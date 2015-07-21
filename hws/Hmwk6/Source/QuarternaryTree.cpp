#include "../Headers/QTreeNode.h"
#include <vector>
#include <iostream>
#include <fstream>

class QuarternaryTree // created a class for the quarternary tree
    {
private:
  void clearing();
  void recursive_delete(QTreeNode *node);
  void deleteNode(QTreeNode *node);

public:
  QTreeNode *Root;
  QuarternaryTree() { Root = NULL; }
  bool insert_vector(std::vector<std::string> &w); // used address to find pointer
  bool compare_vector_to_tree(std::vector<std::string> &v);

  // deleting the trees recursively.
  ~QuarternaryTree() {
    clearing();
    delete Root;
  }
};

void QuarternaryTree::clearing() {
  recursive_delete(Root);
} // for deleting recursive and passed root

void QuarternaryTree::recursive_delete(
    QTreeNode *node) // checking if the nodes are null,
{                    // then going on to recursive delete.
  if (node == NULL) {
    recursive_delete(node->child1);
    recursive_delete(node->child2);
    recursive_delete(node->child3);
    recursive_delete(node->child4);
    deleteNode(node);
  }
}

void QuarternaryTree::deleteNode(QTreeNode *node) // deletes nodes
{
  delete node;
  node = NULL;
}

bool QuarternaryTree::insert_vector(std::vector<std::string> &w) {
  for (auto i = 0; i < w.size();
       i++) {           // increment through each string in vector
    std::string temp = w[i]; // string to work with
    // this will be the pointer that navigates through the tree
    QTreeNode *currentNode = Root;
    for (auto n = 0; n < temp.size(); n++) {
      if (Root == NULL) {
        // create new BTreeNode, give it's data a value of z
        // because this will differentiate it
        Root = new QTreeNode();
        Root->Data = 'z';
        Root->child1 = NULL;
        Root->child2 = NULL;
        Root->child3 = NULL;
        Root->child4 = NULL;
        currentNode = Root;
      }
      if (temp[n] == 'a') {
        // if the value is not yet in the tree then create new node
        if (currentNode->child1 == NULL) {
          currentNode->child1 = new QTreeNode();
          currentNode->child1->Data = 'a';
          currentNode->child1->child1 = NULL;
          currentNode->child1->child2 = NULL;
          currentNode->child1->child3 = NULL;
          currentNode->child1->child4 = NULL;
        }
        // make sure to move down the tree
        currentNode = currentNode->child1;
      }
      if (temp[n] == 't') {
        // if the value is not yet in the tree then create new node
        if (currentNode->child2 == NULL) {
          currentNode->child2 = new QTreeNode();
          currentNode->child2->Data = 't';
          currentNode->child2->child1 = NULL;
          currentNode->child2->child2 = NULL;
          currentNode->child2->child3 = NULL;
          currentNode->child2->child4 = NULL;
        }
        currentNode = currentNode->child2; // make sure to move down the tree
      }
      if (temp[n] == 'c') {
        // if the value is not yet in the tree then create new node
        if (currentNode->child3 == NULL) {
          currentNode->child3 = new QTreeNode();
          currentNode->child3->Data = 'c';
          currentNode->child3->child1 = NULL;
          currentNode->child3->child2 = NULL;
          currentNode->child3->child3 = NULL;
          currentNode->child3->child4 = NULL;
        }
        currentNode = currentNode->child3; // make sure to move down the tree
      }
      if (temp[n] == 'g') {
        // if the value is not yet in the tree then create new node
        if (currentNode->child4 == NULL) {
          currentNode->child4 = new QTreeNode();
          currentNode->child4->Data = 'g';
          currentNode->child4->child1 = NULL;
          currentNode->child4->child2 = NULL;
          currentNode->child4->child3 = NULL;
          currentNode->child4->child4 = NULL;
        }
        currentNode = currentNode->child4; // make sure to move down the tree
      }
    }
    // double checking to make sure that currentnode will point to nothing
    currentNode->child1 = NULL;
    currentNode->child2 = NULL;
    currentNode->child3 = NULL;
    currentNode->child4 = NULL;
  }
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
        if (currentNode->child1 != NULL &&
            currentNode->child1->Data == temp[n]) {
          currentNode = currentNode->child1;
        } else {
          flag = false;
          break;
        }                          // if a then it will move down the tree
      } else if (temp[n] == 't') { // if the letter is t,
        if (currentNode->child2 != NULL &&
            currentNode->child2->Data == temp[n]) {
          currentNode = currentNode->child2;
        }
        // if the Lchild is not NULL AND the Rchild's data is r
        // then move on (double checking)
        else {
          flag = false;
          break;
        }                          // else make the flag false, break for loop
      } else if (temp[n] == 'c') { // if the letter is c
        if (currentNode->child3 != NULL &&
            currentNode->child3->Data == temp[n]) {
          currentNode = currentNode->child3;
        } else {
          flag = false;
          break;
        } // if the letter is c
        // then it will move down the tree
      } else if (temp[n] == 'g') {
        if (currentNode->child4 != NULL &&
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
