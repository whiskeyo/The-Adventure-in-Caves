# The Adventure in Caves

This game is my project for the course Objected Oriented Programming (summer semester, 2019) on the University of Wroclaw. It is written in C++ using SFML 2.5.1 library.

## What is it about? - short description of the game

Player appears in the cave, his main goal is to get out of it. To do so, he needs to pass few levels, in which he should collect as much coins as possible and fight his enemies, who are ready to stop him.

See it [on my YouTube channel](https://www.youtube.com/watch?v=XgQRgbAI9ow).

## Installing SFML, compiling and running the game

```shell
sudo apt-get install libsfml-dev
cmake -S . -B build && cmake --build build -j$(nproc)
./build/the-adventure-in-caves
```

## Level file structure

```plain
<width>
<height>
<width * height blocks separated by spaces and new lines after reaching width>
<file with background>
<blocks color as 3 values 0-255>
```
