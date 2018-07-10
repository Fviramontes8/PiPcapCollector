# PiPcapCollector
Pcap data collection and autonomy code for pi.
device_emitter.sh takes the IP and MAC address of the host device and writes it into two text files: ip.txt & mac.txt. If the files exist in the directory the bash shell script will delete the file before writing a new one. It then launches the Python file of the same name.
The Python program device_emitter.py reads the text files and uploads them to a postgreSQL database.

Remember to compile DatabaseConnect.cpp with data_delete.cpp and parser5.cppas both those cpp files need DatabaseConnect.cpp
It is recommended to compile parser5.cpp and make seven programs, each for the day of the week.
