#include <bits/stdc++.h>
using namespace std;


template <typename T>
struct Node{
    Node<T>* Next;
    T key;
    Node(){
        Next = NULL;
        key = 0 ;
    }
    Node (T element){
        Next = NULL;
        key = element;
    }
};


template <typename T>
class slList{
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;
    public:
        slList(){
            head = tail = NULL;
            size = 0;
        }
        Node<T>* returnHead(){
            return head;
        }
        void insertAtHead(T element){
            Node<T>* newNode = new Node<T>(element);
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
            Node<T>* newNode = new Node<T>(element);
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
            Node<T>* newNode = new Node<T>(element);
            Node<T>* tempNode = head;
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
            Node<T>* tempNode = head;
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
                Node<T>* tempNode = tail;
                head = NULL;
                delete tempNode;
                tail = NULL;
                size--;
                return ;
            }
            Node<T>* tempNode = head;
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
            Node<T>* tempNode = head;
            Node<T>* cur;
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
            Node<T>* tempNode = head;
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
            Node<T>* tempNode = head;
            for (int i = 0; i < index; i++)
            {
                tempNode=tempNode->Next;
            }
            tempNode->key = element;
        }
        bool isExist(T element){
            Node<T>* tempNode = head;
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
            Node<T>* tempNode = head;
            for (int i = 0; i < index; i++)
            {
                tempNode=tempNode->Next;
            }
            if (tempNode->key == element) return 1;
            return 0;
        }
        // -----------------------------------------------------
        void swap(int firstIndex , int secondIndex){

        }
        // -----------------------------------------------------
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
            Node<T>* tempNode = head;
            while(tempNode != NULL){
                cout << tempNode->key << " ";
                tempNode = tempNode->Next;
            }
            delete tempNode;
        }
};

template <typename T>
slList<T> combineNodes(Node<T>* head){
    Node<T>* tempNode = head;
    slList<T> newList;
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

void mergeLinkedList() {}
slList<int> sortedList;
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
            Node<int>* tempNode = sortedList.returnHead();
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

int main(){
    // list.insertAtHead(3);
    // list.insertAtHead(4);
    // list.insertAtHead(5);
    // cout << list.isItemAtEqual(5,0) << endl;
    // list.print();
    slList<int> list , newList ,list2;
    list.insertAtTail(1);
    list.insertAtTail(4);
    list.insertAtTail(5);
    newList.insertAtTail(0);
    newList.insertAtTail(0);
    newList.insertAtTail(0);
    list2.insertAtTail(0);
    list2.insertAtTail(14);
    list2.insertAtTail(14);
    list2.insertAtTail(14);
    list2.insertAtTail(14);
    mergeLinkedList(newList.returnHead(),list2.returnHead(),list.returnHead(),list2.returnHead());
    sortedList.print();
}