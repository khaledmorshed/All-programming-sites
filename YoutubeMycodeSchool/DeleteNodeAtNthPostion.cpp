
#include<bits/stdc++.h>

using namespace std;

void decision();
void delet();
void insrt();
void print();
void  exit();
int lengthOfList();

struct Node{

    int data;
    Node* next;

};

Node* head = NULL;

int lengthOfList(){

    Node* temp = head;
    int len = 0;

    while(temp != NULL){

        temp = temp->next;
        len++;
    }


  return len;

}

void insrt(int x){

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

void delet(int position){


    Node* temp1 = head;

    if(position == 1){

        head = temp1->next;
        free(temp1);
        return;
    }

    for(int i = 0; i < position - 2; i++){

        temp1 = temp1->next;
    }

    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);

}

void print(){

    int i=1;

    Node* temp = head;
    cout<<"List is :"<<endl;
    while(temp != NULL){

        cout<<i++<<" : "<<temp->data<<endl;;
        temp = temp->next;

    }
    //cout<<endl;
}


void decision(){

    int takenumber,n;

    cout<<"1.insert press one(1)"<<endl<<"2.delete press two(2)"<<endl<<"3.press anywhere to exit"<<endl<<endl<<"choice : ";
    cin>>takenumber;

    //Insert function
    if(takenumber == 1){

         while(1){
        cout<<endl<<"Insert a number at end and input 0 to get exit and -1 to get choice option: ";
        cin >>n;

        if(n == 0){

             exit();
        }
        else if(n == -1){

            cout<<endl;
            decision();
        }


        else{

         insrt(n);
         print();

        }
    }
    }

    //Delete function
    else if(takenumber == 2){


    if(head == NULL){

        cout<<endl<<"There is no value in your list to delete.To delete insert first."<<endl;
        cout<<endl;
        decision();
    }

        int position, i,length;

    while(1){

        cout<<endl<<"Input a position to delete and input 0 to exit or press -1 to get choice option : ";

        cin>>position;

        if(position == 0){

            exit();
        }
        else if(position == -1){

             cout<<endl;
            decision();
        }

        else if(position > (length=lengthOfList())){

                cout<<endl<<"<---There is no value in this position so input existing position--->"<<endl;
        }


        else{

         delet(position);
         print();

        }
    }

    }

    else {
            exit();
    }

}

void exit(){

             cout<<endl<<"<----See you soon---->"<<endl;
             return ;
}


int main(){

     decision();
}
