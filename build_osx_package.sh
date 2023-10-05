#!/bin/sh -eu

rm -rf buildtmp
mkdir buildtmp
meson=$(which meson) 
meson setup buildtmp --buildtype=release  --prefix=/tmp/rfidAdmin.app --bindir=Contents/MacOS
ninja -C buildtmp install
rm -rf buildtmp
mkdir -p mnttmp
rm -f working.dmg
gunzip < template.dmg.gz > working.dmg
hdiutil attach working.dmg -noautoopen -quiet -mountpoint mnttmp
rm -rf mnttmp/rfidAdmin.app
mv /tmp/rfidAdmin.app mnttmp
# NOTE: output of hdiutil changes every now and then.
# Verify that this is still working.
hdiutil detach $(hdiutil info|grep "mnttmp"|awk '{print $1}')
rm -rf mnttmp
rm -f rfidAdmin.dmg
hdiutil convert working.dmg -quiet -format UDZO -imagekey zlib-level=9 -o rfidAdmin.dmg
rm -f working.dmg

echo "Done\n"