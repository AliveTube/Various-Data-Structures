#include "singleLinkedList.h"

template <typename T>
singleLinkedList<T> combineNodes(sllNode<T>* head){
    sllNode<T>* tempNode = head;
    singleLinkedList<T> newList;
    while(tempNode->Next!=NULL){
        if (!tempNode->key){
            tempNode = tempNode->Next;
            T sm = 0;
            while(tempNode->key != 0){
                sm+=tempNode->key;
                tempNode = tempNode->Next;
            }
            if(sm) newList.insertAtTail(sm);
            sm=0;
        }
    }
    return newList;
}