#pragma once

#include<iostream>
using namespace std;

template <typename T>
class List {
    private:
        T *arr;
        int size ;
        int index ;
    public:
        List(){
            size = 1;
            index = 0;
            arr = new T[size];
        }
        List(int sz){
            this->size = sz;
            index = 0;
            arr = new T[sz];
        }
        ~List(){
            delete[] arr;
            size = 0;
            index = 0;
        }
        void insert(T element){
            if (index >= size){
                cout << "List is full !" << endl;
            }
            else {
                arr[index++] = element;
            }
        }
        void insertAt(T element , int indx){
            if (indx >= size || indx < 0){
                cout << "Invalid index !" << endl;
            }
            else if (index >= size){
                cout << "List is full !" << endl;
            }
            else {
                for (int i = size-2; i >= indx; i--)
                {
                    arr[i+1] = arr[i];
                }
                arr[indx] = element;
                index++;
            }
        }
        T retrieveAt(int indx){
            if (indx >= index || indx < 0){
                cout << "Invalid index !" << endl;
            }
            else {
                return arr[indx];
            }
        }
        void removeAt(int indx){
            if (indx >= index || indx < 0){
                cout << "Invalid index !" << endl;
            }
            else {
                for (int i = indx; i < size-1; i++)
                {
                    arr[i] = arr[i+1];
                }
                index--;
            }
        }
        void replaceAt(T element , int indx){
            if (indx >= index || indx < 0){
                cout << "Invalid index !" << endl;
            }
            else {
                arr[indx] = element;
            }
        }
        bool isItemAtEqual(T element, int indx){
            if (indx >= index || indx < 0){
                cout << "Invalid index !" << endl;
            }
            else {
                return arr[indx] == element;
            }
        }
        bool isEmpty(){
            return index == 0;
        }
        bool isFull(){
            return index == size;
        }
        int listSize(){
            return index;
        }
        int maxListSize(){
            return size;
        }
        void clear(){
            delete[] arr;
            size = 0;
            index = 0;
        }
        void print(){
            for (int i = 0; i < index; i++)
            {
                cout << arr[i] << " ";
            }
        }
};

// int main(){
//    List <int> lst(4);
//    lst.insert(2);
//    lst.insert(4);
//    lst.insertAt(6,1);
//    lst.insertAt(44,1);
//    lst.removeAt(0);
//    lst.print();
//    lst.clear();
//    lst.print();
// }