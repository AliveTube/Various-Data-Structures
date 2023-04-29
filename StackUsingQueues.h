#pragma once

#include "Queue.h"
#include <exception>
#include <iostream>


template<typename T>
class StackUsingQueues {
    Queue<T> q1, q2;
    bool swapped = false;
public:
    void push(T val) {
        if (swapped) {
            q1.enqueue(val);
            while (!q2.isEmpty()) {
                q1.enqueue(q2.dequeue());
            }
        } else {
            q2.enqueue(val);
            while (!q1.isEmpty()) {
                q2.enqueue(q1.dequeue());
            }
        }
        swapped ^= 1;
    }

    T pop() {
        if (swapped)
            return q2.dequeue();
        else
            return q1.dequeue();
    }
};