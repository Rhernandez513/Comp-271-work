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
    BinaryTree() {Root=NULL;}       //constructor
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
    TreeNode * Tmp=Root;
    stack<TreeNode*> S;
    while(1)
    {
	
      
    }
}

void BinaryTree::Inorder()
{
    TreeNode * Tmp=Root;
    stack<TreeNode*> S;
    while(1)
    {
        //traverse left until its NULL & push
        while(Tmp!=NULL)
        {
            S.push(Tmp);
            Tmp=Tmp->Lchild;
        }
        //if stack is empty stop the process
        if(S.empty()) return;
        
        //if not empty, pop 1 and go right
        Tmp=S.top();
        S.pop();
        cout << Tmp->Data;
        Tmp=Tmp->Rchild;
    }
}

void BinaryTree::Postorder()
{
    TreeNode * Tmp=Root;
    stack<TreeNode*> S;		//stores nodes
    stack<char> F;	//stores flag
    char flag;	//íLí or ëRí
    while(1)
    {
        //traverse left until its NULL & push
        while(Tmp!=NULL)
        {
            S.push(Tmp);
            F.push('L');
            Tmp=Tmp->Lchild;
        }
        //if stack is empty stop the process
        if(S.empty()) return;
        else
        {
            Tmp=S.top();
            S.pop();		//pop node
            flag=F.top();
            F.pop();		//pop flag value
            if(flag=='R')
            {
                cout << Tmp->Data;
                Tmp=NULL;
            }
            else	//if flag is ëLí
            {
                S.push(Tmp);
                F.push('R');	//push Tmp with ëRí
                Tmp=Tmp->Rchild;	//move to right
            }
        }
    }
}

//#2 Recursive version of PREORDER
void BinaryTree::PreorderR(TreeNode*)
{
	//write recursive version of preorder
}

//#3 Recursive version of INORDER
void BinaryTree::InorderR(TreeNode*)
{
   //write recursive version of inorder
}

//#4 Recursive version of POSTORDER
void BinaryTree::PostorderR(TreeNode*)
{
  //write recursive version  of postorderf
}

//#5 in the INORDER fashion look for node where Temp->Data==D and return node
TreeNode* BinaryTree::Find_Node_Inorder(char D)
{
    TreeNode * Tmp=Root;
    stack<TreeNode*> S;
    while(1)
    {
       	//traverse left until its NULL & push
       	//if not empty, pop 1 and go right
      	//OLD code: cout << Tmp->Data; should do a comparison instead
    
    }
}

//#6 Write the insertNode function
void BinaryTree::InsertNode(char Val)
{
    TreeNode *newNode,	// Pointer to a new node
    *nodePtr;	// Pointer to traverse the tree
    
    // Create a new node called newNode
    //make that nodes Data variable equal to VAL
    //set newNode Lchild and Rchild = NULL
    
    if (!Root)	// Is the tree empty?
        Root = newNode;
    else
    {
        nodePtr = Root;
        while (nodePtr != NULL)
        {
            if () //check for < than
            {
               //break;
            }
            else if () //check for > than
            {
				br//eak;
            }
            else
            {
                cout << "Duplicate value found in tree.\n";
                break;
            }
        }
    }
}



/************************************* MAIN FUNCTION *************************************/
int main()
{
    //#7 Createa a binary tree call b and isnsert nodes m,a,q
    //Create a binary tree called 'b'
    //insertNodes 'm','a','q' in this specific order

    //#8 call recurisve and non recursive functions of order types
    cout << "Postorder: ";
    //call both postorderR and postorder
    cout << endl;
    
    cout << "Inorder: ";
     //call both inorderR and inorder
    cout << endl;
    
    cout << "Preorder: ";
    //call both preorderR and preorder
    cout << endl;
    
    return 0;
}
