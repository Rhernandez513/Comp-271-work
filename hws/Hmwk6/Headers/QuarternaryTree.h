#ifndef QUARTERNARYTREE_H
#define QUARTERNARYTREE_H
#include "QTreeNode.h"
#include <vector>
#include <string>

class QuarternaryTree // created a class for the quarternary tree
{
public:
  QuarternaryTree();
  ~QuarternaryTree();

  QTreeNode *Root;
  QTreeNode * CreateNode(const char val);

  // used address to find pointer
  bool insert_vector(std::vector<std::string> &w);
  bool compare_vector_to_tree(std::vector<std::string> &v);
};
#endif // QUARTERNARYTREE_H

