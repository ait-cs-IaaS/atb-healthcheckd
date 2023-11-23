#!/bin/bash

export DEBFULLNAME="Roy Mandoline"
export DEBEMAIL="roy@aecid-testbed.com"

INPUT_DIR="/app"
OUTPUT_DIR="/build"

if [ $# -ne 2 ]
then
	echo "usage: $0 <progname> <version>"
	exit 1
fi

APPNAME=$1
VERSION=$2


if [ "$EUID" -ne 0 ]
then
	echo "Please run as root"
	exit 1
fi

cp -r $INPUT_DIR $OUTPUT_DIR/$APPNAME-$VERSION
cd $OUTPUT_DIR/$APPNAME-$VERSION
apt update
apt install -y dh-make devscripts build-essential make
dh_make -s -y --createorig
debuild -us -uc


exit 0
