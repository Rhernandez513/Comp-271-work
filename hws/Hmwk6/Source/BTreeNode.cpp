#include "..\\Headers\\BTreeNode.h"

using namespace hw6;

BTreeNode::BTreeNode()
 : Lchild(nullptr)
 , Rchild(nullptr)
{
}

BTreeNode::BTreeNode(const char val)
 : Lchild(nullptr)
 , Rchild(nullptr)
 , Data(val)
{
}

BTreeNode::~BTreeNode() {
  if (Lchild) delete Lchild;
  if (Rchild) delete Rchild;
}

char BTreeNode::GetData() {
  return this->Data;
}
