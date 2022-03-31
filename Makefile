CC=gcc
CFLAGS=-Wall -Wpedantic -Wextra -std=c99

default:
	make all

clean:
	rm -f *.o sport_events sport_athlete sport_db

#-o outputs a gcc and -c compiles without linking to other files inside of program

sport: 	sport_db.o sport_athlete.o sport_events.o
	gcc -o sport sport_db.o sport_athlete.o sport_events.o

sport_db.o:	sport_db.c sport_db.h 
		gcc -c sport_db.c 
		

sport_athlete.o:	sport_athlete.c sport_athlete.h
		gcc -c sport_athlete.c

sport_events.o:	sport_events.c sport_events.h
		gcc -c sport_events.c