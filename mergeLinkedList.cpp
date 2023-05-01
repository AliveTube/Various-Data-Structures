#include "singleLinkedList.h"

void mergeLinkedList() {}
singleLinkedList<int> sortedList;
template <typename T ,typename... heads>
void mergeLinkedList(T head , heads... Heads){
    if(sortedList.isEmpty()){
        while(head != NULL){
            sortedList.insertAtTail(head->key);
            head = head->Next;
        }
    }
    else{
        while(head != NULL){
            sllNode<int>* tempNode = sortedList.returnHead();
            int index = 0;
            while(head->key >= tempNode->key && tempNode != NULL){
                tempNode=tempNode->Next;
                index++;
                if(tempNode==NULL)break;
            }
            sortedList.insertAt(head->key,index);
            head=head->Next;
        }
    }
    mergeLinkedList(Heads...);
}