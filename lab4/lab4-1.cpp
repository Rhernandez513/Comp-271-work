#include <iostream>

class Node
{
  public:
    int data;
    Node * link;
};

class Llist
{
  private:
    Node * Head, * Tail;
  public:
    Llist();
    void Append(Node * NewNode);
    void Insert_at_Pos(Node * NewNode, int position);
    void DeleteNode(int position);
    void show_nodes();
    Node * search_for_node(int data);
    int length_list();
};

using namespace std;

Llist::Llist()
{
  this->Head = nullptr;
}

void Llist::Append(Node * NewNode)
{
  if (this->Head  ==  nullptr) {
    this->Head = NewNode;
    this->Tail = NewNode;
  } else {
      this->Tail->link = NewNode;
      this->Tail = NewNode;
  }
}

void Llist::Insert_at_Pos(Node * NewNode, int position)
{
  Node *temp = this->Head;
  if (position  ==  1) {   //we will insert at the first position
    NewNode->link = temp;
    this->Head = NewNode;           //update the head
  } else {
     int flag = 1;
     for (int count = 1; count != (position - 1); count++) {
       temp = temp->link;
       if (temp == nullptr) {
         flag = 0;
         std::cout << "Position not found.\n";
         break;
        }
      }
      if (flag == 1) {
        NewNode->link = temp->link;
        temp->link = NewNode;
      }
  }
}

void Llist::DeleteNode(int position)
{
  Node *temp = this->Head;
  if (position == 1) {   //we will delete the first node
      this->Head = temp->link;
      delete temp;           //delete the node
  } else {
      int flag = 1;
      Node *curr;
     for (int count = 1; count != (position - 1); count++) {
       temp = temp->link;
       if (temp == nullptr) {
         flag = 0;
         std::cout << "Position not found.\n";
         break;
        }
      }
      if (flag == 1) {
        curr = temp->link;
        temp->link = curr->link;
        delete curr;
      }
  }
}

void Llist::show_nodes()
{
  int i = 1;
  Node * temp;
  temp = this->Head;
  std::cout << i << "\t" << temp->data << "\n";
  i++;
  while (temp->link != nullptr) {
    temp = temp->link;
    std::cout << i << "\t" << temp->data << "\n";
    i++;
  }
}

/******************* Week 6, Exercise 1 *******************/
/// <summary> Finds a Node </summary>
/// <params> Integer to search for </params>
/// <returns> Node that matches data member </returns>
Node * Llist::search_for_node(int data)
{
  Node * temp = this->Head;
  for (int i = 0; temp != nullptr; i++) {
    if (temp->data == data) { 
      break;
    }
    temp = temp->link;
  }
  return temp;
}

/// <summary> Finds the Length of the Linked List </summary>
/// <returns> Position of data member </returns>
int Llist::length_list()
{
  Node * temp = this->Head;
  int count = 0;
  while (temp->link != nullptr) {
    temp = temp->link;
    count++;
  }
  return count;
}

/******************* Week 6, Exercise 1 *******************/

int main()
{
  Llist x;                //create the linked list

  //create a node to add to list
  Node *node1 = new Node;
  node1->data = 10;
  node1->link = nullptr;
  x.Append(node1);

  //create a node to add to list
  Node *node2 = new Node;
  node2->data = 5;
  node2->link = nullptr;
  x.Append(node2);
  x.show_nodes();

  //create a node to add to list at 2nd position
  Node *node3 = new Node;
  node3->data = 1;
  node3->link = nullptr;
  x.Insert_at_Pos(node3,2);
  x.show_nodes();

  //test the length_list function
  std::cout << "The list has " << x.length_list() << " elements." << std::endl;
  std::cout << std::endl;

  //test search_for_node function
  Node * temp;
  temp = x.search_for_node(1);
  if (temp != nullptr) {
    std::cout << "I found " << temp->data << std::endl;
  }

  //delete a node and test the length_list function again
  x.DeleteNode(2);
  x.show_nodes();
  std::cout << "The list has " << x.length_list() << " elements." << std::endl;

  //test search_for_node function --> Should not find it; it is looking for the deleted node
  temp = x.search_for_node(1);
  if (temp != nullptr) {
    std::cout << "I found " << temp->data << std::endl;
  } else {
    std::cout << "Looks like I didn't find anything." << std::endl;
  }

  return 0;
}

