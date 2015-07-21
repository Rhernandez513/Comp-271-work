#include "BTreeNode.h"
#ifndef BINARYTREE.H
#define BINARYTREE.H

class BinaryTree {
public:
  BTreeNode *Root;
  BinaryTree();
  bool insert_vector(std::vector<string> &w);
  bool compare_vector_to_tree(std::vector<string> &v);
};
#endif // BINARYTREE.H
