#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
   int data;
   Node* next;
   Node(int data){
    this->data=data;
    next=nullptr;
   }
   void createNode(){
    Node* head=new Node(5);
    Node* temp=new Node(6);
    head->next=temp;
    cout<<head->data<<endl;
    cout<<head->next->data;
   }
};

int main(){
   Node* obj=new Node(5);
   obj.createNode();
}