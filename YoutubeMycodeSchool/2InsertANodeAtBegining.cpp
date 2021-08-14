#include<iostream>

using namespace std;

struct Node{

    int data;
    Node* next;
};


struct Node* head;

//insert value at begining
Node* insrt(Node* head, int x){

    Node* temp = new Node();
    temp -> data = x;
    temp -> next = head;
    head = temp;

    return head;
}

void print(Node* head){

    Node* temp = head;
    cout<<"List is :"<<endl;
    while(temp != NULL){

        cout<<&temp<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

      Node*  head = NULL;
    int n, x;

    cout<<"How many numbers want to insert : "<<endl;

    cin>>n;

    for(int i = 0; i < n; i++){
        cout<<endl<<"Enter the number : ";
        cin >> x;

        head = insrt(head,x);
        print(head);
    }

}

