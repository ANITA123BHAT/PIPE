#include<iostream>;
class Node{
    public:
    int data;
    Node *next=NULL;
    Node *prev=NULL;
    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
class DoublyLinkedList{
    public:
    Node *head;
    Node *tail;
    DoublyLinkedList(){
        head=NULL;
        tail=NULL;
    }

    void insertionAtHead(int value){

    }
};
int main(){
    DoublyLinkedList dll;
    dll.insertionAtHead(10);


    return 0;
}