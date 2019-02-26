#!/bin/bash
sleep 100s
cd ~/PiPcapCollector
pgrep parser >> status.txt

python device_check.py
