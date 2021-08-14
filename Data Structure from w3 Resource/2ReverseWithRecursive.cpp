#include<iostream>


using namespace std;

void insertion(int);

struct Node{

    int data;
    Node* next;

};

Node* head = NULL, *prevtemp;

void insertion(int x){

    Node* temp = new Node();

    temp->data = x;
    temp->next = NULL;

    if(head == NULL){

        head = temp;
        prevtemp = temp;
        return;
    }

    prevtemp->next = temp;
    prevtemp = temp;

}

void ForwardPrint(Node* f){

    if(f == NULL){

        return;
    }

    cout<<f->data<<endl;

    ForwardPrint(f->next);

}

void ReversePrint(Node* p){


    if(p == NULL){

        return;
    }

    ReversePrint(p->next);

    cout<<p->data<<endl;

}

int main(){

    int n, x;

    cout<<"Input the number of nodes : ";
    cin>>n;

    for(int i = 0; i < n; i++){

        cout<<"input the value of node : ";
        cin>>x;
        insertion(x);
    }
    cout<<"Reverse List--->"<<endl;
    ReversePrint(head);
    cout<<"Forward List--->"<<endl;
    ForwardPrint(head);

}
