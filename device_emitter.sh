#!/bin/bash
sleep 120s
cd PiPcapCollector
if [ -f /root/PiPcapCollector/ip.txt ];then
#cd PiPcapCollector
rm ip.txt
fi
hostname -I >> ip.txt
if [ -f /root/PiPcapCollector/mac.txt ];then
#cd PiPcapCollector
rm mac.txt
fi
cat /sys/class/net/eth0/address >> mac.txt

python device_emitter.py
