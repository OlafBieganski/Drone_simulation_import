#!/bin/bash

cd obj

g++ -c -Wall -pedantic ../Prostopadloscian.cpp

g++ -c -Wall -pedantic ../trialMain.cpp ../Wektor.hh ../MacierzObr.hh

g++ -c -Wall -pedantic ../../API/source/Dr3D_gnuplot_api.cpp

cd ..

g++ obj/trialMain.o obj/Prostopadloscian.o obj/Dr3D_gnuplot_api.o -lpthread

echo "Koniec kompilacji"