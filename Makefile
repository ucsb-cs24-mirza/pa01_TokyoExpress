main.o: main.cpp cards.h
	g++ main.cpp -c

cards.o: cards.cpp cards.h
	g++ cards.cpp -c

game: main.o cards.o
	g++ main.o cards.o -o game

testcards.o: testcards.cpp testcards.h cards.h
	g++ testcards.cpp -c

testcards: cards.o testcards.o
	g++ cards.o testcards.o -o testcards
