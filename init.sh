#!/bin/bash

#Installing necessary packages
#sudo apt install libtins-dev libpcap-dev libssl-dev libboost-all-dev libpq-dev

echo "Parser is ready!"
if [ ! -d ./data ] ; then
echo "No data directory, making one now..."
mkdir data
else
echo "data directory exists..."
fi

cd data

echo "Changing directory to data..."
if [ ! -d ./sun ] ; then
echo "Creating data directory sun"
mkdir sun
fi

if [ ! -d ./mon ] ; then
echo "Creating data directory mon"
mkdir mon
fi

if [ ! -d ./tues ] ; then
echo "Creating data directory tues"
mkdir tues
fi

if [ ! -d ./wed ] ; then
echo "Creating data directory wed"
mkdir wed
fi

if [ ! -d ./thurs ] ; then
echo "Creating data directory thurs"
mkdir thurs
fi

if [ ! -d ./fri ] ; then
echo "Creating data directory fri"
mkdir fri
fi

if [ ! -d ./sat ] ; then
echo "Creating data directory sat"
mkdir sat
fi
