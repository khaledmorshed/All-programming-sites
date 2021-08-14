
#include<iostream>

using namespace std;

void insertion();
void print();

struct Node{

    int data;
    Node* next;
};

Node* ReverseWithIterative(Node* head);
void ReversePrint(Node* head);



Node* head = NULL;
Node* Beftemp;

Node* insertion(Node* head,int value){


    Node* temp = new Node();



    temp->data = value;
    temp->next = NULL;

    if(head == NULL){

        head = temp;
        Beftemp = temp;
        return head;
    }

    Beftemp ->next = temp;
    Beftemp = temp;
    return head;

}

Node* ReverseWithIterative(Node* head){

    Node *current, *prev, *next;

    current = head;
    prev = NULL;

    while(current != NULL){

        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;

}

void print(Node* head){

    Node* temp = head;
    cout<<endl<<"List is :"<<endl;
    while(temp != NULL){

        cout<<" Data : "<<temp->data<<endl;
        temp = temp->next;

    }
    cout<<endl;
}

void ReversePrint(Node* head){

    Node* temp = head;
    cout<<endl<<"List is Reversed:"<<endl;
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

        head = insertion(head,value);

    }

     print(head);

     head = ReverseWithIterative(head);
     ReversePrint(head);

}
