#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "BTreeNode.h"
#include <vector>
#include <string>

class BinaryTree {
public:
  BTreeNode *Root;
  BinaryTree() { }
  ~BinaryTree() { }
  BTreeNode * CreateNode(const char val);
  BTreeNode * AppendNode(BTreeNode * parentNode, char val);
  bool CheckCharsInStr(std::string temp);
  bool insert_vector(std::vector<std::string> &w);
  bool compare_vector_to_tree(std::vector<std::string> &v);
};
#endif // BINARYTREE.H

