#ifndef QUARTERNARYTREE_H
#define QUARTERNARYTREE_H
#include "QTreeNode.h"
#include <vector>
#include <string>

namespace hw6 {
class QuarternaryTree // created a class for the quarternary tree
{
public:
  QuarternaryTree();
  ~QuarternaryTree();

  QTreeNode *Root;
  QTreeNode * CreateNode(const char val);
  QTreeNode * AppendNode(QTreeNode * parentNode, char val);

  bool CheckCharsInStr(std::string inStr);
  bool insert_vector(std::vector<std::string> &w);
  bool compare_vector_to_tree(std::vector<std::string> &v);
};
}
#endif // QUARTERNARYTREE_H

