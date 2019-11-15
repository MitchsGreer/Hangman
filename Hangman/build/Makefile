#This is the Hangman Makefile, executing this file will create Hangman while storing the object files
#in a seperate folder. 

#Declaring some useful information.
TARGET = Hangman #The desired name of the executable.
CC = gcc #The compiler of choice. 
CFLAGS = -c -Wall #Cflags for compilation, -Wall brings to light most c warnings.
OBJ_DIR = $(BUILD_DIR)/../obj#Destination for the object files.
SRC_DIR = $(BUILD_DIR)/../src
BUILD_DIR = $(CURDIR)

#Sources object files for the executable.
SOURCE = play.o\
		 menu.o\
		 input.o\
		 scoreboard.o\
		 stats.o\
		 time.o\
		 word.o\
		 main.o

LOCATION = $(OBJ_DIR)/play.o\
	 	   $(OBJ_DIR)/menu.o\
		   $(OBJ_DIR)/input.o\
		   $(OBJ_DIR)/scoreboard.o\
		   $(OBJ_DIR)/stats.o\
		   $(OBJ_DIR)/time.o\
		   $(OBJ_DIR)/word.o\
		   $(OBJ_DIR)/main.o

#Resource files for the the executable.
RESOURCE = $(SRC_DIR)/resource.h\
		   $(SRC_DIR)/play.h\
		   $(SRC_DIR)/input.h\
		   $(SRC_DIR)/menu.h\
		   $(SRC_DIR)/scoreboard.h\
		   $(SRC_DIR)/stats.h\
		   $(SRC_DIR)/time.h\
		   $(SRC_DIR)/word.h

#Rule for how the executable should be compiled.
$(TARGET) : $(SOURCE) $(RESOURCE)
	$(CC) $(LOCATION) -o $(TARGET)

OBJ_DIR : mkdir -p $(OBJ_DIR)

#Below are the rules used to create the object files from the c source files.
input.o : ../src/input.c $(SRC_DIR)/resource.h
	$(CC) $(CFLAGS) ../src/input.c -o $(OBJ_DIR)/input.o

main.o : ../src/main.c $(SRC_DIR)/resource.h
	$(CC) $(CFLAGS) ../src/main.c -o $(OBJ_DIR)/main.o

menu.o : ../src/menu.c $(SRC_DIR)/menu.h
	$(CC) $(CFLAGS) ../src/menu.c -o $(OBJ_DIR)/menu.o

play.o : ../src/play.c $(SRC_DIR)/play.h $(SRC_DIR)/play.h
	$(CC) $(CFLAGS) ../src/play.c -o $(OBJ_DIR)/play.o

scoreboard.o : ../src/scoreboard.c $(SRC_DIR)/scoreboard.h
	$(CC) $(CFLAGS) ../src/scoreboard.c -o $(OBJ_DIR)/scoreboard.o

stats.o : ../src/stats.c $(SRC_DIR)/stats.h
	$(CC) $(CFLAGS) ../src/stats.c -o $(OBJ_DIR)/stats.o

time.o : ../src/time.c $(SRC_DIR)/time.h
	$(CC) $(CFLAGS) ../src/time.c -o $(OBJ_DIR)/time.o

word.o : ../src/word.c $(SRC_DIR)/word.h
	$(CC) $(CFLAGS) ../src/word.c -o $(OBJ_DIR)/word.o

#Stops this Makefile from interfering with files named clean
.PHONY : clean

#Defines how the "$make clean" bash command works
clean : 
	rm $(LOCATION) $(TARGET)