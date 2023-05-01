#include "queue.h"

void generateBinaryNumbers(long long n){
    Queue<string> q;
    q.enqueue("1");
    for (int i = 1; i <= n; i++)
    {
        string a = q.first();
        cout << a << endl;
        q.dequeue();
        string b = a;
        a+='0';
        b+='1';
        q.enqueue(a);
        q.enqueue(b);
    }
}