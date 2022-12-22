all:
	g++ -I src/include -I Images -I Fonts -I src/utilities -L src/lib -o main main.cpp -l mingw32 -l SDL2main -l SDL2 -l SDL2_image -l SDL2_ttf