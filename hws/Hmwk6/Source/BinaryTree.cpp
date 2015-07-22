#include "../Headers/BinaryTree.h"
#include <iostream>
#include <fstream>

BinaryTree::BinaryTree()
 : Root(nullptr) 
{
};

// deleting the nodes recursively.
BinaryTree::~BinaryTree()
{
  if(Root) delete Root;
};

BTreeNode * BinaryTree::CreateNode(const char val) {
  return new BTreeNode(val);
}

BTreeNode * BinaryTree::AppendNode(BTreeNode * parentNode, char val) {
  if(!parentNode) throw "parentNode was null!!";

  switch (val) {
  case ('y'):
    // if the value is not yet in the tree then create new node
    if (parentNode->Lchild == nullptr) {
      parentNode->Lchild = BinaryTree::CreateNode('y');
    }
    // make sure to move down the tree
    parentNode = parentNode->Lchild;
    break;
  case ('r'):
    // if the value is not yet in the tree then create new node
    if (parentNode->Rchild == nullptr) {
      parentNode->Rchild = BinaryTree::CreateNode('r');
    }
    // making sure to move down the tree
    parentNode = parentNode->Rchild;
    break;
  default:
    return nullptr;
  }
  return parentNode;
}

bool BinaryTree::insert_vector(std::vector<std::string> &w) {
  // increment through each string in vector
  for (int i = 0, wSize = w.size(); i < wSize; i++) {
    // string to work with
    std::string temp = w[i];
    // this will be the pointer that navigates through the tree
    BTreeNode *currentNode = Root;
    for (int n = 0, s = temp.size(); n < s; n++) {
      if (Root == nullptr) {
        // create new BTreeNode, give it's data a value of z
        // because this will differentiate it
        Root = BinaryTree::CreateNode('z');
        currentNode = Root;
      }
      currentNode = BinaryTree::AppendNode(temp[n]);
      if (!currentNode) break;
    } // End inner For
  } // End outer For
  return true;
}

// Compares all strings in the vector<string> w
// For possible matches within the BinaryTree
// Returns True if Operation is succesful
bool BinaryTree::compare_vector_to_tree(std::vector<std::string> &v) {
  char *file1 = "BReads_map_results.txt";
  std::ofstream out (file1, std::ofstream::out);
  if(!out.is_open()) {
    std::cout << "Error Opening file to write." << std::endl;
    return false;
  }

  // will keep track of how many strings we've gone through to print to file
  int stringcount = 0; 
  // will keep track of how many strings match from reads.txt to my tree
  int truthcount = 0;

  bool found = false;
  for (int i = 0, s = v.size(); i < s; i++) {
    std::string temp = v[i]; // using string for comparison
    // will help keep track of what's in the tree and what's not
    found = BinaryTree::CheckCharsInStr(temp);
    stringcount++;
    if (found == true) {
      truthcount++;
      std::cout << std::endl;
      std::cout << "String " << temp.c_str() << ": is mapped." << std::endl;
    } else if (found == false) {
      std::cout << "String " << temp.c_str() << ": is not mapped." << std::endl;
    }
  } // End For

  std::cout << "Total that have been read: " << stringcount << std::endl;
  out << "Total that have been read: " << stringcount << std::endl;
  std::cout << "Total that are mapped: " << truthcount << std::endl;
  out << "Total that are mapped: " << truthcount << std::endl;
  out.clear();
  out.close();
  return true;
}

// This Function Checks checks a string of length 10 for
// 'r' or 'y' members that match the a path in the BinaryTree
// Returns True if found, false otherwise
bool BinaryTree::CheckCharsInStr(std::string temp) {
  bool flag = true;
  BTreeNode *currentNode = this->Root; // using the Root from this binary tree
  for (int n = 0; n < 10; n++) {         // only ten letters in each string
    std::cout << temp[n];    // printing to console each character
    if (temp[n] == 'r') {
      if (currentNode->Rchild && currentNode->Rchild->GetData() == temp[n]) {
        currentNode = currentNode->Rchild;
      } else {
        // if the Rchild is not nullptr, AND the Rchild's data is r then move on
        flag = false;
        break;
      } 
    } else if (temp[n] == 'y') {
      if (currentNode->Lchild && currentNode->Lchild->GetData() == temp[n]) {
        currentNode = currentNode->Lchild;
      } else {
        // if the Lchild is not nullptr AND the Rchild's data is r then move on
        flag = false;
        break;
      }
    } else { // If for some reason bad data is in the str
      flag = false;
      break;
    }
  } // End For
  return flag;
}

