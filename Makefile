all:
	windres Images/icon.rc -O coff -o Images/icon.res \

	# debug
	g++ \
	main.cpp \
	SDL2-Utilites/SDL2/*.cpp \
	-g \
	-I src/include -I Fonts -I SDL2-Utilites/SDL2/ \
	-L src/lib \
	-o main \
	-l mingw32 -l SDL2main -l SDL2 -l SDL2_image -l SDL2_ttf

	# app
	g++ \
	-mwindows -static-libgcc -static-libstdc++ \
	main.cpp \
	SDL2-Utilites/SDL2/*.cpp \
	-I src/include -I Fonts -I SDL2-Utilites/SDL2 \
	-L src/lib \
	-o Algorithm_Maker  Images/icon.res \
	-l mingw32 -l SDL2main -l SDL2 -l SDL2_image -l SDL2_ttf \