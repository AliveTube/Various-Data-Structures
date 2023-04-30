#include "Queue.h"

template<typename T>
void sortQueue(Queue<T> &inputQueue) {
    int n = inputQueue.queueSize();
    Queue<T> q1, q2, output;
    while (!inputQueue.isEmpty()) {
        q1.enqueue(inputQueue.dequeue());
    }

    for (int i = 0; i < n; ++i) {
        T curMin = q1.first();
        while (!q1.isEmpty()) {
            if (q1.first() < curMin)
                curMin = q1.first();
            q2.enqueue(q1.dequeue());
        }
        while (!q2.isEmpty()) {
            if (q2.first() == curMin) {
                inputQueue.enqueue(q2.dequeue());
            } else {
                q1.enqueue(q2.dequeue());
            }
        }
    }
}