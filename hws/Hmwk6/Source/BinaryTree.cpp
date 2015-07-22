#include "../Headers/BinaryTree.h"
#include <iostream>
#include <fstream>

BinaryTree::BinaryTree() { Root = NULL; };

bool BinaryTree::insert_vector(std::vector<std::string> &w) {
  // increment through each string in vector
  for (int i = 0, wSize = w.size(); i < wSize; i++) {
    // string to work with
    std::string temp = w[i];
    // this will be the pointer that navigates through the tree
    BTreeNode *currentNode = Root;
    for (int n = 0, s = temp.size(); n < s; n++) {
      if (Root == NULL) {
        // create new BTreeNode, give it's data a value of z
        // because this will differentiate it
        Root = new BTreeNode();
        Root->Data = 'z';
        Root->Lchild = NULL;
        Root->Rchild = NULL;
        currentNode = Root;
      }
      if (temp[n] == 'y') {
        // if the value is not yet in the tree then create new node
        if (currentNode->Lchild == NULL) {
          currentNode->Lchild = new BTreeNode();
          currentNode->Lchild->Data = 'y';
          currentNode->Lchild->Lchild = NULL;
          currentNode->Lchild->Rchild = NULL;
        }
        // make sure to move down the tree
        currentNode = currentNode->Lchild;
      } else if (temp[n] == 'r') {
        // if the value is not yet in the tree then create new node
        if (currentNode->Rchild == NULL) {
          currentNode->Rchild = new BTreeNode();
          currentNode->Rchild->Data = 'r';
          currentNode->Rchild->Lchild = NULL;
          currentNode->Rchild->Rchild = NULL;
        }
        // making sure to move down the tree
        currentNode = currentNode->Rchild;
      } // End if
    } // End inner For
  } // End outer For
  return true;
}

// this will compare the vector to the tree that we made and will read yes if
// they do
bool BinaryTree::compare_vector_to_tree(std::vector<std::string> &v) {
  char *file1 = "BReads_map_results.txt";
  std::ofstream out (file1, std::ofstream::out);
  int stringcount = 0; // will keep track of how many strings we've gone through
                       // to print to file
  int truthcount = 0;
  // will keep track of how many strings match from reads.txt to my tree
  for (int i = 0; i < v.size(); i++) {
    std::string temp = v[i]; // using string for comparison
    // will help keep track of what's in the tree and what's not
    bool flag = true;
    BTreeNode *currentNode = this->Root; // using the Root from this binary tree
    for (int n = 0; n < 10; n++)         // only ten letters in each string
    {
      std::cout << temp[n];    // printing to console each character
      if (temp[n] == 'r') // if the letter is r
      {
        if (currentNode->Rchild != NULL &&
            currentNode->Rchild->Data == temp[n]) {
          currentNode = currentNode->Rchild;
        }
        // if the Rchild is not NULL, AND the Rchild's data is r then move on
        // (double checking)
        else {
          flag = false;
          break;
        }                          // else make the flag false, break for loop
      } else if (temp[n] == 'y') { // if the letter is y,
        if (currentNode->Lchild != NULL &&
            currentNode->Lchild->Data == temp[n]) {
          currentNode = currentNode->Lchild;
        }
        // if the Lchild is not NULL AND the Rchild's data is r then move on
        // (double checking)
        else {
          flag = false;
          break;
        } // else make the flag false, break for loop
      } else {
        flag = false;
        break;
      }
    }
    stringcount++;
    if (flag == true) {
      truthcount++;
      std::cout << std::endl;
      std::cout << "String " << i << ": is mapped." << std::endl;
    } else if (flag == false) {
      std::cout << "String " << i << ": is not mapped." << std::endl;
    }
  }
  std::cout << "Total that has been read: " << stringcount << std::endl;
  out << "Total that has been read: " << stringcount << std::endl;
  std::cout << "Total that is mapped: " << truthcount << std::endl;
  out << "Total that is mapped: " << truthcount << std::endl;
  out.clear();
  out.close();
  return true;
}
