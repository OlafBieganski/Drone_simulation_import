
FLAGS=-Wall -pedantic

__start__:rotacje3D
	./rotacje3D

rotacje3D: obj obj/main.o obj/Dr3D_gnuplot_api.o obj/Prostopadloscian.o
	g++ ${FLAGS} -o rotacje3D obj/main.o obj/Prostopadloscian.o obj/Dr3D_gnuplot_api.o -lpthread

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/Wektor.hh inc/MacierzObr.hh inc/Prostopadloscian.hh API/source/Dr3D_gnuplot_api.hh
	g++ -c ${FLAGS} -o obj/main.o src/main.cpp 

obj/Dr3D_gnuplot_api.o: API/source/Dr3D_gnuplot_api.cpp API/source/Dr3D_gnuplot_api.hh
	g++ -c ${FLAGS} -o obj/Dr3D_gnuplot_api.o API/source/Dr3D_gnuplot_api.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp API/source/Dr3D_gnuplot_api.hh inc/Wektor.hh inc/MacierzObr.hh
	g++ -c ${FLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

clean:
	rm obj/*.o rotacje3D
