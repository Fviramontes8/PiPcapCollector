#!/bin/bash

g++ parser5_sun.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser_sun
g++ data_delete_sun.cpp DatabaseConnect.cpp -lpq -o data_delete_sun

g++ parser5_mon.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser_mon
g++ data_delete_mon.cpp DatabaseConnect.cpp -lpq -o data_delete_mon

g++ parser5_tues.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser_tues
g++ data_delete_tues.cpp DatabaseConnect.cpp -lpq -o data_delete_tues

g++ parser5_wed.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser_wed
g++ data_delete_wed.cpp DatabaseConnect.cpp -lpq -o data_delete_wed

g++ parser5_thurs.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser5_thurs
g++ data_delete_thurs.cpp DatabaseConnect.cpp -lpq -o data_delete_thurs

g++ parser5_fri.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser5_fri
g++ data_delete_fri.cpp DatabaseConnect.cpp -lpq -o data_delete_fri

g++ parser5_sat.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser_sat
g++ data_delete_sat.cpp DatabaseConnect.cpp -lpq -o data_delete_sat
