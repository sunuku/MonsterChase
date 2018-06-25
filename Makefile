# _*_ MakeFile _*_


#target: dependencies
#	action



myprogram: sdl_paint.o main.o monsterai.o world.o
	gcc main.o sdl_paint.o world.o monsterai.o -o myprogram -lSDL2 -lSDL2_ttf



sdl_paint.o: sdl_paint.c
	gcc -c sdl_paint.c

main1.o: main.c
	gcc -c main.c




monsterai.o: monsterai.c
	gcc -c monsterai.c





world.o: world.c
	gcc -c world.c


