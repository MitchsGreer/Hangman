Hangman in C++
==============
This is hangman implemented in C++.

Requirements
------------
- CMake
- A C++ compiler (this was tested with g++)

Building
--------
Run something like the following (building GNU Makefiles in this example):
```
#> cmake -S . -B build -G "Unix Makefiles"
#> cd build
#> make
```

Running in Docker
-----------------
There is a dockerfile for this implementation to build and run:
```
#> docker build -t hangman_cpp .
#> docker run -ti hangman_cpp
```