#ifndef QUARTERNARYTREE.H
#define QUARTERNARYTREE .H

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
  bool insert_vector(vector<string> &w); // used address to find pointer
  bool compare_vector_to_tree(vector<string> &v);
};
#endif // QUARTERNARYTREE.H

