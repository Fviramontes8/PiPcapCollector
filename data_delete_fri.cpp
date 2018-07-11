#include <iostream>
#include <string>
#include "DatabaseConnect.hpp" //From local file to talk to a postgresql database

int main(int argc, char* argv[]) {
	
	std::string table_name = "fri";
	
	//Opening connection with database
	DatabaseConnect db("postgres", "129.24.26.110", "postgres", "Cerculsihr4T");
	db.connect();
	
	db.deleteTableContent(table_name);
	
	db.disconnect();
	return 0;
}
