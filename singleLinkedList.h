#pragma once

#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct sllNode{
    sllNode<T>* Next;
    T key;
    sllNode(){
        Next = NULL;
        key = 0 ;
    }
    sllNode (T element){
        Next = NULL;
        key = element;
    }
};


template <typename T>
class singleLinkedList{
    private:
        sllNode<T>* head;
        sllNode<T>* tail;
        int size;
    public:
        singleLinkedList(){
            head = tail = NULL;
            size = 0;
        }
        sllNode<T>* returnHead(){
            return head;
        }
        void insertAtHead(T element){
            sllNode<T>* newNode = new sllNode<T>(element);
            if (head == NULL){
                head = tail = newNode;
            }
            else {
                newNode->Next = head;
                head = newNode;
            }
            size++;
        }
        void insertAtTail(T element){
            sllNode<T>* newNode = new sllNode<T>(element);
            if (tail == NULL){
                head = tail = newNode;
            }
            else {
                tail->Next = newNode;
                tail = newNode;
            }
            size++;
        }
        void insertAt(T element , int index){
            if (index > size || index < 0){
                cout << "Index out of bound !" << endl;
                return ;
            }
            if(!index){
                insertAtHead(element);
            }
            sllNode<T>* newNode = new sllNode<T>(element);
            sllNode<T>* tempNode = head;
            tempNode = head;
            int i = 0;
            while(tempNode!=NULL){
                if (i+1 == index){
                    newNode->Next = tempNode->Next;
                    tempNode->Next = newNode;
                    break;
                }
                tempNode=tempNode->Next;
                i++;
            }
            size++;
        }
        void removeAtHead(){
            if (head == NULL){
                cout << "List is empty" << endl;
                return;
            }
            sllNode<T>* tempNode = head;
            head = head->Next;
            delete tempNode;
            if (head == NULL){
                tail = NULL;
            }
            size--;
        }
        void removeAtTail(){
            if (tail == NULL){
                cout << "List is empty" << endl;
                return;
            }
            else if (tail == head){
                sllNode<T>* tempNode = tail;
                head = NULL;
                delete tempNode;
                tail = NULL;
                size--;
                return ;
            }
            sllNode<T>* tempNode = head;
            while(tempNode->Next->Next != NULL){
                tempNode=tempNode->Next;
            }
            tail = tempNode;
            tail->Next = NULL;
            tempNode = tempNode->Next;
            delete tempNode;
            size--;
        }
        void removeAt(int index){
            if (index >= size || index < 0){
                cout << "Index out of bound !" << endl;
                return ;
            }
            if (!index){
                removeAtHead();
                return ;
            }
            sllNode<T>* tempNode = head;
            sllNode<T>* cur;
            int i = 0;
            while (tempNode != NULL){
                if (i+1 == index){
                    cur = tempNode->Next;
                    tempNode->Next = tempNode->Next->Next;
                    delete cur;
                    break;
                }
                i++;
                tempNode = tempNode->Next;
            }
            size--;
        }
        T retrieveAt(int index){
            if (index >= size || index < 0){
                cout << "Index out of bound !" << endl;
                return 0;
            }
            sllNode<T>* tempNode = head;
            for (int i = 0; i < index; i++)
            {
                tempNode=tempNode->Next;
            }
            return tempNode->key;
        }
        void replaceAt(T element, int index){
            if (index >= size || index < 0){
                cout << "Index out of bound !" << endl;
                return ;
            }
            sllNode<T>* tempNode = head;
            for (int i = 0; i < index; i++)
            {
                tempNode=tempNode->Next;
            }
            tempNode->key = element;
        }
        bool isExist(T element){
            sllNode<T>* tempNode = head;
            while(tempNode != NULL){
                if (tempNode->key == element){
                    return 1;
                }
                tempNode=tempNode->Next;
            }
            return 0;
        }
        bool isItemAtEqual(T element , int index){
            if (index >= size || index < 0){
                cout << "Index out of bound !" << endl;
                return 0;
            }
            sllNode<T>* tempNode = head;
            for (int i = 0; i < index; i++)
            {
                tempNode=tempNode->Next;
            }
            if (tempNode->key == element) return 1;
            return 0;
        }
        void swap(int firstIndex , int secondIndex){
            if (firstIndex < 0 || firstIndex >= size || secondIndex < 0 || secondIndex >= size){
                cout << "Index out of bound !" << endl;
                return ;
            }
            else if (firstIndex == secondIndex){
                return;
            }
            if (firstIndex > secondIndex){
                std::swap(firstIndex,secondIndex);
            }
            sllNode<T>* tempNode1 = head, *tempNode2 = head ;
            sllNode<T>* prev1 = NULL , *prev2 = NULL , *next1 = NULL , *next2 = NULL;
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
            if(secondIndex - firstIndex == 1){
                if(prev1 != NULL){
                    prev1->Next = tempNode2;
                }
                tempNode1->Next = tempNode2->Next;
                tempNode2->Next = tempNode1;
            }
            else {
                next1 = tempNode1->Next;
                next2 = tempNode2->Next;
                tempNode1->Next = next2;
                tempNode2->Next = next1;
                if(prev1 != NULL){
                    prev1->Next = tempNode2;
                }
                prev2->Next = tempNode1;
            }
            if(tempNode1 == head){
                head = tempNode2;
            }
            if(tempNode2 == tail){
                tail = tempNode1;
            }
        }
        bool isEmpty(){
            return size == 0;
        }
        int linkedListSize(){
            return size;
        }
        void clear(){
            while(head != NULL){
                removeAtHead();
            }
        }
        void print(){
            sllNode<T>* tempNode = head;
            while(tempNode != NULL){
                cout << tempNode->key << " ";
                tempNode = tempNode->Next;
            }
            delete tempNode;
        }
};