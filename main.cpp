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

  // Inputting Cards Into Linked List
  
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

  // Finished inputting

  bool gameActive = 1; // Game tracker
  bool matchFound = 0; // Token variable
  
  while(gameActive) {
    // Alice's turn
    for (Card*iter = alice.first; iter != NULL; iter = iter->next) {
      if (bob.contains(iter)) {
	cout << "Alice picked matching card " << *iter << endl;
        bob.remove(bob.contains(iter)); // removing both
	alice.remove(alice.contains(iter));
	matchFound = 1;
	break; // break out of loop if match found
      }
    }
    if (matchFound == 0) gameActive = 0; // no match = game over
    if (matchFound == 1) {
      matchFound = 0; // reset token variable
      // Bob's turn
      for (Card*iter = bob.first; iter != NULL; iter = iter->next) {
        if (alice.contains(iter)) {
	  cout << "Bob picked matching card " << *iter << endl;
          alice.remove(alice.contains(iter)); // removing both
	  bob.remove(bob.contains(iter));
	  matchFound = 1;
	  break;
      }
    }
    if (matchFound == 0) gameActive = 0; // no match = game over
    }
  }
  cout << endl;
  // Final output

  cout << "Alice's cards: " << endl;
  for (Card *iter = alice.first; iter != NULL; iter = iter->next) {
    cout << *iter << endl;    
  }
  cout << endl;
  cout << "Bob's cards: " << endl;
  for (Card *iter2 = bob.first; iter2 != NULL; iter2 = iter2->next) {
    cout << *iter2 << endl;    
  }

  return 0;
}
