liboffset.so: tiled_offsets.o 
	g++ -shared -WL,-soname,liboffset.so -o liboffset.so tiled_offsets.o
tiled_offsets.o: tiled_offsets.cpp 
	g++ -std=c++11 -c -fPIC tiled_offsets.cpp -o tiled_offsets.o
clean:
	rm *.o
	rm *.so