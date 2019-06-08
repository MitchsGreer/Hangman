#This is the Hangman Makefile, executing this file will create Hangman while storing the object files
#in a seperate folder. 

#Declaring some useful information.
TARGET = Hangman #The desired name of the executable.
CC = gcc #The compiler of choice. 
CFLAGS = -c -Wall #Cflags for compilation, -Wall brings to light most c warnings.
NEW_DIR = object_files/ #Destination for the object files.


#Sources object files for the executable.
SOURCE = play.o\
		 menu.o\
		 input.o\
		 scoreboard.o\
		 stats.o\
		 time.o\
		 word.o\
		 main.o

#Resource files for the the executable.
RESOURCE = ../Resources/resource.h\
		   ../Resources/play.h\
		   ../Resources/input.h\
		   ../Resources/menu.h\
		   ../Resources/scoreboard.h\
		   ../Resources/stats.h\
		   ../Resources/time.h\
		   ../Resources/word.h

#Rule for how the executable should be compiled.
$(TARGET) : $(SOURCE) $(RESOURCE)
	$(CC) $(SOURCE) -o $(TARGET)

#Below are the rules used to create the object files from the c source files.
input.o : ../src/input.c ../Resources/resource.h
	$(CC) $(CFLAGS) ../src/input.c -o input.o

main.o : ../src/main.c ../Resources/resource.h
	$(CC) $(CFLAGS) ../src/main.c -o main.o

menu.o : ../src/menu.c ../Resources/menu.h
	$(CC) $(CFLAGS) ../src/menu.c -o menu.o

play.o : ../src/play.c ../Resources/play.h ../Resources/play.h
	$(CC) $(CFLAGS) ../src/play.c -o play.o

scoreboard.o : ../src/scoreboard.c ../Resources/scoreboard.h
	$(CC) $(CFLAGS) ../src/scoreboard.c -o scoreboard.o

stats.o : ../src/stats.c ../Resources/stats.h
	$(CC) $(CFLAGS) ../src/stats.c -o stats.o

time.o : ../src/time.c ../Resources/time.h
	$(CC) $(CFLAGS) ../src/time.c -o time.o

word.o : ../src/word.c ../Resources/word.h
	$(CC) $(CFLAGS) ../src/word.c -o word.o

#Stops this Makefile from interfering with files named clean
.PHONY : clean

#Defines how the "$make clean" bash command works
clean : 
	rm $(SOURCE) $(TARGET)