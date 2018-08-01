#!/bin/bash
tshark -i mon0 -I -a duration:60 -b duration:1 -w ./data/sun/data.pcap
