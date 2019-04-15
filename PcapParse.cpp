#include <iostream>
#include <tins/tins.h>
#include <bitset>
#include <stddef.h>
#include <string>				//std::string
#include <vector>				//std::vector
#include <boost/filesystem.hpp> //boost::filesystem::directory_iterator
#include "DatabaseConnect.hpp"	//DatabaseConnect
#include "PcapParse.hpp"

str_vector get_current_files(std::string path) {
	str_vector temp;
	boost::filesystem::directory_iterator end_iter;
	for(boost::filesystem::directory_iterator i(path); i!=end_iter; i++) {
		//std::cout << i->path().extension() << std::endl;
		if(i->path().extension() == ".pcap") {
			temp.push_back(i->path().string());
		}
	}
	if(temp.empty()) {
		std::cout << "Waiting...\n";
		usleep(1000000);
		get_current_files(path);
	}
	else {
		return temp;
	}
}

void rm_current_files(str_vector data) {
	for(auto& d: data) {
		//std::cout << d << std::endl;
		if(remove(d.c_str()) != 0) {
			perror("Error deleting file!\n");
		}
		else {
			std::cout << "Removed: " << d << std::endl;
		}
	}
}

mac_info get_mac_info(const Tins::PDU &pkt_pdu, Tins::Packet input_pkt, mac_info input_mac) {
	if(input_pkt.pdu()->find_pdu<Tins::Dot11Data>()) {
		const Tins::Dot11Data &d11d = pkt_pdu.rfind_pdu<Tins::Dot11Data>();
		input_mac.src = d11d.addr2().to_string();
		input_mac.dst = d11d.addr1().to_string();
	}
	else if(input_pkt.pdu()->find_pdu<Tins::Dot11ManagementFrame>()) {
		const Tins::Dot11ManagementFrame & d11m = pkt_pdu.rfind_pdu<Tins::Dot11ManagementFrame>();
		input_mac.src = d11m.addr2().to_string();
		input_mac.dst = d11m.addr1().to_string();
	}
	else if (input_pkt.pdu()->find_pdu<Tins::Dot11>()) {
		const Tins::Dot11 &d11 = pkt_pdu.rfind_pdu<Tins::Dot11>();
		input_mac.src = "None";
		input_mac.dst = d11.addr1().to_string();
	}
	else {
		input_mac.src = "None";
		input_mac.dst = "None";
	}
	return input_mac;
}

radio_info get_radio_info(const Tins::PDU &pkt_pdu, Tins::Packet input_pkt, radio_info input_radio) {
	if(input_pkt.pdu()->find_pdu<Tins::RadioTap>()) {
		const Tins::RadioTap &rTap = pkt_pdu.rfind_pdu<Tins::RadioTap>();

		if( (rTap.present() & Tins::RadioTap::CHANNEL) != 0) {
			input_radio.cFlags = rTap.channel_type();
		}
		
		if( (rTap.present() & Tins::RadioTap::RATE) != 0) {
			input_radio.dataRate = rTap.rate() / 2.0;
		}

		if( (rTap.present() & Tins::RadioTap::DBM_SIGNAL) != 0) {
			input_radio.signal_strength = rTap.dbm_signal();
		}
	}
	else {
		input_radio.cFlags = 0;
		input_radio.signal_strength = 0;
		input_radio.dataRate = 0.0;
	}
	return input_radio;
}

void update_nou(str_vector *in_mac_list, db_data *pkt_stats, mac_info in_mac) {
	if( (in_mac_list->empty()) & (in_mac.src != "None")) {
		pkt_stats->NumUsers = 2;
		in_mac_list->push_back(in_mac.src);
		in_mac_list->push_back(in_mac.dst);
	}
	else if( (in_mac_list->empty()) & (in_mac.src == "None")) {
		pkt_stats->NumUsers = 1;
		in_mac_list->push_back(in_mac.dst);
	}
	else if(in_mac.src == "None") {
		;
	}
	else {
		if(std::find(in_mac_list->begin(), in_mac_list->end(), in_mac.src) != in_mac_list->end()) {
			;
		}
		else {
			pkt_stats->NumUsers += 1;
			in_mac_list->push_back(in_mac.src);
		}
		if(std::find(in_mac_list->begin(), in_mac_list->end(), in_mac.dst) != in_mac_list->end()) {
			;
		}
		else {
			pkt_stats->NumUsers += 1;
			in_mac_list->push_back(in_mac.dst);
		}
	}
}
