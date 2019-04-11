sampleobjects = buffer_manager.o file_manager.o insertnew.o
sampleobjects1=buffer_manager.o file_manager.o printrun.o

insertnew : $(sampleobjects)
	     g++ -std=c++11 -o insertnew $(sampleobjects)
printrun : $(sampleobjects1)
	     g++ -std=c++11 -o  printrun $(sampleobjects1)

insertnew.o : insertnew.cpp
	g++ -std=c++11 -c insertnew.cpp

printrun.o : printrun.cpp
	g++ -std=c++11 -c printrun.cpp

buffer_manager.o : buffer_manager.cpp
	g++ -std=c++11 -c buffer_manager.cpp

file_manager.o : file_manager.cpp
	g++ -std=c++11 -c file_manager.cpp

clean :
	rm -f *.o
	rm -f insertnews
