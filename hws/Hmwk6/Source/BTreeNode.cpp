#include "BTreeNode.h"

BTreeNode::BTreeNode(const char val) : BTreeNode() {
  Data = val;
}

BTreeNode::BTreeNode(){
  BTreeNode->Lchild = nullptr;
  BTreeNode->Rchild = nullptr;
}

