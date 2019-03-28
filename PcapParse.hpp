#include <iostream>
#include <tins/tins.h>
#include <bitset>
#include <stddef.h>
#include <string>				//std::string
#include <vector>				//std::vector
#include <boost/filesystem.hpp> //boost::filesystem::directory_iterator

//For pushing statistical features to the database
typedef struct db_Data {
	int TimeStamp;
	int NumUsers;
	int NumBits;
	int NumPkts;
	int AvgSigS;
	int AvgDataRate;
	int BitsA;
	int BitsN;
} db_data;

//Temporary placeholders for source and destination mac addresses
typedef struct mac_src_dst {
	std::string src;
	std::string dst;
} mac_info;

//Temporary placeholder for wireless radio statistics
typedef struct radioInfo {
	int cFlags;
	int signal_strength;
	float dataRate;
} radio_info;

typedef std::vector<std::string> str_vector;

//Function prototypes
str_vector get_current_files(std::string path);

mac_info get_mac_info(const Tins::PDU &pkt_pdu, Tins::Packet input_pkt, mac_info input_mac);

radio_info get_radio_info(const Tins::PDU &pkt_pdu, Tins::Packet input_pkt, radio_info input_radio);

void update_nou(str_vector *in_mac_list, db_data *pkt_stats, mac_info in_mac);
