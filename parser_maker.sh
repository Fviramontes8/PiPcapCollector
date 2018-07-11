#!/bin/bash

g++ parser5_sun.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser_sun

g++ parser5_mon.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser_mon

g++ parser5_tues.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser_tues

g++ parser5_wed.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser_wed

g++ parser5_thurs.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser5_thurs

g++ parser5_fri.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser5_fri

g++ parser5_sat.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser_sat

