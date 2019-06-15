# The Adventure in Caves

This game is my project for the course Objected Oriented Programming (summer semester, 2019) on the University of Wroclaw. It is written in C++ using SFML 2.5.1 library.

**What is it about? - short description of the game**

Player appears in the cave, his main goal is to get out of it. To do so, he needs to pass few levels, in which he should collect as much coins as possible and fight his enemies, who are ready to stop him.
See it here: https://www.youtube.com/watch?v=XgQRgbAI9ow


**Installing SFML, compiling and running the game:**
```
$ sudo apt-get install libsfml-dev
$ g++ -c *.cpp 
$ g++ -o TAiC *.o -lsfml-graphics -lsfml-window -lsfml-system
$ ./TAiC
```
