#pragma once

#include <bits/stdc++.h>
#include <exception>

using namespace std;



template<typename T>
struct QueueNode {
    QueueNode *nxt = nullptr, *prev = nullptr;
    T value = nullptr;

    QueueNode(T value) : value(value) {}
};

template<typename T>
class Queue {
    QueueNode<T> *head = nullptr, *tail = nullptr;
    int size = 0;

public:
    void enqueue(T val) {
        QueueNode<T> *newNode = new QueueNode<T>(val);
        if (head == nullptr) {
            head = newNode;
        }
        if (tail != nullptr) {
            tail->nxt = newNode;
            newNode->prev = tail;
        }
        tail = newNode;
        size++;
    }

    T dequeue() {
        if (size == 0)
            throw std::exception();
        QueueNode<T> *newHead = head->nxt;
        if (head == tail) {
            tail = nullptr;
        }
        if(newHead != nullptr) {
            newHead->prev = nullptr;
        }
        T value = head->value;
        delete head;

        head = newHead;
        size--;
        return value;
    }

    T first() {
        return head->value;
    }

    bool isEmpty() {
        return size == 0;
    }

    int queueSize() {
        return size;
    }

    void clear() {
        while (size > 0) {
            dequeue();
        }
    }

    void print() {
        QueueNode<T> *cur = head;
        do {
            std::cout << cur->value << " \n"[cur->nxt == nullptr];
            cur = cur->nxt;
        } while (cur != nullptr);
    }

    ~Queue() {
        clear();
    }

};
