#pragma once

#include<string>
#include<iostream>
using namespace std;

template <typename T>
class Stack{
    private:
        T* arr;
        int size ;
        int capacity ;
    public:
        Stack(){
            size = 0;
            capacity = 1;
            arr = new T[capacity];
        }
        Stack(int stkSize){
            size = 0;
            capacity = stkSize;
            arr = new T[capacity];
        }
        void push(T element){
            if(size >= capacity){
                capacity*=2;
                T*tempArr = new T[capacity];
                for (int i = 0; i < size; i++)
                {
                    tempArr[i] = arr[i];
                }
                delete[] arr;
                arr = new T[capacity];
                arr = tempArr;
            }
            arr[size++] = element;
        }
        T pop(){
            if (!size){
                cout << "Stack is empty" << endl;
                return 0;
            }
            return arr[size--];
        }
        T top(){
            return arr[size-1];
        }
        bool isEmpty(){
            return size == 0;
        }
        int stackSize(){
            return size;
        }
        int stackCapacity(){
            return capacity;
        }
        void clear(){
            delete[] arr;
            size = 0;
            capacity = 1;
            arr = new T[capacity];
        }
        void print(){
            for (int i = size-1; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
        }
};
