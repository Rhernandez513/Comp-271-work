#include "..\\Headers\\BinaryTree.h"
#include <iostream>
#include <fstream>

using namespace hw6;

BinaryTree::BinaryTree()
 : Root(nullptr) 
{
};

// Delete's All node's in the BinaryTree
// Before deleting itself
BinaryTree::~BinaryTree()
{
  if(Root) delete Root;
};

// Factory Method for BTreeNode
BTreeNode * BinaryTree::CreateNode(const char val) {
  return new BTreeNode(val);
}

// Creates and appends a node onto the parentNode 
// into this Binary Tree If val == 'r' || val == 'y'
// Returns the newly created node
BTreeNode * BinaryTree::AppendNode(BTreeNode * parentNode, char val) {
  if(!parentNode) return nullptr;
  switch (val) {
  case ('y'):
    // if the value is not yet in the tree then create new node
    if (parentNode->Lchild == nullptr) {
      parentNode->Lchild = BinaryTree::CreateNode('y');
    }
    // make sure to move down the tree
    parentNode = parentNode->Lchild;
    return parentNode;
  case ('r'):
    // if the value is not yet in the tree then create new node
    if (parentNode->Rchild == nullptr) {
      parentNode->Rchild = BinaryTree::CreateNode('r');
    }
    // making sure to move down the tree
    parentNode = parentNode->Rchild;
    return parentNode;
  default:
  return nullptr;
  }
}

// Inserts Each string in vector<string> w into this Binary Tree
bool BinaryTree::insert_vector(std::vector<std::string> &w) {
  std::string temp;
  // increment through each string in vector
  for (int i = 0, wSize = w.size(); i < wSize; i++) {
    // string to work with
    temp = w[i];
    // this will be the pointer that navigates through the tree
    BTreeNode *currentNode = Root;
    for (int n = 0, s = temp.size(); n < s; n++) {
      if (Root == nullptr) {
        // create new BTreeNode, give it's data a value of z
        // because this will differentiate it
        currentNode = Root = BinaryTree::CreateNode('z');
      }
      currentNode = BinaryTree::AppendNode(currentNode, temp[n]);
      if (!currentNode) break;
    } // End inner For
  } // End outer For
  return true;
}

// Compares all strings in the vector<string> w
// For possible matches within the BinaryTree
// Returns True if Operation is successful
bool BinaryTree::compare_vector_to_tree(std::vector<std::string> &v) {
  std::string temp;
  int stringCount = 0; // how many strings we've gone through to print to file
  int truthCount = 0;  // will keep track of how many strings match
  const char * file1 = "Results\\BReads_map_results.txt";
  std::ofstream out (file1, std::ofstream::out);
  if(!out.is_open()) {
    std::cout << "Error Opening file to write." << std::endl;
    return false;
  }

  bool found = false;
  for (int i = 0, s = v.size(); i < s; i++) {
    temp = v[i]; // using string for comparison
    // will help keep track of what's in the tree and what's not
    found = CheckCharsInStr(temp);
    stringCount++;
    if (found) {
      truthCount++;
      std::cout << "String (" << temp << ") is mapped." << std::endl;
      out << "String (" << temp << ") is mapped." << std::endl;
    } else {
      std::cout << "String (" << temp << ") is not mapped." << std::endl;
      out << "String (" << temp << ") is not mapped." << std::endl;
    }
  } // End For

  // Report on what read vs was mapped to the tree
  const char * readMsg = "\nTotal that have been read: ";
  const char * mapMsg = "\nTotal that are mapped: ";
  std::cout << readMsg << stringCount << std::endl;
  out << readMsg << stringCount << std::endl;
  std::cout << mapMsg << truthCount << std::endl;
  out << mapMsg << truthCount << std::endl;
  out.clear();
  out.close();

  return true;
}

// This Function Checks checks a string of length 10 for
// 'r' or 'y' members that match the a path in the BinaryTree
// Returns True if found, false otherwise
bool BinaryTree::CheckCharsInStr(std::string temp) {
#include "ignore_compiler_warning\\push.h"
#include "ignore_compiler_warning\\force_val_to_bool.h" // MSC C4800
  bool flag = true;
  BTreeNode *currentNode = this->Root; // using the Root from this binary tree
  for (int n = 0; n < 10; n++) {       // only ten letters in each string
    switch (temp[n]) {
    case ('r'):
    (currentNode->Rchild && currentNode->Rchild->GetData() == temp[n])
      ? (currentNode = currentNode->Rchild) != 0 : (flag = false);
      break;
    case ('y'):
    (currentNode->Lchild && currentNode->Lchild->GetData() == temp[n])
      ? (currentNode = currentNode->Lchild) != 0 : (flag = false);
      break;
    } // End Switch
    if (!flag) break; // Out of For loop
  }
#include "ignore_compiler_warning\\pop.h"
  return flag;
}

