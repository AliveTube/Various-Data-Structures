#pragma once

#include <exception>
#include <iostream>

template<typename T>
struct LinkedListNode {
    LinkedListNode *nxt = nullptr, *prev = nullptr;
    T value = nullptr;

    LinkedListNode(T value) : value(value) {}
};

template<typename T>
class CircularLinkedList {
    LinkedListNode<T> *head = nullptr, *tail = nullptr;
    int size = 0;

    LinkedListNode<T> *retriveNodeAt(int index) {
        if (index >= size) {
            throw std::exception();
        }

        int cnt = 0;
        auto *curNode = head;
        if (index <= size / 2) {
            while (cnt < index) {
                curNode = curNode->nxt;
                cnt++;
            }
        } else {
            while (cnt < size - index) {
                curNode = curNode->prev;
                cnt++;
            }
        }

        return curNode;
    }

public:
    void insertAtHead(T element) {
        auto *newNode = new LinkedListNode<T>(element);

        if (size == 0) {
            head = tail = newNode;
            head->nxt = head->prev = head;
        } else {
            head->prev = newNode;
            tail->nxt = newNode;

            newNode->nxt = head;
            newNode->prev = tail;
            head = newNode;
        }
        size++;
    }

    void insertAtTail(T element) {
        auto *newNode = new LinkedListNode<T>(element);

        if (size == 0) {
            head = tail = newNode;
            head->nxt = head->prev = head;
        } else {
            head->prev = newNode;
            tail->nxt = newNode;

            newNode->nxt = head;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void insertAt(T element, int index) {
        if (index >= size) {
            throw std::exception();
        }

        if (index == 0) {
            insertAtHead(element);
            return;
        } else if (index == size - 1) {
            insertAtTail(element);
            return;
        }

        auto *newNode = new LinkedListNode<T>(element);
        if (size == 0) {
            head = tail = newNode;
            head->nxt = head->prev = head;
            return;
        }

        int cnt = 0;
        auto *curNode = retriveNodeAt(index);

        auto prev = curNode->prev;
        curNode->prev = newNode;
        prev->nxt = newNode;

        newNode->nxt = curNode;
        newNode->prev = prev;
        size++;
    }

    void removeAtHead() {
        if (size == 0) {
            throw std::exception();
        }

        auto *newHead = head->nxt;
        tail->nxt = newHead;
        newHead->prev = tail;

        delete head;

        head = newHead;
        size--;
    }

    void removeAtTail() {
        if (size == 0) {
            throw std::exception();
        }

        auto *newTail = tail->prev;
        head->prev = newTail;
        newTail->nxt = head;

        delete tail;

        tail = newTail;
        size--;
    }

    void removeAt(int index) {
        if (index >= size) {
            throw std::exception();
        }
        if (index == 0) {
            removeAtHead();
            return;
        } else if (index == size - 1) {
            removeAtTail();
            return;
        }

        int cnt = 0;
        auto *curNode = retriveNodeAt(index);

        auto nxt = curNode->nxt;
        auto prev = curNode->prev;

        prev->nxt = nxt;
        nxt->prev = prev;

        delete curNode;
        size--;
    }

    T retriveAt(int index) {
        if (index >= size) {
            throw std::exception();
        }
        int cnt = 0;
        auto *curNode = retriveNodeAt(index);
        return curNode->value;
    }

    void replaceAt(T element, int index) {
        if (index >= size) {
            throw std::exception();
        }

        int cnt = 0;
        auto *curNode = retriveNodeAt(index);

        curNode->value = element;
    }

    bool isExist(T element) {
        auto *curNode = head;
        do {
            if (curNode->value == element) { return true; }
            curNode = curNode->nxt;
        } while (curNode != head);
        return false;
    }

    bool isItemAtEqual(T element, int index) {
        if (index >= size) {
            throw std::exception();
        }

        int cnt = 0;
        auto *curNode = retriveNodeAt(index);

        return element == curNode->value;
    }

    void swap(int firstItemIndex, int secondItemIndex) {
        if (firstItemIndex >= size || secondItemIndex >= size) {
            throw std::exception();
        }
        if (firstItemIndex > secondItemIndex) { std::swap(firstItemIndex, secondItemIndex); }

        LinkedListNode<T> *firstNode = retriveNodeAt(firstItemIndex);
        LinkedListNode<T> *secondNode = retriveNodeAt(secondItemIndex);

        if (secondItemIndex - firstItemIndex == 1) {
            firstNode->prev->nxt = secondNode;
            secondNode->nxt->prev = firstNode;

            firstNode->nxt = secondNode->nxt;
            secondNode->nxt = firstNode;

            secondNode->prev = firstNode->prev;
            firstNode->prev = secondNode;
            return;
        }

        auto tmp = firstNode->nxt;
        firstNode->nxt = secondNode->nxt;
        secondNode->nxt = tmp;

        tmp = firstNode->prev;
        firstNode->prev = secondNode->prev;
        secondNode->prev = tmp;


        firstNode->nxt->prev = firstNode;
        firstNode->prev->nxt = firstNode;

        secondNode->nxt->prev = secondNode;
        secondNode->prev->nxt = secondNode;

        if (head == firstNode) {
            head = secondNode;
        }
        if (tail == secondNode) {
            tail = firstNode;
        }
    }

    bool isEmpty() {
        return size == 0;
    }

    int circularLinkedListSize() {
        return size;
    }

    void clear() {
        while (size > 0) {
            removeAtHead();
        }
    }

    void print() {
        auto *curNode = head;
        do {
            std::cout << curNode->value << " ";
            curNode = curNode->nxt;
        } while (curNode != head);
        std::cout << std::endl;
    }

    ~CircularLinkedList() {
        while (size > 0) {
            removeAtHead();
        }
    }
};