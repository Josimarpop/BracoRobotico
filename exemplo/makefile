main : main.o
g++ -o main main.o -L C:\Program Files (x86)\mingw-w64\i686-4.9.0-posix-dwarf-rt_v3-rev2\mingw32\include -lstdc++

main.o : main.cpp
g++ -ggdb -c main.cpp

all :
${MAKE} main

clean :
-del main.o