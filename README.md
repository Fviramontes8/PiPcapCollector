# PiPcapCollector
Pcap data collection and autonomy code for pi.
The bash shell script take the IP and MAC address of the host device and writes it into two text files: ip.txt & mac.txt. If the files exist in the directory the bash shell script will delete the file before writing a new one. It then launches the Python file of the same name.
The Python programs reads the text files and uploads them to a postgreSQL database.
