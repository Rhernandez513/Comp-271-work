#include "BTreeNode.h"

BTreeNode::BTreeNode()
 : Lchild(nullptr)
 , Rchild(nullptr)
{
}

BTreeNode::BTreeNode(const char val)
  : BTreeNode()
  , Data(val)
{
}

BTreeNode::~BTreeNode() {
  if (Lchild) delete Lchild;
  if (Rchild) delete Rchild;
}

BTreeNode::GetData() {
  return this->Data;
}
