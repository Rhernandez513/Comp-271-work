#include "../Headers/QuarternaryTree.h"
#include <vector>
#include <iostream>
#include <fstream>

QuarternaryTree::QuarternaryTree()
  : Root(nullptr)
{
};

// deleting the nodes recursively.
QuarternaryTree::~QuarternaryTree()
{
  if(Root) delete Root;
};

QTreeNode * QuarternaryTree::CreateNode(const char val) {
  return new QTreeNode(val);
}

bool QuarternaryTree::insert_vector(std::vector<std::string> &w) {
  for (auto i = 0; i < w.size();
       i++) {           // increment through each string in vector
    std::string temp = w[i]; // string to work with
    // this will be the pointer that navigates through the tree
    QTreeNode *currentNode = Root;
    for (int n = 0, tSize = temp.size(); n < tSize; n++) {
      if (Root == nullptr) {
        // create new BTreeNode, give it's data a value of z
        // because this will differentiate it
        Root = QuarternaryTree::CreateNode('z');
        currentNode = Root;
      }
      if (temp[n] == 'a') {
        // if the value is not yet in the tree then create new node
        if (currentNode->child1 == nullptr) {
          currentNode->child1 = QuarternaryTree::CreateNode('a');
        }
        // make sure to move down the tree
        currentNode = currentNode->child1;
      }
      if (temp[n] == 't') {
        // if the value is not yet in the tree then create new node
        if (currentNode->child2 == nullptr) {
          currentNode->child2 = QuarternaryTree::CreateNode('t');
        }
        currentNode = currentNode->child2; // make sure to move down the tree
      }
      if (temp[n] == 'c') {
        // if the value is not yet in the tree then create new node
        if (currentNode->child3 == nullptr) {
          currentNode->child3 = QuarternaryTree::CreateNode('c');
        }
        currentNode = currentNode->child3; // make sure to move down the tree
      }
      if (temp[n] == 'g') {
        // if the value is not yet in the tree then create new node
        if (currentNode->child4 == nullptr) {
          currentNode->child4 = QuarternaryTree::CreateNode('g');
        }
        currentNode = currentNode->child4; // make sure to move down the tree
      }
    } // End inner For
    // double checking to make sure that currentnode will point to nothing
    currentNode->child1 = nullptr;
    currentNode->child2 = nullptr;
    currentNode->child3 = nullptr;
    currentNode->child4 = nullptr;
  } // End outer For
  return true;
}

bool QuarternaryTree::compare_vector_to_tree(std::vector<std::string> &v) {
  char *file1 = "QReads_map_results.txt";
  std::ofstream out(file1, std::ofstream::out);
  int stringcount = 0; // will keep track of how many strings we've gone through
                       // to print to file
  int truthcount =
      0; // will keep track of how many strings match from reads.txt to my tree
  for (int i = 0; i < v.size(); i++) {
    std::string temp = v[i]; // using string for comparison
    bool flag =
        true; // will help keep track of what's in the tree and what's not
    QTreeNode *currentNode = this->Root; // using the Root from this binary tree
    for (int n = 0; n < 10; n++) {       // only ten letters in each string
      if (temp[n] == 'a') {              // if the letter is a
        if (currentNode->child1 != nullptr &&
            currentNode->child1->Data == temp[n]) {
          currentNode = currentNode->child1;
        } else {
          flag = false;
          break;
        }                          // if a then it will move down the tree
      } else if (temp[n] == 't') { // if the letter is t,
        if (currentNode->child2 != nullptr &&
            currentNode->child2->Data == temp[n]) {
          currentNode = currentNode->child2;
        }
        // if the Lchild is not nullptr AND the Rchild's data is r
        // then move on (double checking)
        else {
          flag = false;
          break;
        }                          // else make the flag false, break for loop
      } else if (temp[n] == 'c') { // if the letter is c
        if (currentNode->child3 != nullptr &&
            currentNode->child3->Data == temp[n]) {
          currentNode = currentNode->child3;
        } else {
          flag = false;
          break;
        } // if the letter is c
        // then it will move down the tree
      } else if (temp[n] == 'g') {
        if (currentNode->child4 != nullptr &&
            currentNode->child4->Data == temp[n]) {
          currentNode = currentNode->child4;
        } else {
          flag = false;
          break;
        }
      } else {
        flag = false;
        break;
      }
    }
    stringcount++; // incrementing the amount of strings counted for comparison
    if (flag == true) {
      truthcount++;
      std::cout << "String " << i + 1 << ": is Mapped." << std::endl;
      out << "String " << i + 1 << ": is Mapped." << std::endl;
    } else if (flag == false) {
      std::cout << "String " << i + 1 << ": is not Mapped." << std::endl;
      out << "String " << i + 1 << ": is not Mapped." << std::endl;
    }
  }
  std::cout << "Total QTree that reads: " << stringcount << std::endl;
  out << "Total QTree that reads: " << stringcount << std::endl;
  std::cout << "Total QTree reads mapped: " << truthcount << std::endl;
  out << "Total QTree reads mapped: " << truthcount << std::endl;
  out.clear();
  out.close();
  return true;
}

