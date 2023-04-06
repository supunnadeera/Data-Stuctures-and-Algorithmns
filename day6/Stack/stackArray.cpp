#include <iostream>
#include <chrono>
using namespace std;

int n;
int *stack,top=-1;

void Push(int val){
    if(top+1>n){
        cout<<"stack overflow"<<endl;
        return;
    }else{
        top++;
        stack[top] = val;
    }
    
}

void Display(){
    if(top>=0){
        cout<<"[";
        for(int i = 0; i<=top;i++){
            cout<<stack[i]<<", ";
        }
        cout<<"]"<<endl;
    }else{
        cout<<"[]"<<endl;
    }
}

void  Pop(){
    if(top<=-1){
        cout<<"stack underflow"<<endl;
    }else{
        top--;
    }


}
void isEmpty(){
    if (top <= -1){
        cout<<"stack is empty"<<endl;
    }else{
        cout<<"stack is not empty"<<endl;
    }
}

void isFull(){
    if (top >= 200){
        cout<<"stack is full"<<endl;
    }else{
        cout<<"stack is not empty"<<endl;
    }
}

int StackTop(){
    return stack[top];
}


int main(){
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    stack = new int[n];

    auto start = chrono::steady_clock::now();

    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Display();
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    Display();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    Display();
    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ms" << endl;
}