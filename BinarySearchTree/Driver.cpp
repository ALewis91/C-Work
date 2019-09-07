#include "Entry.h"
#include "bst.h"
#include <string>
#include <iostream>
int main() 
{
       std::cout << "Driver Author: Aaron Lewis\n";
       typedef SearchTree<Entry<int, std::string>> BST;
       typedef Entry<int, std::string> entry;
       std::cout << "Creating binary search tree bst...\n";
       
       BST bst;
       
       if (bst.empty())
              std::cout << "bst is empty\n";
       else
              std::cout << "bst is not empty\n";
              
       std::cout << "Inserting k:1, v:\"Aaron\"...\n";
       bst.insert(1, "Aaron");
       std::cout << "Inserting k:2, v:\"Komi\"...\n";
       bst.insert(2, "Komi");
       std::cout << "Inserting k:3, v:\"Nika\"...\n";
       bst.insert(3, "Nika");
       
       if (bst.empty())
              std::cout << "bst is empty\n";
       else
              std::cout << "bst is not empty\n";
              
       std::cout << "Current size: " << bst.size() << std::endl;
       std::cout << "Finding Entry with key:1...";
       BST::Iterator it = bst.find(1);
       entry e = *it;
       std::cout << "\nEntry with key 1: " << "k:" << e.key();
       std::cout << ", v:\"" << e.value() << "\"" << std::endl;
       std::cout << "Removing Entry with key:1...\n";
       bst.erase(1);
       std::cout << "Current size: " << bst.size() << std::endl;
       it = bst.find(2);
       e = *it;
       std::cout << "\nEntry with key 2: " << "k:" << e.key();
       std::cout << ", v:\"" << e.value() << "\"" << std::endl;
       it = bst.find(3);
       e = *it;
       std::cout << "\nEntry with key 3: " << "k:" << e.key();
       std::cout << ", v:\"" << e.value() << "\"" << std::endl;
       
       return 0;
}
