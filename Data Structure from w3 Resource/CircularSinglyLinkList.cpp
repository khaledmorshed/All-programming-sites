#include<iostream>

using namespace std;

struct Node{

    int data;
    Node* next;
};

void insertion(int x);
void print();

Node* head = NULL, *prevnode;

int main(){

    int n, x;

    cout<<"Input number of nodes : ";
    cin>>n;

    for(int i = 0; i < n; i++){

        cout<<"Input value of node : ";
        cin>>x;
        insertion(x);
    }

    print();

}

void insertion(int x){

    Node* temp = new Node();
    temp->data = x;
    //temp->next = NULL;

    if(head == NULL){

        head = temp;
        prevnode = head;
        temp->next = temp;
       // cout<<endl<<"circular : "<<temp->next<<endl;
        return;
    }

    prevnode->next = temp;
    prevnode = temp;
    prevnode->next = head;
   // cout<<endl<<"circular : "<<prevnode->next<<endl;

}


void print(/*This is interesting because it will not stop*/){

    Node* temp = head;
    cout<<"Circular list is : "<<endl;
    while(temp != NULL){

        cout<<temp->data<<endl;
        temp = temp -> next;

    }

}
