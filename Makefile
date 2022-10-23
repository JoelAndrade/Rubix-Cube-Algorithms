all:
	windres Images/icon.rc -O coff -o Images/icon.res
	g++ -g -I src/include -I fonts -I utilities/SDL2 -L src/lib -o main main.cpp utilities/SDL2/*.cpp -l mingw32 -l SDL2main -l SDL2 -l SDL2_image -l SDL2_ttf
	g++ -mwindows -I src/include -I fonts -I utilities/SDL2 -L src/lib -static-libgcc -static-libstdc++ -o Algorithm_Maker utilities/SDL2/*.cpp Images/icon.res main.cpp -l mingw32 -l SDL2main -l SDL2 -l SDL2_image -l SDL2_ttf