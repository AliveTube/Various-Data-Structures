#include "singleLinkedList.h"

void mergeLinkedList() {}
singleLinkedList<int> sortedList;
template <typename T,typename... heads>
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
            while(tempNode != NULL && head->key >= tempNode->key){
                tempNode=tempNode->Next;
                index++;
            }
            sortedList.insertAt(head->key,index);
            head=head->Next;
        }
    }
    mergeLinkedList(Heads...);
}

int main(){
    singleLinkedList<int> list , list2 , list3;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);

    list2.insertAtTail(44);
    list2.insertAtTail(55);
    list2.insertAtTail(125);
    list2.insertAtTail(300);

    list3.insertAtTail(3);
    list2.insertAtTail(34);
    list2.insertAtTail(37);
    list2.insertAtTail(59);

    mergeLinkedList(list.returnHead(),list2.returnHead(),list3.returnHead());
    sortedList.print();
}
