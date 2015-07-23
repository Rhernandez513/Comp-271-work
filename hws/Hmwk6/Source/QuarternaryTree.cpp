#include "../Headers/QuarternaryTree.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

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

// Creates and appends a node onto the parentNode into this Quarternary Tree
// If val IN ('a', 't', 'c', 'g') Returns the newly created node
// Else Returns nullptr
QTreeNode * QuarternaryTree::AppendNode(QTreeNode * parentNode, char val) {
  if (!parentNode) throw "ParentNode was null!";
  switch (val) {
  case ('a'):
    // if the value is not yet in the tree then create new node
    if (parentNode->child1 == nullptr) {
      parentNode->child1 = QuarternaryTree::CreateNode('a');
    }
    // make sure to move down the tree
    parentNode = parentNode->child1;
    return parentNode;
  case ('t'):
    // if the value is not yet in the tree then create new node
    if (parentNode->child2 == nullptr) {
      parentNode->child2 = QuarternaryTree::CreateNode('t');
    }
    parentNode = parentNode->child2; // make sure to move down the tree
    return parentNode;
  case ('c'):
    // if the value is not yet in the tree then create new node
    if (parentNode->child3 == nullptr) {
      parentNode->child3 = QuarternaryTree::CreateNode('c');
    }
    parentNode = parentNode->child3; // make sure to move down the tree
    return parentNode;
  case ('g'):
    // if the value is not yet in the tree then create new node
    if (parentNode->child4 == nullptr) {
      parentNode->child4 = QuarternaryTree::CreateNode('g');
    }
    parentNode = parentNode->child4; // make sure to move down the tree
    return parentNode;
  }
  return nullptr;
}

// Inserts each string in vector<string> w into the QuarternaryTree
bool QuarternaryTree::insert_vector(std::vector<std::string> &w) {
  std::string temp;
  for (auto i = 0; i < w.size(); i++) {
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
  QTreeNode *currentNode = this->Root;
  for (int n = 0; n < 10; n++) {
    switch (inStr[n]) {
    case ('a'): // Adenine
      (currentNode->child1 && currentNode->child1->Data == inStr[n])
        ? currentNode = currentNode->child1 : return false;
    break;
    case ('t'): // Thymine
      (currentNode->child2 && currentNode->child2->Data == inStr[n])
        ? currentNode = currentNode->child2 : return false;
    break;
    case ('c'): // Cytosine
      (currentNode->child3 && currentNode->child3->Data == inStr[n])
        ? currentNode = currentNode->child3 : return false;
    break;
    case ('g'): // Guanine
      (currentNode->child4 && currentNode->child4->Data == inStr[n])
        ? currentNode = currentNode->child4 : return false;
    break;
    } // End Switch
  }
  return true;
}

// Compares all strings in the vector<string> w
// For possible matches within the BinaryTree
// Returns True if Operation is succesful
bool QuarternaryTree::compare_vector_to_tree(std::vector<std::string> &v) {
  bool flag;
  std::string temp;
  char *file1 = "../Results/QReads_Map_Results.txt";
  std::ofstream out(file1, std::ofstream::out);
  if(!out.is_open()) {
    std::cout << "Error Opening file to write." << std::endl;
    return false;
  }
  int stringCount = 0;
  int truthCount = 0;
  // will keep track of how many strings match from reads.txt to my tree
  for (int i = 0; i < v.size(); i++) {
    temp = v[i]; // using string for comparison
    // will help keep track of what's in the tree and what's not
    flag = QuarternaryTree::CheckCharsInStr(temp);
    stringCount++; // incrementing the amount of strings counted for comparison
    if (flag == true) {
      truthCount++;
      std::cout << "String " << i + 1 << ": is Mapped." << std::endl;
      out << "String " << i + 1 << ": is Mapped." << std::endl;
    } else if (flag == false) {
      std::cout << "String " << i + 1 << ": is not Mapped." << std::endl;
      out << "String " << i + 1 << ": is not Mapped." << std::endl;
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

