#include "..\\Headers\\QTreeNode.h"

using namespace hw6;

QTreeNode::QTreeNode()
 : child1(nullptr)
 , child2(nullptr)
 , child3(nullptr)
 , child4(nullptr)
{
}
 
QTreeNode::QTreeNode(const char val)
 : Data(val)
 , child1(nullptr)
 , child2(nullptr)
 , child3(nullptr)
 , child4(nullptr)
{
}

// Deletes this node and All Children Recursively
QTreeNode::~QTreeNode() {
  if(child1) delete child1;
  if(child2) delete child2;
  if(child3) delete child3;
  if(child4) delete child4;
}
