#include<iostream>


using namespace std;

void insertion(int);

struct Node{

    int data;
    Node* next;

};

void insertion(int x);
void ForwardPrint(Node* f);
void ReversePrint(Node* p);
void ReverseList(Node* p);


Node* head = NULL, *prevtemp;

int main(){

    int n, x;

    cout<<"Input the number of nodes : ";
    cin>>n;

    for(int i = 0; i < n; i++){

        cout<<"input the value of node : ";
        cin>>x;
        insertion(x);
    }

    cout<<"Forward List--->"<<endl;
    ForwardPrint(head);

    ReverseList(head);

    cout<<"Reverse List--->"<<endl;
    ReversePrint(head);


}



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


void ReverseList(Node* p){

    if(p->next == NULL){

        head = p;
        return;
    }

    ReverseList(p->next);

    Node* q = p->next;
    q->next = p;
    p->next = NULL;

}

void ForwardPrint(Node* f){

    if(f == NULL){

        return;
    }

    cout<<f->data<<endl;

    ForwardPrint(f->next);

}

void ReversePrint(Node* head){

    Node* temp = head;

    while(temp != NULL){

        cout<<" Data : "<<temp->data<<endl;
        temp = temp->next;

    }
    cout<<endl;
}









