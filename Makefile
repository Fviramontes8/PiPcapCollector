PLUS = g++
FLAGS = -lboost_filesystem -lboost_system -lpq -ltins
NEW = pcap_parser5.cpp DatabaseConnect.cpp PcapParse.cpp
NEWEXEC = parse5

make:
	$(PLUS) $(NEW) $(FLAGS) -o $(NEWEXEC) 
clean:
	rm $(NEWEXEC)
