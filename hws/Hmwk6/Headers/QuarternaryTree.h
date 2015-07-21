#ifndef QUARTERNARYTREE_H
#define QUARTERNARYTREE_H
#include "QTreeNode.h"
#include <vector>

class QuarternaryTree // created a class for the quarternary tree
{
private:
  void clearing();
  void recursive_delete(QTreeNode *node);
  void deleteNode(QTreeNode *node);

public:
  QTreeNode *Root;
  QuarternaryTree();
  ~QuarternaryTree();
  bool insert_vector(std::vector<std::string> &w); // used address to find pointer
  bool compare_vector_to_tree(std::vector<std::string> &v);
};
#endif // QUARTERNARYTREE_H

