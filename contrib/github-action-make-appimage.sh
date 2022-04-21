#!/bin/bash

source /opt/qt515/bin/qt515-env.sh

LD_LIBRARY_PATH=$(readlink -f ../qwt/lib):$LD_LIBRARY_PATH

echo `readlink -f ../qwt/lib`

echo `ldd build/dist/usr/bin/strata`

cd build

# Create the AppImage
wget -c "https://github.com/probonopd/linuxdeployqt/releases/download/continuous/linuxdeployqt-continuous-x86_64.AppImage"
chmod a+x linuxdeployqt-continuous-x86_64.AppImage

./linuxdeployqt-continuous-x86_64.AppImage dist/usr/share/applications/strata.desktop -appimage -no-translations

# Rename and upload the AppImage
VERSION=$(sed -ne 's/.*VERSION "\([0-9.]\+\)".*/\1/p' ../CMakeLists.txt)
GITHASH=$(git rev-parse --short HEAD)
IMAGE=Strata-v$VERSION-$GITHASH-x86_64.AppImage

mv Strata-*.AppImage $IMAGE
