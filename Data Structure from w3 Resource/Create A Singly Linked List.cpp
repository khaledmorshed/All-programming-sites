#include<iostream>

using namespace std;

void insertion();
void print();

struct Node{

    int data;
    Node* next;
};

Node* head = NULL;
Node* lastNode;

void insertion(int value){
    Node* temp = new Node();

    temp->data = value;
    temp->next = NULL;

    if(head == NULL){

        head = temp;
        lastNode = temp;
        return;
    }

    lastNode ->next = temp;
    lastNode = temp;

}

void print(){

    Node* temp = head;
    cout<<endl<<"List is :"<<endl;
    while(temp != NULL){

        cout<<" Data : "<<temp->data<<endl;
        temp = temp->next;

    }
    cout<<endl;
}


int main(){

    int node, value;

    cout<<"Input number of nodes : ";

    cin>>node;
    cout<<endl;
    for(int i = 0; i < node; i++){

        cout<<"input data for node "<<i+1<<" : ";

        cin>>value;

        insertion(value);

    }

     print();

}
