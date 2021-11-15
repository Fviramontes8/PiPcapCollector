GPP = g++ -std=c++17
FLAGS = -lboost_filesystem -lboost_system -lpq -ltins
EXEC = parse5

all: $(EXEC)

$(EXEC): pcap_parser5.o DatabaseConnect.o PcapParse.o
	$(GPP) $^ $(FLAGS) -o $@ 

pcap_parser5.o: pcap_parser5.cpp DatabaseConnect.hpp PcapParse.hpp
	$(GPP) $< $(FLAGS) -o $@

DatabaseConnect.o: DatabaseConnect.cpp DatabaseConnect.hpp
	$(GPP) $< $(FLAGS) -o $@

PcapParse.o: PcapParse.cpp PcapParse.hpp DatabaseConnect.hpp
	$(GPP) $< $(FLAGS) -o $@

clean:
	-rm *.o $(EXEC)
