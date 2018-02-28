# -*- coding: utf-8 -*-
"""
Created on Wed Jan 24 15:17:49 2018

@author: fviramontes8
"""

import DatabaseConnect as dc

def device_upload(ip_addr, mac_addr):
    db.connect()
    key = db.getNextKey("ip")
    key += 1
    #print("Next key: " + str(key))
    pi_upload = [key, mac_addr, ip_addr]
    db.writeDeviceData("ip", pi_upload)
    db.disconnect()

def device_delete(mac_addr, table_name):
    db.connect()
    db.deleteData(mac_addr, table_name)
    db.disconnect()


db = dc.DatabaseConnect()
db.connect()
table_contents = db.readTable("ip")
db.disconnect()

#print(table_contents[0][0])
pi_details = {}
for i in table_contents:
    pi_details[i[0]] = [i[1], i[2]]
#print(pi_details)

text_object = open("ip.txt", "r")
#print(text_object.read())
ip_address = text_object.read()
text_object.close()
ip_address = ip_address.strip("\n")
ip_address = ip_address.strip()
#print("This computer's IP address: '" + ip_address+"'")

text_object = open("mac.txt", "r")
mac_address = text_object.read()
text_object.close()
mac_address = mac_address.strip("\n")
#print("This computer's MAC address: '" + mac_address+"'")

text_object = open("date.txt", "r")
date = text_object.read()
text_object.close()
date=date.strip("\n")
#print("'"+date+"'")

for pi_iterator in range(len(pi_details)):
    database_ip = pi_details[pi_iterator+1][1]
    #print("Database: " + database_ip)
    if(database_ip == ip_address):
        ip_check = 0
        #print("There is an IP address, here is the key: " +str(pi_iterator+1))
    else:
        #print("There is no match for IP!")
        ip_check = 1
    #print("ip_check: " + str(ip_check))

mac_check = 0

if(ip_check):
    for pi_iterator in range(len(pi_details)):
        database_mac = pi_details[pi_iterator+1][0]
        #print("Database: " + database_mac)
        if(database_mac == mac_address):
            device_delete(mac_address, "ip")
            mac_check = 1
            #print("There is a MAC address, here is the key: " +str(pi_iterator+1))
            #db.deleteIPData(pi_iterator+1)
        else:
            mac_check = 1
            #print("There is no match for MAC!")
        #print("mac_check: " + str(mac_check))

if(mac_check):
    #print("This device is not on the database!")
    device_upload(ip_address, mac_address)

print(date)

#import subprocess
if date == 0:
    print("Its sunday!")
    #subprocess.call(["./parser_sun"])
elif date == 1:
    print("Its monday!")
    #subprocess.call(["./parser_mon"])
elif date == 2:
    print("Its tuesday!")
    #subprocess.call(["./parser_tues"])
elif date == 3:
    print("Its wednesday!")
    #subprocess.call(["./parser_wed"])
elif date == 4:
    print("Its thursday!")
    #subprocess.call(["./parser_thurs"])
elif date == 5:
    print("Its friday!")
    #subprocess.call(["./parser_fri"])
elif date == 6:
    print("Its saturday!")
    #subprocess.call(["./parser_sat"])
elif date == 7:
    print("Its sunday?")
    #subprocess.call(["./parser_sun"])
else:
    pass
#subprocess.call(["./parser5"])
