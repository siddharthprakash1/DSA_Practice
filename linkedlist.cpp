#include<iostream>
using namespace std;
class node{
    public:
        int value;
        node* next;
    node(int value){
        this->value=value;
        next=nullptr;
    }
};
class linkedlist{
    private:
        node* head;
        node* tail;
        int length;
    public:
    linkedlist(int value){
        node* newnode= new node(value);
        head=newnode;
        tail=newnode;
        length=1;
    }
    ~linkedlist(){
        node* temp=head;
        while(head){
            head=head->next;
            delete temp;
            temp=head;
        }
    }
    void printlist(){
        node*temp=head;
        while(temp!=nullptr){
            cout<<temp->value<<endl;
            temp=temp->next;
        }
    }

    void gethead() {
        if(head==nullptr){
            cout<<"Head:Nullptr"<<endl;
        }
        else{
            cout<<"Head: "<<head->value<<endl;
        }
    }
    void gettail(){
        if(tail==nullptr){
            cout<<"Tail:Nullptr"<<endl;
        }
        else{
            cout<<"Tail: "<<tail->value<<endl;
        }
    }
    void getLength(){
        cout<<"Length: "<<length<<endl;
    }
    void append(int value)
    {
        node* newnode=new node(value);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }

};

int main (){
    linkedlist *myll=new linkedlist(1);
    myll->append(2);
    myll->append(3);
    myll->gethead();
    myll->gettail();
    myll->getLength();
    cout<<endl<<"Linked List:"<<endl;
    myll->printlist();
}
