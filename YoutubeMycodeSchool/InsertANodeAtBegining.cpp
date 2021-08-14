#include<iostream>

using namespace std;

struct Node{

    int data;
    Node* next;
};


struct Node* head;

//insert value at begining
void insrt(int x){

    Node* temp = new Node();
    temp -> data = x;
    temp -> next = head;
    head = temp;
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

        insrt(x);
        print();
    }

}
