// This file should contain unit tests for all the 
// public interfaces of the classes that you implement

#include "cards.h"
#include "testcards.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
  runAll();
  return 0;
}

void runAll(){
  test_append();
  test_equal();
  test_card();
}

void test_append(){
  START_TEST("test_append");
  test_append_empty_list();
  test_append_single_element_list();
  END_TEST("test_append");

}

void test_equal(){
  START_TEST("test_equal");
  test_equal_empty_list();
  //test_equal_single_element_list();
  END_TEST("test_equal");

}

void test_card(){
  START_TEST("test_card");
  test_card_operator_double_equal();
  test_contains();
  test_add();
  test_remove();
  //test_equal_single_element_list();
  END_TEST("test_card");
}


void test_append_empty_list(){ 
// A test case for append single card node to LinkedList
}

void test_append_single_element_list(){ 
  // Tests cases should be independent,
    // small, fast, orthogonal (test for different cases)

}
void test_equal_empty_list(){ 
  string testname = "case 0: [], []";
}

void test_contains() {
  Hand h;
  Card c('s', '1');
  Card d('h', 'k');
} 

void test_add() {
  Hand h;
  Card* c = new Card('d', '3');
  cout << *c << endl;
  h.add(c);
  cout << *(h.first) << endl;
}

void test_remove() {
  Hand h;
  h.add(new Card('s', '1'));
  cout << *(h.first) << endl;
  h.remove(1);
  h.add(new Card('d', 'k'));
  cout << *(h.first) << endl;
}

void test_card_operator_double_equal(){
  Card c('s', '1');
  Card d('d', '1');
  if (c == d) cout << "TRUE" << endl;
  else cout << "FALSE" << endl;
}




