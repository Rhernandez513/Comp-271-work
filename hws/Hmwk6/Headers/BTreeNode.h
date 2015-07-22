#ifndef BTREENODE_H
#define BTREENODE_H

class BTreeNode {
public:
  BTreeNode() { }
  BTreeNode(const char val) { }
  char Data;
  BTreeNode *Lchild;
  BTreeNode *Rchild;
};
#endif // BTREENODE.H
