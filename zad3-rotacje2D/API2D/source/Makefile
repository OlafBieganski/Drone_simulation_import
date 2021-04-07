CPPFLAGS= -c -g -Wall -pedantic -std=c++17 

__start__: example.out
	./example.out

example.out: Dr2D_gnuplot_api.o example.o
	g++ -o example.out example.o Dr2D_gnuplot_api.o -lpthread

example.o: example.cpp Dr2D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o example.o example.cpp

Dr3D_gnuplot_api.o: Dr2D_gnuplot_api.cpp Dr2D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o Dr2D_gnuplot_api.o Dr2D_gnuplot_api.cpp

Dr3D_gnuplot_api.hh: Draw2D_api_interface.hh
	touch Dr2D_gnuplot_api.hh

clear:
	rm example.out example.o Dr2D_gnuplot_api.o
