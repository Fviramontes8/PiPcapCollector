#!/bin/bash

echo "Compiling parsers..."
g++ parser5_sun.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser_sun

g++ parser5_mon.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser_mon

g++ parser5_tues.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser_tues

g++ parser5_wed.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser_wed

g++ parser5_thurs.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser5_thurs

g++ parser5_fri.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser5_fri

g++ parser5_sat.cpp DatabaseConnect.cpp -ltins -lboost_system -lboost_filesystem -lpq -o parser_sat

echo "Parsers are ready!"
if [ ! -d ./data ] ; then
echo "No data directory, making one now..."
mkdir data
else
echo "data directory exists..."
fi

cd data

echo "Changing directory to data..."
echo "Creating day directories if they do not exist"
if [ ! -d ./sun ] ; then
mkdir sun
fi

if [ ! -d ./mon ] ; then
mkdir mon
fi

if [ ! -d ./tues ] ; then
mkdir tues
fi

if [ ! -d ./wed ] ; then
mkdir wed
fi

if [ ! -d ./thurs ] ; then
mkdir thurs
fi

if [ ! -d ./fri ] ; then
mkdir fri
fi

if [ ! -d ./sat ] ; then
mkdir sat
fi
