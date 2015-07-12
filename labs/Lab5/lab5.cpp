#include <iostream>
#include <stack>

using namespace std;

class TreeNode
{
  public:
    char Data;
    TreeNode *Lchild;
    TreeNode *Rchild;
};

class BinaryTree
{
  public:
    TreeNode *Root;
  public:
    BinaryTree() { Root = nullptr; }       //constructor
    void Preorder();
    void Inorder();
    void Postorder();
    void PreorderR(TreeNode*);
    void InorderR(TreeNode*);
    void PostorderR(TreeNode*);
    TreeNode* Find_Node_Inorder(char D);
    void InsertNode(char Val);
};

// 1. finish up the preorder, look at slides
void BinaryTree::Preorder()
{
  TreeNode * Tmp = Root;
  stack<TreeNode*> S;
  while (true) {
    while (Tmp != nullptr) {
      std::cout << Tmp->Data;
      S.push(Tmp);
      Tmp = Tmp->Lchild;
    }
    if (S.empty()) {
      return;
    }
    Tmp = S.top();
    S.pop();
    Tmp = Tmp->Rchild;
  }
}

void BinaryTree::Inorder()
{
  TreeNode * Tmp = Root;
  stack<TreeNode*> S;
  while (true) {
    //traverse left until its nullptr & push
    while (Tmp != nullptr) {
      S.push(Tmp);
      Tmp = Tmp->Lchild;
    }
    //if stack is empty stop the process
    if (S.empty()) {
      return;
    }
    //if not empty, pop 1 and go right
    Tmp = S.top();
    S.pop();
    std::cout << Tmp->Data;
    Tmp = Tmp->Rchild;
  }
}

void BinaryTree::Postorder()
{
  TreeNode * Tmp = Root;
  stack<TreeNode*> S;
  //stores nodes
  stack<char> F;
  //stores flag
  char flag;
  //'L' or 'R'
  while (1) {
    //traverse left until its nullptr & push
    while (Tmp != nullptr) {
      S.push(Tmp);
      F.push('L');
      Tmp = Tmp->Lchild;
    }
    //if stack is empty stop the process
    if (S.empty()) { 
      return;
    } else {
      Tmp = S.top();
      S.pop();
      //pop node
      flag = F.top();
      F.pop();
      //pop flag value
      if (flag == 'R') {
        std::cout << Tmp->Data;
        Tmp = nullptr;
      } else {  //if flag is 'L'
        S.push(Tmp);
        //push Tmp with 'R'
        F.push('R');
        //move to right
        Tmp = Tmp->Rchild;
      }
    }
  }
}

//#2 Recursive version of PREORDER
void BinaryTree::PreorderR(TreeNode*)
{
  if (Root != nullptr) {
    std::cout << Root->Data; /* D         D      */
    PreorderR(Root->Lchild); /* L        / \     */
    PreorderR(Root->Rchild); /* R       L   R    */
  }
}

//#3 Recursive version of INORDER
void BinaryTree::InorderR(TreeNode*)
{
  if (Root != nullptr) {
    InorderR(Root->Lchild);  /* L         D      */
    std::cout << Root->Data; /* D        / \     */
    InorderR(Root->Rchild);  /* R       L   R    */
  }
}

//#4 Recursive version of POSTORDER
void BinaryTree::PostorderR(TreeNode*)
{
  if (Root != nullptr) {
    PreorderR(Root->Lchild); /* L         D      */
    PreorderR(Root->Rchild); /* R        / \     */
    std::cout << Root->Data; /* D       L   R    */
  }
}

//#5 in the INORDER fashion look for node where Temp->Data==D and return node
TreeNode* BinaryTree::Find_Node_Inorder(char D)
{
  TreeNode * Tmp = Root;
  stack<TreeNode*> S;
  while (true) {
    // Go Left until NULL & push
    while (Tmp != nullptr) {
      S.push(Tmp);
      Tmp = Tmp->Lchild;
    }
    // If Stack is empty, back out
    if(S.empty()) {
      return nullptr;
    }
    // Check Data
    Tmp = S.top();
    S.pop();
    if (Tmp->Data == D) {
      return Tmp;
    }
    // Go right & start going left again
    Tmp = Tmp->Rchild;
  }
}

//#6 Write the insertNode function
void BinaryTree::InsertNode(char Val)
{
  // Pointer to a new node
  // Pointer to traverse the tree
  TreeNode * newNode, * nodePtr;
  // Create a new node
  newNode = new TreeNode;
  newNode->Data = Val;
  newNode->Lchild = newNode->Rchild = nullptr;
  if (!Root) {
    // Is the tree empty?
    Root = newNode;
  } else {
    nodePtr = Root;
    while (nodePtr != nullptr) {
      if (Val < nodePtr->Data) {
        if (nodePtr->Lchild) {
          nodePtr = nodePtr->Lchild;
        } else {
          nodePtr->Lchild = newNode;
          break;
        }
      } else if (Val > nodePtr->Data) {
        if (nodePtr->Rchild) {
          nodePtr = nodePtr->Rchild;
        } else {
          nodePtr->Rchild = newNode;
          break;
        }
      } else {
        std::cout << "Duplicate value found in tree.\n";
        break;
      }
    }
  }
}

/************************************* MAIN FUNCTION *************************************/
int main()
{
  //#7 Create a binary tree call b and insert nodes m,a,q
  //Create a binary tree called 'b'
  BinaryTree * b = new BinaryTree();
  char m = 'm', a = 'a', q = 'q';
  //insertNodes 'm','a','q' in this specific order
  b->InsertNode(m);
  b->InsertNode(a);
  b->InsertNode(q);
  TreeNode * nodePtr = new TreeNode;
  //#8 call recurisve and non recursive functions of order types
  //call both postorderR and postorder
  std::cout << "Postorder: ";
  b->Postorder();
  std::cout << std::endl;
  std::cout << "PostorderR: ";
  //b->PostorderR(nodePtr);
  std::cout << std::endl;

  //call both inorderR and inorder
  std::cout << "Inorder: ";
  b->Inorder();
  std::cout << std::endl;
  std::cout << "InorderR: ";
  //b->InorderR(nodePtr);
  std::cout << std::endl;

  //call both preorderR and preorder
  std::cout << "Preorder: ";
  b->Preorder();
  std::cout << std::endl;
  std::cout << "PreorderR: ";
  //b->PreorderR(nodePtr);
  std::cout << std::endl;
  std::system("pause");
  return 1;
}
