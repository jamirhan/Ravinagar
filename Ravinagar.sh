#!/bin/bash
sudo apt-get install git
sudo apt-get install qt5-default
sudo apt-get install libboost-all-dev
sudo apt-get install cmake
git clone https://github.com/jamirhan/Ravinagar.git
# shellcheck disable=SC2164
cd Ravinagar
git checkout dev_2
mkdir build
# shellcheck disable=SC2164
cd build
cmake ..
make
cd ./..
# shellcheck disable=SC2164
cd bin
./Client
