syedWasayuddinA1: syedWasayuddinA1.o syedWasayuddinA1Main.o
	gcc syedWasayuddinA1.o syedWasayuddinA1Main.c -o syedWasayuddinA1 -lm
syedWasayuddinA1.o: syedWasayuddinA1.c givenA1.h
	gcc -Wall -std=c99 -c syedWasayuddinA1.c
syedWasayuddinA1Main.o: syedWasayuddinA1Main.c givenA1.h
	gcc -Wall -std=c99 -c syedWasayuddinA1Main.c
clean:
	rm *.o syedWasayuddinA1