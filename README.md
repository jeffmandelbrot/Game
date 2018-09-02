# Game
## Compilation
g++ -std=c++11 -lpthread -c crypters/\*.cpp main.cpp

g++ -std=c++11 -lpthread \*.o -o bin/game -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

cd bin

./game
