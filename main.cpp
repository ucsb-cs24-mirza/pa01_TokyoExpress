#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"

using namespace std;

int main(int argv, char** argc){
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // Create two objects of the class you defined 
  // to contain two sets of cards in two input files
  Hand alice;
  Hand bob;

  char suit;
  char value;
  while (getline (cardFile1, line) && (line.length() > 0)){
    suit = line[0];
    value = line[2];
    alice.add(new Card(suit, value));
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    suit = line[0];
    value = line[2];
    bob.add(new Card(suit, value)); 
  }
  cardFile2.close();

  bool gameActive = 1;
  char turn = 'a'; // Alice's turn first
  bool matchFound = 0;

  
  cout << "Alice's cards: " << endl;
  for (Card *iter = alice.first; iter != NULL; iter = iter->next) {
    cout << *iter << endl;    
  }

  cout << "Bob's cards: " << endl;
  for (Card *iter2 = bob.first; iter2 != NULL; iter2 = iter2->next) {
    cout << *iter2 << endl;    
  }

  return 0;
}
