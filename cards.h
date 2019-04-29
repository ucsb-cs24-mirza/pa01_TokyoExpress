//cards.h
//Authors: Your Partner's Name and Your Name
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#endif
#include <iostream>
using namespace std;

class Card {
  public:
    char suit;
    char value;
    Card *next;

    Card(char x, char y);
    
    bool operator == (const Card& c);
    
    friend ostream& operator<<(ostream& os, Card& c) {
      os << c.suit << " " << c.value;
      return os;
    }


};

class Hand {
  public:
    Card* first;
    Card* last;
    Hand();
    int contains(Card* c);
    // Precondition: Card value is inputted
    // Postcondition: If card is found, location will be outputted. 
    // Else will output 0.
    void remove(int x);
    // Precondition: Location value is inputted
    // Postcondition: Card at that location will be removed.
    void add(Card* c);

    ~Hand();
};
