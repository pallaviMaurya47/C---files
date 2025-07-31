#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
       int data;
       Node* next;
    public:
      Node(int data){
        this->data=data;
        next=nullptr;
      }
      Node* create(vector<int>vec){
        Node* head=new Node(vec[0]);
        Node* t=head;
        int n=vec.size();
        for(int i=1;i<n;i++){
            Node* temp=new Node(vec[i]);
            t->next=temp;
            t=temp;
        }

        return head;
      }
      void display(Node* head){
        cout<<"Here is linked list:"<<endl;
        Node* p=head;
        while(p){
           cout<<p->data<<" ";
           p=p->next;
        }
        cout<<endl;
      }

      //CRUD Operations- UPDATE:-in begin,last
      Node* insertion_in_beginning(Node* head){
           
           int n;
           cin>>n;
           Node* new_node=new Node(n);
           new_node->next=head;
           head=new_node;
           return head;
      }

      Node* insert_pos(Node* head, int pos){
          Node* p=head;
          cout<<"enter a number:"<<endl;
          int x;
          cin>>x;
          Node* temp=new Node(x);
          int count=1;
          while(count<=pos){
            p=p->next;
            count++;
          }
          Node* q=p->next;
          p->next=temp;
          temp->next=q;
          return head;
      }
    Node* insert_in_last(Node* head){
           cout<<"Enter number in last:"<<endl;
           int n;
           cin>>n;
           Node* p=head;
           Node* last=new Node(n);
           while(p->next!=nullptr){
            p=p->next;
           }
           p->next=last;
           last->next=nullptr; //null ptr not needed here;
           return head;
      }

      //delete Operation
      Node* delete_begin(Node* head){
        if(head==nullptr){
          return nullptr;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
      }
      Node* del_at_last(Node* head){
        if(head==nullptr) {
          return head;
        }
        Node* p=head;
        while(p->next->next !=nullptr){
          p=p->next;
        }
        Node* temp=p->next;
        p->next=nullptr;
        delete temp;
        return head;
      }

      Node* del_at_pos(Node* head, int pos){
        if(head==nullptr) return nullptr;
        Node* ptr=head;
        int current=1;
        while(current<pos-1){
          ptr=ptr->next;
          current++;
        }
       Node* temp=ptr->next;
       ptr->next= ptr->next->next;
       temp->next=nullptr;
       delete temp;
       return head;

      }
};
int main(){

    Node obj(0);
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    Node* head=obj.create(vec);
    obj.display(head);

    head=obj.insertion_in_beginning(head);
    obj.display(head);
    head=obj.insert_in_last(head);
    obj.display(head);

    head=obj.insert_pos(head,3);
    obj.display(head);

    head=obj.delete_begin(head);
    obj.display(head);
    head=obj.del_at_last(head);
    obj.display(head);
    cout<<"Enter the position of node to be deleted:"<<endl;
    int pos;
    cin>>pos;
    head=obj.del_at_pos(head, pos);
    obj.display(head);
}