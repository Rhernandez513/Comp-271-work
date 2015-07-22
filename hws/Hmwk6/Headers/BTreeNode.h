#ifndef BTREENODE_H
#define BTREENODE_H

class BTreeNode {
private:
  char Data;
public:
  BTreeNode() { }
  BTreeNode(const char val) : BTreeNode() { }
  ~BTreeNode() { }
  
  BTreeNode *Lchild;
  BTreeNode *Rchild;

  char BTreeNode::GetData() {
};
#endif // BTREENODE.H
