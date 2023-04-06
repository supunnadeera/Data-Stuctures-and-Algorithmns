#include <iostream>
#include <chrono>
using namespace std;

struct Node {
    int data;
    Node *link;
};

struct LinkedList{

    Node * head = NULL;
    int length = 0;

    void push(int data){
        if (head == NULL){
            Node * temp;
            temp = new Node;
            temp->data = data;
            temp->link = NULL;
            head = temp; 
            length++;
        }
        else{
            Node * temp;
            temp = new Node;
            temp->data = data;
            temp->link = head;
            head = temp;
            length++;
        }
    }
    void pop(){
        if (head == NULL){
            cout<<"stack underflow"<<endl;
        }
        else{
            head = head->link;
            length --;
        }
        
    }
    void isEmpty(){
        if(head == NULL){
            cout<<"stack is empty"<<endl;
        }else{
            cout<<"stack is not empty"<<endl;
        }
    }
    void stackTop(){
        if (head != NULL){
            cout<<head->data;

        }else{
            cout<<"stack is empty"<<endl;
        }
    }

    void display(){
        if (head == NULL){
            cout<<"[]"<<endl;
        }
        else{
            Node * temp = head;
            cout<< "[";
            while (temp != NULL){
                cout<<temp->data<<", ";
                temp = temp->link;
            }
             cout<< "]"<<endl;
        }
    }


};

int main (){
    LinkedList *linkedlist;
    linkedlist = new LinkedList;

    auto start = chrono::steady_clock::now();


    linkedlist->push(8);
    linkedlist->push(10);
    linkedlist->push(5);
    linkedlist->push(11);
    linkedlist->push(15);
    linkedlist->push(23);
    linkedlist->push(6);
    linkedlist->push(18);
    linkedlist->push(20);
    linkedlist->push(17);
    linkedlist->display();
    linkedlist->pop();
    linkedlist->pop();
    linkedlist->pop();
    linkedlist->pop();
    linkedlist->pop();
    linkedlist->display();
    linkedlist->push(4);
    linkedlist->push(30);
    linkedlist->push(3);
    linkedlist->push(1);
    linkedlist->display();

    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ms" << endl;

}
