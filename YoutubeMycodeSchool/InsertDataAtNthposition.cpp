#include<iostream>
 using namespace std;

 struct Nod{

    int data;
    Nod* next;

 };

 Nod* head = NULL;

 void insrt(int x, int posi){

    Nod* temp = new Nod();

    temp -> data = x;
    temp -> next = NULL;

    if(posi == 1){

        temp -> next = head;
        head = temp;

        return;
    }

    Nod* temp2 = head;

    for(int i = 0; i < posi - 2; i++){

        temp2 = temp2 -> next;
    }

    temp->next = temp2->next;
    temp2->next = temp;

 }
int j;
 void print(int posi){

     Nod* temp3 = head;
    j=1;

    while(temp3 != 0){

        cout<<endl<<j++<<" : ";
        cout<<temp3->data<<endl;
        temp3 = temp3 -> next;
    }
   // cout<<endl;
 }

 int main(){

    int n, x, posi;

    cout<<"How many numbers want to insert : ";
    cin>>n;

    for(int i; i<n; i++){

        cout<<endl<<"Enter the number and position : ";
        cin >> x >>posi;
        insrt(x,posi);
        print(posi);
    }

 }
