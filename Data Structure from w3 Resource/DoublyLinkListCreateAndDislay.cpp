#include<iostream>

using namespace std;

struct Node{

    int data;
    Node* next;
    Node* prev;

};

void insertion(int x);
Node* GetnewNode(int x);
void print();

Node* head = NULL;


int main(){

    int n, x;

    cout<<"input number of nodes of doubly link list : ";
    cin>>n;

    for(int i = 0; i < n; i++){

        cout<<"input value of node : ";
        cin>>x;

        insertion(x);
    }
    print();
}


void insertion(int x){

    Node* newnode = GetnewNode(x);

    if(head == NULL){

        head = newnode;
        return;
    }

    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

Node* GetnewNode(int x){

    Node* temp = new Node();

    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}

void print(){

    Node* temp = head;
    cout<<endl<<"List are :"<<endl;
    while(temp != NULL){

        cout<<temp->data<<endl;
        temp = temp->next;
    }

}
