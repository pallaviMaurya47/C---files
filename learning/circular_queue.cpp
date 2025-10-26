#include<iostream>
using namespace std;
class Circular_queue
{
  public:
    int front;
    int rear;
    int size;
    int *arr;
    Circular_queue(int size){
        this->size=size;
        arr=new int[size];
        rear=-1;
        front=-1;
    }

    void enqueue(int x){
        if((rear+1)%size ==front){
            cout<<"Overflow queue"<<endl;
            return;
        }
        if(front==-1){
            front=0;
        }
        rear=(rear+1)%size;
        arr[rear]=x;
        cout<<"element inserted!"<<endl;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Empty queue. Can't remove the element!"<<endl;
            return;
        }
        cout<<"Removed element:\n"<<arr[front]<<endl;
        if(front==rear){
            front=-1;
            rear=-1;
            
        }else{
            front=(front+1)%size;
        }
    }

    void display_elements(){
        if(isEmpty()){
            cout<<"Empty queue!"<<endl;
            return;
        }
        cout<<"displaying..."<<endl;
        int i=front;
        while(i<=rear){
            cout<<arr[i]<<" ";
            i=(i+1)%size;
        }
        cout<<endl;
    }

    bool isEmpty(){
        if(front==-1){
            return true;
        }
        return false;
    }
};

int main(){
    Circular_queue qu(4);
    qu.enqueue(1);
    qu.enqueue(2);
    qu.enqueue(3);
    qu.enqueue(4);
    qu.enqueue(5);
    qu.dequeue();
    qu.enqueue(5);
    qu.display_elements();
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    qu.enqueue(1);
}