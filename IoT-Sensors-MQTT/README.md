# Install qtmqtt module
- git clone git://code.qt.io/qt/qtmqtt.git
- git checkout v5.15.2
- sudo apt-get install qtbase5-private-dev
- open Qt Creator and build (desktop compiler)
- copy .../build-qtmqtt-.../include/QtMQTT to .../Qt/{Qt version}/gcc_64/include
- copy .../build-qtmqtt-.../lib/cmake/Qt5Mqtt to .../Qt/{Qt version}/gcc_64/lib/cmake
- copy files .ls .prl .so .. to ../Qt/{Qt version}/gcc_64/lib
- copy .../build-qtmqtt-.../lib/pkgconfig to .../Qt/{Qt version}/gcc_64/lib/pkgconfig

