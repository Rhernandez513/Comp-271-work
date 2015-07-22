#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "BTreeNode.h"
#include <vector>

class BinaryTree {
public:
  BTreeNode *Root;
  BinaryTree() { }
  bool insert_vector(std::vector<std::string> &w);
  bool compare_vector_to_tree(std::vector<std::string> &v);
  BTreeNode * CreateNode(const char val);
};
#endif // BINARYTREE.H
