//cards.cpp
//Authors: Your Partner's Name and Your Name
//Implementation of the classes defined in cards.h
#include <iostream>
using namespace std;
#include <string>
#include "cards.h"

Card::Card(char x, char y) {
      suit = x;
      value = y;
      next = 0;
    }

bool Card::operator==(const Card& c) {
      if (suit == c.suit && value == c.value) return true;
      return false;
    }
    
Hand::Hand() {
      first = 0;
      last = 0;
    }
    
int Hand::contains(Card* c) {
      int count = 0;
      Card* iter = first;
      while(iter) {
	count++;      
        if (iter == c) return count;
	iter = iter->next;
      }
      return 0;
    }
    
void Hand::remove(int x) {
      if (x == 0) return;
      if (x == 1) {
	if (first == last) delete first;
	else {
	  Card* temp = first;
	  first = first->next;
	  delete temp;
	}
        return;
      }
      else {
	int count = 2;
        Card* iter = first;
	while(iter) {
	  if (x == count) {
	    Card* temp = iter->next;
	    iter->next = iter->next->next;
	    delete temp;
	  }
	  iter = iter->next;
	  count++;
	}
      }
     return;
    }

void Hand::add(Card* c) {
      if (!first && !last) {
        first = c;
	last = c;
      }
      else {
      last->next = c;
      last = c;
      }
    }

Hand::~Hand() {
      if (first == last) delete first;
      else {
      Card* iter = first;
      Card* temp;
      while (iter) {
        temp = iter->next;
	delete iter;
	iter = temp;
      }
      }
    }

