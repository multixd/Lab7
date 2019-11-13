//
//  main.cpp
//  Lab7
//
//  Created by Vincent Liang on 11/12/19.
//  Copyright © 2019 Vincent Liang. All rights reserved.
//

#include <iostream>
#include "AVLTree.h"

using namespace std;

int menu() {
  int choice = 0;
  cout << endl << "Enter menu choice: ";
  cout << endl;
  cout 
    << "1. Insert" << endl
    << "2. Print" << endl
    << "3. Quit" << endl;
  cin >> choice;

  // fix buffer just in case non-numeric choice entered
  // also gets rid of newline character
  cin.clear();
  cin.ignore(256, '\n');
  return choice;
}

int main( ) {

  AVLTree tree;

  int choice = menu();

  string entry;

  while (choice != 3) {

    if (choice == 1) {
      cout << "Enter string to insert: ";
      getline(cin, entry);
      cout << endl;

      tree.insert(entry);

    } else if (choice == 2) {
      tree.printBalanceFactors();

    } 
    //fix buffer just in case non-numeric choice entered
    choice = menu();
  }

  return 0;
}
