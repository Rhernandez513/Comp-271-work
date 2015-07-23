#ifndef BTREENODE_H
#define BTREENODE_H

namespace hw6 {
class BTreeNode {
private:
  char Data;
public:
  BTreeNode();
  BTreeNode(const char val);
  ~BTreeNode();
  
  BTreeNode *Lchild;
  BTreeNode *Rchild;

  char GetData();
};
}
#endif // BTREENODE.H
