#pragma once

#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct dllNode{
    dllNode<T>* Next;
    dllNode<T>* Prev;
    T key;

    dllNode(){
        Next = NULL;
        Prev = NULL;
        key = 0 ;
    }
    dllNode (T element){
        Next = NULL;
        Prev = NULL;
        key = element;
    }
};


template <typename T>
class doubleLinkedList{
    private:
        dllNode<T>* head;
        dllNode<T>* tail;
        int size;
    public:
        doubleLinkedList(){
            head = tail = NULL;
            size = 0;
        }
        void insertAtHead(T element){
            dllNode<T>* newNode = new dllNode(element);
            if (!size){
                head=tail=newNode;
            }
            else {
                newNode->Next = head;
                head->Prev = newNode ;
                head = newNode;
            }
            size++;
        }
        void insertAtTail(T element){
            dllNode<T>* newNode = new dllNode(element);
            if (!size){
                head=tail=newNode;
            }
            else {
                newNode->Prev = tail;
                tail->Next = newNode ;
                tail = newNode;
            }
            size++;
        }
        void insertAt(T element , int index){
            dllNode<T>* tempNode = head;
            dllNode<T>* newNode = new dllNode(element);
            if (index > size || index < 0){
                cout << "Invalid index!" << endl;
                return ;
            }
            else if(!index){
                insertAtHead(element);
            }
            else if (index == size){
                insertAtTail(element);
            }
            else{
                for (int i = 0; i < index-1; i++)
                {
                    tempNode=tempNode->Next;
                }
                newNode->Prev = tempNode;
                newNode->Next = tempNode->Next;
                tempNode->Next->Prev = newNode;
                tempNode->Next = newNode;
                size++;
            }
        }
        void removeAtHead(){
            if (!size){
                cout << "List is empty!" << endl;
                return;
            }
            dllNode<T>* tempNode = head;
            tempNode = tempNode->Next;
            tempNode->Prev = NULL;
            delete head;
            head = tempNode;
            size--;
        }
        void removeAtTail(){
            if (!size){
                cout << "List is empty!" << endl;
                return;
            }
            dllNode<T>* tempNode = tail;
            tempNode = tempNode->Prev;
            tempNode->Next = NULL;
            delete tail;
            tail = tempNode;
            size--;
        }
        void removeAt(int index){
            dllNode<T>* tempNode = head;
            if (index > size || index < 0){
                cout << "Invalid index!" << endl;
                return ;
            }
            else if(!index){
                removeAtHead();
            }
            else if (index == size){
                removeAtTail();
            }
            else{
                for (int i = 0; i < index-1; i++)
                {
                    tempNode=tempNode->Next;
                }
                dllNode<T>* cur = tempNode->Next;
                tempNode->Next = tempNode->Next->Next;
                tempNode->Next->Prev = tempNode;
                delete cur;
            }
            size--;
        }
        T retrieveAt(int index){
            dllNode<T>* tempNode = head;
            if (index > size || index < 0){
                cout << "Invalid index!" << endl;
            }
            else{
                for (int i = 0; i < index; i++)
                {
                    tempNode=tempNode->Next;
                }
            }
            return tempNode->key;
        }
        void replaceAt(T element , int index){
            dllNode<T>* tempNode = head;
            if (index > size || index < 0){
                cout << "Invalid index!" << endl;
                return ;
            }
            for (int i = 0; i < index; i++)
            {
                tempNode=tempNode->Next;
            }
            tempNode->key = element;
        }
        bool isExist(T element){
            dllNode<T>* tempNode = head;
            for (int i = 0; i < size; i++)
            {
                if (tempNode->key == element) return 1;
                tempNode=tempNode->Next;
            }
            return 0 ;
        }
        bool isItemAtEqual(T element , int index){
            dllNode<T>* tempNode = head;
            if (index > size || index < 0){
                cout << "Invalid index!" << endl;
            }
            else {
                for (int i = 0; i < index; i++)
                {
                    tempNode=tempNode->Next;
                }
                if(tempNode->key == element){
                    return 1;
                }
            }
            return 0 ;
        }
        void swap(int firstIndex , int secondIndex){
            if (firstIndex < 0 || firstIndex >= size || secondIndex < 0 || secondIndex >= size){
                cout << "Index out of bound !" << endl;
                return ;
            }
            else if (firstIndex == secondIndex){
                return;
            }
            if(firstIndex > secondIndex){
                std::swap(firstIndex,secondIndex);
            }
            dllNode<T>* tempNode1 = head, *tempNode2 = head ;
            dllNode<T>* prev1 = NULL , *prev2 = NULL , *next1 = NULL , *next2 = NULL;
            for (int i = 0; i < firstIndex; i++)
            {
                prev1 = tempNode1;
                tempNode1 = tempNode1->Next;
            }
            for (int i = 0; i < secondIndex; i++)
            {
                prev2 = tempNode2;
                tempNode2 = tempNode2->Next;
            }
            if(secondIndex-firstIndex == 1){
                tempNode1->Next = tempNode2->Next;
                tempNode2->Prev = prev1;
                tempNode1->Prev = tempNode2;
                tempNode2->Next = tempNode1;
                next2 = tempNode2->Next;
                if(next2 != NULL){
                    next2->Prev = tempNode1;
                }
                if(prev1 != NULL){
                    prev1->Next = tempNode2;
                }
            }
            else {
                next1 = tempNode1->Next;
                next2 = tempNode2->Next;
                tempNode1->Next = next2;
                tempNode2->Next = next1;
                tempNode1->Prev = prev2;
                tempNode2->Prev = prev1;
                if(next2 != NULL){
                    next2->Prev = tempNode1;
                }
                if(prev1 != NULL){
                    prev1->Next = tempNode2;
                }
                next1->Prev = tempNode2;
                prev2->Next = tempNode1;
            }
            if (tempNode2 == tail){
                tail = tempNode1;
            }
            if (tempNode1 == head){
                head = tempNode2;
            }
        }
        void reverse(){
            dllNode<T>* tempNode = head;
            dllNode<T>* cur = head;
            if (size <= 1){
                return ;
            }
            while(tempNode != NULL){
                cur = tempNode->Next;
                tempNode->Next = tempNode->Prev;
                tempNode->Prev = cur;
                tempNode = tempNode->Prev;
            }
            dllNode<T>* temp = head;
            head = tail;
            tail = temp;
        }
        bool isEmpty(){
            return size == 0;
        }
        int doubleLinkedListSize(){
            return size;
        }
        void clear(){
            while(head != NULL){
                removeAtHead();
            }
        }
        void forwardTraversal(){
            dllNode<T>* tempNode = head;
            while(tempNode != NULL){
                cout << tempNode->key << " ";
                tempNode = tempNode->Next;
            }
        }
        void backwardTraversal(){
            dllNode<T>* tempNode = tail;
            while(tempNode != NULL){
                cout << tempNode->key << " ";
                tempNode = tempNode->Prev;
            }
        }
};
int main(){
    doubleLinkedList<int> list ;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.swap(3,4);
    list.forwardTraversal();

}