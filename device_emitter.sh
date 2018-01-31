#! bin/bash
cd PiPcapCollector
rm ip.txt
hostname -I >> ip.txt
rm mac.txt
cat /sys/class/net/eth0/address >> mac.txt
