
FLAGS=-Wall -pedantic

__start__:DronSymulacja
	./DronSymulacja

DronSymulacja: obj obj/trial.o obj/Dr3D_gnuplot_api.o obj/Prostopadloscian.o obj/Surface.o obj/CoordinateSys.o obj/DrawingInterface.o
	g++ ${FLAGS} -o DronSymulacja obj/trial.o obj/Prostopadloscian.o obj/Dr3D_gnuplot_api.o obj/Surface.o obj/CoordinateSys.o obj/DrawingInterface.o -lpthread

obj:
	mkdir obj

obj/trial.o: src/trial.cpp inc/Wektor.hh inc/MacierzObr.hh inc/Prostopadloscian.hh API/source/Dr3D_gnuplot_api.hh inc/Surface.hh
	g++ -c ${FLAGS} -o obj/trial.o src/trial.cpp 

obj/Dr3D_gnuplot_api.o: API/source/Dr3D_gnuplot_api.cpp API/source/Dr3D_gnuplot_api.hh
	g++ -c ${FLAGS} -o obj/Dr3D_gnuplot_api.o API/source/Dr3D_gnuplot_api.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp API/source/Dr3D_gnuplot_api.hh inc/Wektor.hh inc/MacierzObr.hh inc/CoordinateSys.hh inc/DrawingInterface.hh
	g++ -c ${FLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Surface.o: src/Surface.cpp API/source/Dr3D_gnuplot_api.hh
	g++ -c ${FLAGS} -o obj/Surface.o src/Surface.cpp

obj/CoordinateSys.o: src/CoordinateSys.cpp inc/Wektor.hh inc/MacierzObr.hh
	g++ -c ${FLAGS} -o obj/CoordinateSys.o src/CoordinateSys.cpp

obj/DrawingInterface.o: src/DrawingInterface.cpp API/source/Dr3D_gnuplot_api.hh
	g++ -c ${FLAGS} -o obj/DrawingInterface.o src/DrawingInterface.cpp
	
clean:
	rm obj/*.o DronSymulacja
