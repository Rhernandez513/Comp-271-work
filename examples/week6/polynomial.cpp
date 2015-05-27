#include <iostream>

class PolyNode
{
    public:
        int coef;
        int exp;
        PolyNode *link;
};

class Poly
{
    private:
        PolyNode *Head, *Tail;
    public:
        Poly() {Head=Tail=NULL;}        //constructor
        void Create();
        PolyNode* GetNode();
        void Append(PolyNode *NewNode);
        void Display();
        Poly PolyMult(Poly A);
        Poly PolyAdd(Poly A);
        void Insert(PolyNode*);
        int Evaluate(int val);
};

using namespace std;

void Poly::Create()
{
    char ans;
    PolyNode *NewNode;
    while(1)
    {
        cout << "Any term to be added (Y/N)? ";
        cin >> ans;
        if(ans=='N' || ans=='n')
            break;
        NewNode=GetNode();
        if(Head==NULL)
        {
            Head=NewNode;
            Tail=NewNode;
        }
        else
            Append(NewNode);
    }
}

void Poly::Append(PolyNode *NewNode)
{
    if(Tail==NULL)
        Head=Tail=NewNode;
    else
    {
        Tail->link=NewNode;
        Tail=NewNode;
    }
}

PolyNode* Poly::GetNode()
{
    PolyNode *NewNode;
    NewNode=new PolyNode;
    if(NewNode==NULL)
    {
        cout << "Error in memory allocation\n";
    }
    cout << "Enter coefficient and exponent ";
    cin >> NewNode->coef;
    cin >> NewNode->exp;
    NewNode->link=NULL;
    return NewNode;
}

void Poly::Display()
{
    PolyNode *tmp=Head;
    while(tmp!=NULL)
    {
        cout << tmp->coef << "x^" << tmp->exp;
        tmp=tmp->link;
        if(tmp!=NULL) cout << " + ";
    }
    cout << endl;
}

int Poly::Evaluate(int val)
{
    int j,result=0,Power;
    PolyNode *tmp=Head;
    while(tmp!=NULL)
    {
        Power=1;
        for(j=1; j<=tmp->exp; j++)
            Power*=val;
        result+=(tmp->coef)*Power;
        tmp=tmp->link;
    }
    return result;
}


int main()
{
    Poly p;
    p.Create();
    p.Display();
    cout << "When x=2, the solution= " << p.Evaluate(2) << endl;
    return 0;
}
