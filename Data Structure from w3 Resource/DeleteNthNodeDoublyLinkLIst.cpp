#include<iostream>

using namespace std;

struct Node{

    int data;
    Node *next, *prev;
};

void insertion(int x);

Node* head = NULL, *prevNode;
Node* GetNode(int x);
void deletNthNode(int posiToDel);
void print();

int main(){

    int n, x;

    cout<<"Input number of nodes of doubly link list : ";

    cin>> n;

    for(int i = 0; i < n; i++){

        cout<<"Input value of node : ";
        cin>>x;

        insertion(x);
    }

    cout<<"Before delete List is : "<<endl;
    print();

    int posiToDel, num;

    cout<<"number of deleting nodes : ";

    cin>>num;


    for(int j = 0; j < num; j++){

        cout<<"input the position to delete : ";
        cin>>posiToDel;
        deletNthNode(posiToDel);
        cout<<"After delete List is :"<<endl;
        print();
    }





}

void insertion(int x){

    Node* newnode = GetNode(x);

    if(head == NULL){

        head = newnode;
        prevNode = newnode;
        return;
    }

    prevNode->next = newnode;
    newnode->prev = prevNode;
    prevNode = newnode;

}

Node* GetNode(int x){

    Node* temp = new Node();

    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;

    return temp;
}

void deletNthNode(int posiToDel){



    if(posiToDel == 1){

        head = head->next;
        return;
    }

    Node* temp = head;

    for(int i = 1; i < posiToDel - 1; i++){

        temp = temp->next;
    }

    Node* temp2;

    temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);

}

void print(){

    Node* temp = head;
    //cout<<endl<<"List are :"<<endl;
    while(temp != NULL){

        cout<<temp->data<<endl;
        temp = temp->next;
    }

}


