#include<iostream>

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


    int n = 1, i=0;

    while(1){
        cout<<"Insert a number at end and input 0 will help you to break : ";
        cin >>n;

        if(n == 0){

            break;
        }

        insert(n);

        print();

    }


}
