#include "..\\Headers\\QuarternaryTree.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace hw6;

QuarternaryTree::QuarternaryTree()
  : Root(nullptr)
{
};

// Deletes all Nodes Recursively
QuarternaryTree::~QuarternaryTree()
{
  if(Root) delete Root;
};

QTreeNode * QuarternaryTree::CreateNode(const char val) {
  return new QTreeNode(val);
}

// Creates and appends a node onto the parentNode into this Quaternary Tree
// If val IN ('a', 't', 'c', 'g') Returns the newly created node
// Else Returns nullptr
QTreeNode * QuarternaryTree::AppendNode(QTreeNode * parentNode, char val) {
  if (!parentNode) throw "ParentNode was null!";
  switch (val) {
  case ('a'): // Adenine
    // if the value is not yet in the tree then create new node
    if (parentNode->child1 == nullptr) {
      parentNode->child1 = CreateNode('a');
    }
    // make sure to move down the tree
    parentNode = parentNode->child1;
    return parentNode;
  case ('t'): // Thymine
    // if the value is not yet in the tree then create new node
    if (parentNode->child2 == nullptr) {
      parentNode->child2 = CreateNode('t');
    }
    parentNode = parentNode->child2; // make sure to move down the tree
    return parentNode;
  case ('c'): // Cytosine
    // if the value is not yet in the tree then create new node
    if (parentNode->child3 == nullptr) {
      parentNode->child3 = CreateNode('c');
    }
    parentNode = parentNode->child3; // make sure to move down the tree
    return parentNode;
  case ('g'): // Guanine
    // if the value is not yet in the tree then create new node
    if (parentNode->child4 == nullptr) {
      parentNode->child4 = CreateNode('g');
    }
    parentNode = parentNode->child4; // make sure to move down the tree
    return parentNode;
  }
  return nullptr;
}

// Inserts each string in vector<string> w into the QuarternaryTree
bool QuarternaryTree::insert_vector(std::vector<std::string> &w) {
  std::string temp;
  for (int i = 0, sSize = w.size(); i < sSize; i++) {
    temp = w[i]; // string to work with
    // this will be the pointer that navigates through the tree
    QTreeNode *currentNode = Root;
    for (int n = 0, tSize = temp.size(); n < tSize; n++) {
      if (Root == nullptr) {
        // create new BTreeNode, give it's data a value of z
        // because this will differentiate it
        Root = QuarternaryTree::CreateNode('z');
        currentNode = Root;
      }
      currentNode = AppendNode(currentNode, temp[n]);
      if (!currentNode) break;
    } // End inner For
  } // End outer For
  return true;
}

// Checks the Chars in the std::string inStr to see
// If it matches any of the Tree's mappings
// Returns True if match found, false otherwise
bool QuarternaryTree::CheckCharsInStr(std::string inStr) {
#include "ignore_compiler_warning\\push.h" //start ignoring here
#include "ignore_compiler_warning\\force_val_to_bool.h" // MSC C4800
  bool flag = true;
  QTreeNode *currentNode = this->Root;
  for (int n = 0; n < 10; n++) {
    switch (inStr[n]) {
    case ('a'): // Adenine
      (currentNode->child1 && currentNode->child1->Data == inStr[n])
        ? (currentNode = currentNode->child1) != 0 : flag = false;
    break;
    case ('t'): // Thymine
      (currentNode->child2 && currentNode->child2->Data == inStr[n])
        ? (currentNode = currentNode->child2) != 0 : (flag = false);
    break;
    case ('c'): // Cytosine
      (currentNode->child3 && currentNode->child3->Data == inStr[n])
        ? (currentNode = currentNode->child3) != 0 : (flag = false);
    break;
    case ('g'): // Guanine
      (currentNode->child4 && currentNode->child4->Data == inStr[n])
        ? (currentNode = currentNode->child4) != 0 : (flag = false);
      break;
    } // End Switch
    if (!flag) break; // out of for loop
  }
#include "ignore_compiler_warning\\pop.h" // Stop ignoring here
  return flag;
}

// Compares all strings in the vector<string> w
// For possible matches within the BinaryTree
// Returns True if Operation is successful
bool QuarternaryTree::compare_vector_to_tree(std::vector<std::string> &v) {
  std::string temp;
  bool flag = false;
  int stringCount = 0;
  int truthCount = 0; // will keep track of how many strings match
  
  // Output File
  const char * file1 = "Results\\QReads_Map_Results.txt";
  std::ofstream out(file1, std::ofstream::out);
  if(!out.is_open()) {
    std::cout << "Error Opening file to write." << std::endl;
    return false;
  }
  for (int i = 0, s = v.size(); i < s; i++) {
    temp = v[i]; // using string for comparison
    // will help keep track of what's in the tree and what's not
    flag = CheckCharsInStr(temp);
    stringCount++; // incrementing the amount of strings counted for comparison
    if (flag) {
      truthCount++;
      std::cout << "String (" << temp << ") is Mapped." << std::endl;
      out << "String (" << temp << ") is Mapped." << std::endl;
    } else {
      std::cout << "String (" << temp << ") is not Mapped." << std::endl;
      out << "String (" << temp << ") is not Mapped." << std::endl;
    }
  }
  std::cout << "Total QTree that reads: " << stringCount << std::endl;
  out << "Total QTree that reads: " << stringCount << std::endl;
  std::cout << "Total QTree reads mapped: " << truthCount << std::endl;
  out << "Total QTree reads mapped: " << truthCount << std::endl;
  out.clear();
  out.close();
  return true;
}
