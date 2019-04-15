#include <iostream>
#include <tins/tins.h>
#include <bitset>
#include <stddef.h>
#include <string>				//std::string
#include <vector>				//std::vector
#include <boost/filesystem.hpp> //boost::filesystem::directory_iterator
#include "DatabaseConnect.hpp"	//DatabaseConnect
#include "PcapParse.hpp"
#include <algorithm>

void help(char *prog_name) {
	std::cout << "Usage:\n\t" << prog_name << " database_table_name folder_to_store_data" << std::endl;
	std::cout << "Examples:\n\t" << prog_name << " 5pi_mon3 mon" << std::endl;
	std::cout << "\t" << prog_name << " 5pi_sat4 sat" << std::endl;
}

int main(int argc, char *argv[]) {
	if(argc != 3) {
		help(argv[0]);
		return -1;
	}
	DatabaseConnect db;
	std::string table_name = argv[1];
	std::cout << table_name << std::endl;

	//Custom data structures (See PcapParse.hpp)
	str_vector current_files;
	str_vector list_of_mac;
	db_data pkt_stats;
	mac_info mac;
	radio_info radio;

	db.connect();
	int next_key = db.getNextKey(table_name);
	//db.db_test();
	db.disconnect();

	std::string data_path = argv[2];
	//std::cout << "The next key is: " << next_key << std::endl;

	/*****************************************************/
	//const std::string path("/home/PiPcapCollector/data/"+data_path);
	const std::string path("/home/franku/PiPcapCollector/pcap_files/");
	/*****************************************************/
	std::cout << path << std::endl;

	current_files = get_current_files(path);

	int temp=0;
	while(1) {
		for(auto& file_iter: current_files) {
			Tins::FileSniffer sniffer(file_iter);
			std::cout << "Analyzing: " << file_iter << std::endl;
			pkt_stats = {0, 0, 0, 0, 0, 0, 0, 0};
			Tins::Timestamp tstamp;
			while(Tins::Packet pkt = sniffer.next_packet()) {
				const Tins::PDU &pdu = *pkt.pdu();

				tstamp = pkt.timestamp();
				mac = get_mac_info(pdu, pkt, mac);
				//std::cout << mac.src << "->" << mac.dst << std::endl;

				radio = get_radio_info(pdu, pkt, radio);
				//std::cout << radio.cFlags <<", "<< radio.signal_strength;
				//std::cout <<", "<< radio.dataRate << std::endl;

				//This updates the Number of Users statistic
				update_nou(&list_of_mac, &pkt_stats, mac);
				//std::cout << "Number of users: " << pkt_stats.NumUsers << std::endl;
				pkt_stats.NumBits += pdu.size();
				//std::cout << "Bits: " << pkt_stats.NumBits << std::endl;
				
				pkt_stats.NumPkts += 1;
				//std::cout << "# of pkts: " << pkt_stats.NumPkts << std::endl;

				pkt_stats.AvgSigS += radio.signal_strength;
				//std::cout << "Signal strength: " << pkt_stats.AvgSigS << std::endl;

				pkt_stats.AvgDataRate += radio.dataRate;
				//std::cout << "Data rate: " << pkt_stats.AvgDataRate << std::endl;

				if(pkt_stats.AvgDataRate > 0) {
					pkt_stats.BitsA += pdu.size();
				}
				else {
					pkt_stats.BitsN += pdu.size();
				}
				//std::cout << "802.11a: " << pkt_stats.BitsA << " 802.11n: " << pkt_stats.BitsN << std::endl;

			//	usleep(500);
			}
			pkt_stats.TimeStamp = tstamp.seconds();
			pkt_stats.AvgSigS /= pkt_stats.NumPkts;
			pkt_stats.AvgDataRate /= pkt_stats.NumPkts;

			//std::cout << "SigS: " << pkt_stats.AvgSigS << " DR: " << pkt_stats.AvgDataRate << std::endl;
			//usleep(50000);
			//std::cout << "Timestamp: "<< pkt_stats.TimeStamp << std::endl;
			str_vector upload = {std::to_string(pkt_stats.TimeStamp), std::to_string(pkt_stats.NumUsers), std::to_string(pkt_stats.NumBits), std::to_string(pkt_stats.NumPkts), std::to_string(pkt_stats.AvgSigS), std::to_string(pkt_stats.AvgDataRate), std::to_string(pkt_stats.BitsA), std::to_string(pkt_stats.BitsN)};

			/*
			db.connect();
			db.deleteTableContent(table_name);
			next_key = db.getNextKey(table_name);
			db.writeData5GHz(table_name, std::to_string(next_key), upload);
			db.disconnect();
			std::cout << "Next key: " << next_key << std::endl;
			*/
			usleep(500);
		}
		rm_current_files(current_files);
		//current_files = get_current_files(path);
	}

	return 0;
}
