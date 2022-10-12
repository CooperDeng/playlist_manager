
output: playlistdriver.o playlist.o
	g++ playlistdriver.o playlist.o -o playlistdriver

playlistdriver.o: playlistdriver.cpp
	g++ -c playlistdriver.cpp

playlist.o: playlist.cpp playlist.h
	g++ -c playlist.cpp

clean:
	rm *.o playlistdriver
