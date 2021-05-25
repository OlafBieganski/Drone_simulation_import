
FLAGS=-Wall -pedantic -std=c++17

__start__:DronSymulacja
	./DronSymulacja

DronSymulacja: obj obj/main.o obj/Dr3D_gnuplot_api.o obj/Prostopadloscian.o obj/Surface.o obj/CoordinateSys.o obj/DrawingInterface.o obj/Hexagon3D.o obj/Drone.o obj/Scene.o obj/Hill.o obj/Plateau_Cuboid.o obj/Plateau.o
	g++ -g ${FLAGS} -o DronSymulacja obj/main.o obj/Prostopadloscian.o obj/Dr3D_gnuplot_api.o obj/Surface.o obj/CoordinateSys.o obj/DrawingInterface.o obj/Hexagon3D.o obj/Drone.o obj/Scene.o obj/Hill.o obj/Plateau_Cuboid.o obj/Plateau.o -lpthread

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/Wektor.hh inc/MacierzObr.hh inc/Prostopadloscian.hh API/source/Dr3D_gnuplot_api.hh inc/Surface.hh inc/Hexagon3D.hh inc/DrawingInterface.hh inc/Scene.hh
	g++ -c ${FLAGS} -o obj/main.o src/main.cpp 

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
	
obj/Hexagon3D.o: src/Hexagon3D.cpp API/source/Dr3D_gnuplot_api.hh inc/CoordinateSys.hh inc/DrawingInterface.hh
	g++ -c ${FLAGS} -o obj/Hexagon3D.o src/Hexagon3D.cpp

obj/Drone.o: src/Drone.cpp inc/CoordinateSys.hh inc/Prostopadloscian.hh inc/Hexagon3D.hh inc/DrawingInterface.hh
	g++ -c ${FLAGS} -o obj/Drone.o src/Drone.cpp

obj/Scene.o: src/Scene.cpp inc/LandscapeInterface.hh inc/Plateau.hh inc/Plateau_Cuboid.hh inc/Hill.hh inc/Drone.hh
	g++ -c ${FLAGS} -o obj/Scene.o src/Scene.cpp

obj/Plateau.o: src/Plateau.cpp inc/CoordinateSys.hh inc/DrawingInterface.hh
	g++ -c ${FLAGS} -o obj/Plateau.o src/Plateau.cpp

obj/Plateau_Cuboid.o: src/Plateau_Cuboid.cpp inc/Prostopadloscian.hh
	g++ -c ${FLAGS} -o obj/Plateau_Cuboid.o src/Plateau_Cuboid.cpp

obj/Hill.o: src/Hill.cpp inc/CoordinateSys.hh inc/DrawingInterface.hh
	g++ -c ${FLAGS} -o obj/Hill.o src/Hill.cpp 

clean:
	rm obj/*.o DronSymulacja
