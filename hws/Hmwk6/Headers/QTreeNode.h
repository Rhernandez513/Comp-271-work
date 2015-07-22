#ifndef QTREENODE_H
#define QTREENODE_H

class QTreeNode {
public:
  char Data;
  QTreeNode() { }
  QTreeNode(const char val) : QTreeNode() { }
  ~QTreeNode() { }

  QTreeNode *child1;
  QTreeNode *child2;
  QTreeNode *child3;
  QTreeNode *child4;
};
#endif // QTREENODE_H

