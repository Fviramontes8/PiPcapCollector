#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Tue Feb 27 16:13:03 2018

@author: Francisco Viramontes
"""

text_object = open("status.txt", "r")
#print(text_object.read())
status_num = text_object.read()
text_object.close()
import os
status_size = os.stat("status.txt").st_size
if status_size > 0:
    status_num = status_num.strip("\n")
    #print("'"+status_num+"'")
else:
    text_ob = open("date.txt", "r")
    date = text_ob.read()
    text_ob.close()
    date=date.strip("\n")
    import subprocess
    if date == 0:
        #print("Its sunday!")
        subprocess.call(["./parser_sun"])
    elif date == 1:
        #print("Its monday!")
        subprocess.call(["./parser_mon"])
    elif date == 2:
        #print("Its tuesday!")
        subprocess.call(["./parser_tues"])
    elif date == 3:
        #print("Its wednesday!")
        subprocess.call(["./parser_wed"])
    elif date == 4:
        #print("Its thursday!")
        subprocess.call(["./parser_thurs"])
    elif date == 5:
        #print("Its friday!")
        subprocess.call(["./parser_fri"])
    elif date == 6:
        #print("Its saturday!")
        subprocess.call(["./parser_sat"])
    elif date == 7:
        #print("Its sunday?")
        subprocess.call(["./parser_sun"])
    else:
        pass
