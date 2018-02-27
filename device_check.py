#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Tue Feb 27 16:13:03 2018

@author: root
"""

text_object = open("status.txt", "r")
#print(text_object.read())
status_num = text_object.read()
text_object.close()
import os
status_size = os.stat("status.txt").st_size
if status_size > 0:
    status_num = status_num.strip("\n")
    print("'"+status_num+"'")
else:
    print("sad bois")