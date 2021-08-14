#include<iostream>
#include<string.h>
#include<stack>

using namespace std;

struct Node{

    int data;
    Node* next;

};

Node* head = NULL;;

void insert(int x){

    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

    if(head == NULL){

        temp->next = head;
        head = temp;
        return;
    }

    Node* temp2 = head;

    while(temp2->next != NULL){

        temp2 = temp2->next;
    }

    temp2->next = temp;

}

void Reverse(){

    if(head == NULL){
        return;
    }

    stack<Node*>s;

    Node* temp = head;
    while(temp != NULL){

        s.push(temp);
        temp = temp->next;
    }

    temp = s.top();
    head = temp;
    s.pop();

    while(!s.empty()){

        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;

}

void print(){

    Node* temp = head;
    cout<<"List is :"<<endl;
    while(temp != NULL){

        cout<<temp->data<<endl;;
        temp = temp->next;

    }
    cout<<endl;
}


int main(){

        head = NULL;
    int n, x;

    cout<<"How many numbers want to insert : "<<endl;

    cin>>n;

    for(int i = 0; i < n; i++){
        cout<<endl<<"Enter the number : ";
        cin >> x;

        insert(x);

    }

    Reverse();
     print();

}

