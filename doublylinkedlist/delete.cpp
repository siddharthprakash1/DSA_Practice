#include<iostream>
using namespace std;
class node{
    public:
    node* next;
    int value;
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
            node* newnode=new node(value);
            head=newnode;
            tail=newnode;
            length=1;
        }
        ~linkedlist(){
            node*temp=head;
            while(head!=nullptr){
                head=head->next;
                delete temp;
                temp=head;
            }
        }
        void printlist(){
            node* temp=head;
            while(temp!=nullptr){
                cout<<temp->value<<endl;
                temp=temp->next;
            }
        }
        void gethead(){
            if(head==nullptr){
                cout<<"head: nullptr"<<endl;
            }
            else{
                cout<<"head: "<<head->value<<endl;
            }
        }
        void gettail(){
            if(tail==nullptr){
                cout<<"tail: nullptr"<<endl;
            }
            else{
                cout<<"Tail: "<<tail->value<<endl;
            }
        }
        void getlength(){
            cout<<"length: "<<length<<endl;
        }
        void append(int value){
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
int main(){
    linkedlist* ll=new linkedlist(3);
    ll->append(2);
    ll->append(4);
    ll->gethead();
    ll->getlength();
    ll->printlist();

}



