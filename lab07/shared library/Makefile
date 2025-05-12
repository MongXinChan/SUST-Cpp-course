# makefile with dynamic library

.PHONY: libd testlibd clean

libd: libfunction.so
libfunction.so: mymath.cpp
	g++ -shared -fPIC -o libfunction.so mymath.cpp

testlibd: main
main: main.cpp libfunction.so
	g++ main.cpp -L. -lfunction -Wl,-rpath=. -o main

clean:
	rm -f *.o *.so main