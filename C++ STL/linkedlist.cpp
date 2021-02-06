#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
};
node* head = NULL;
void insert(int n){
    node* temp = new node();
    temp -> data = n;
    temp->next = head;
    head = temp;
}
void print(node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}
void deleted(int n){
    node* temp = head;
    if(n==1){
        head = head->next;
        delete(temp);
        return;
    }
    for(int i = 0;i<n-2;i++){
        temp = temp->next;
    }
    node* temp1 = temp->next;
    temp->next = temp1->next;
    delete(temp1);
}
void reverse(){
    node* temp, *prev, *curr;
    curr = head;
    prev = NULL;
    while(curr!=NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}
void printn(node* h){
    if(h==NULL)return;
    cout<<h->data<<" ";
    printn(h->next);
cout<<" ";
}

void printr(node* h){
    if(h==NULL)return;
    printr(h->next);
    cout<<h->data;
cout<<" ";
}
int main() {
    int n; 
    cin>>n;
    for(int i = 0; i<n; i++){
        int m;
        cin>>m;
        insert(m);
    }
    int d;
    cin>>d;
    print(head);
    cout<<"\nposition to be deleted enter\n";
    deleted(d);
    print(head);
    reverse();
    print(head);
    printn(head);
    printr(head);
    return 0;
}
