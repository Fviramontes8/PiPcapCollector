#!/bin/bash
#PATH='/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin'

#sleep 90s
pkill NetworkManager
ifconfig wlan0 down
iw dev wlan0 del
iw phy phy0 interface add mon0 type monitor
iw dev mon0 set channel 161
ifconfig mon0 up
service NetworkManager start
service NetworkManager restart
