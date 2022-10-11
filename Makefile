main:
	g++ -c main-1-1.cpp -I"C:\Users\brodi\OneDrive\Documents\SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit\SFML-2.5.1\include"
	g++ main-1-1.o menu.cpp optionss.cpp Player.cpp single.cpp group.cpp -o main -L"C:\Users\brodi\OneDrive\Documents\SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
	./main

side:
	g++ main-1-1.cpp menu.cpp optionss.cpp Player.cpp single.cpp group.cpp
	./a.exe