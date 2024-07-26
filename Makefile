main:
	cmake --build build --target main

app:
	windres Images/icon.rc -O coff -o Images/icon.res
	cmake --build build
