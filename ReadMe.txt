1. Hunter Peasley and John Mulhern
2390162
hpeasley@chapman.edu
CPSC 350 
PA1: Robber Language


2) Source files:
Level.h
Level.cpp
Mario.h
Mario.cpp 
GameWorld.h
GameWorld.cpp
main.cpp



3) It compiles fine, but some of the time, you get a seg fault. If that happens, just run it until you get a version that doesn’t get a seg fault, and look at that one.

Also, there is a very rare possibility that he would try to defeat the boss and it would continue to print that regardless of his lives.



4) 
g++ -o main *.cpp
./main INPUT.txt OUTPUT.txt
