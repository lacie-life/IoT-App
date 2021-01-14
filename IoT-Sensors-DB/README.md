# Install mongoc driver (Ubuntu 20.04 version)

## Prerequisites for libmongoc¶

sudo apt-get install cmake libssl-dev libsasl2-dev

## Preparing a build from a release tarball

wget https://github.com/mongodb/mongo-c-driver/releases/download/1.17.0/mongo-c-driver-1.17.0.tar.gz

tar xzf mongo-c-driver-1.17.0.tar.gz

cd mongo-c-driver-1.17.0

mkdir cmake-build

cd cmake-build

cmake -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF ..

## Executing a build
cmake --build .

sudo cmake --build . --target install

# Install mongcxx driver (Ubuntu 20.04 version)

curl -OL https://github.com/mongodb/mongo-cxx-driver/releases/download/r3.6.2/mongo-cxx-driver-r3.6.2.tar.gz

tar -xzf mongo-cxx-driver-r3.6.2.tar.gz

cd mongo-cxx-driver-r3.6.2/build

cmake ..                                \
    -DCMAKE_BUILD_TYPE=Release          \
    -DCMAKE_INSTALL_PREFIX=/usr/local
    
# Only for MNMLSTC polyfill
sudo cmake --build . --target EP_mnmlstc_core

cmake --build .

sudo cmake --build . --target install

## Uninstall (Option)

sudo cmake --build . --target uninstall

or 

sudo /opt/mongo-cxx-driver/share/mongo-cxx-driver/uninstall.sh
