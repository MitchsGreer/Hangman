# Hangman
Hangman game implemented in C. Great to look over if you are trying to learn C as it has a wide array of library use and is not a complex game. This game has been developed in Linux and has not been tested in a windows envirenment.

## To Build Hangman
At the moment the files are located by moving up from the home directory. There are some preloaded stats in the `Resource` folder. if you would like to use those you'll need to change the file paths in the `resource.h` file. To do this all you need to do is:

1. Open the `resource.h` file with any text editer
2. Open a terminal
3. Navigate into the resource directory
4. Run the `pwd` command in the terminal
5. Copy the output of the command into the `#define path/name/here/stats` areas, it will look like this
```
#define SCOREBOARD "/home/mitchel/Documents/Projects/Hangman/Resources/scoreboard"
#define STATS "/home/mitchel/Documents/Projects/Hangman/Resources/stats"
#define TIME "/home/mitchel/Documents/Projects/Hangman/Resources/time"
```
   Where it says `/home/mitchel/Documents/Projects/Hangman/Resources` paste your ouput
This should be it, let me know if you have any problems. If you dont want to uses those file, you can start the game as normal and disregard the error messages at the top of the screen.
