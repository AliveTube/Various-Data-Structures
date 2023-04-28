#include <bits/stdc++.h>
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

void infixToPostfix(string str){
    Stack<char> stk;
    int n = str.size();
    string answer;
    for (int i = 0; i < n; i++)
    {
        if(isalpha(str[i]) || isdigit(str[i])){
            answer+=str[i];
        }
        else{
            if(str[i] == '('){
                stk.push('(');
            }
            else if(str[i] == '+' || str[i] == '-'){
                if(stk.isEmpty()){
                    stk.push(str[i]);
                }
                else{
                    if(stk.top() == '-' || stk.top() == '+'){
                        answer+=stk.top();
                        stk.pop();
                        stk.push(str[i]);
                    }
                    else if (stk.top() == '*' || stk.top() == '/' || stk.top() == '^'){
                        while(!stk.isEmpty()){
                            answer+=stk.top();
                            stk.pop();
                        }
                        stk.push(str[i]);
                    }
                    else stk.push(str[i]);
                }
            }
            else if(str[i] == '*' || str[i] == '/' || str[i] == '^'){
                if(stk.isEmpty()){
                    stk.push(str[i]);
                }
                else if(str[i] == '^'){
                    if(stk.top() == '^'){
                        answer+=stk.top();
                        stk.pop();
                        stk.push(str[i]);
                    }
                    else stk.push(str[i]);
                }
                else{
                    if(stk.top()=='/' || stk.top() == '*'){
                        answer+=stk.top();
                        stk.pop();
                        stk.push(str[i]);
                    }
                    else if (stk.top() == '^'){
                        while(!stk.isEmpty() && stk.top() != '+' && stk.top() != '-' && stk.top()!='('){
                            answer+=stk.top();
                            stk.pop();
                        }
                        stk.push(str[i]);
                    }
                    else stk.push(str[i]);
                }
            }
            else if (str[i] == ')'){
                while (stk.top()!='(')
                {
                    answer+=stk.top();
                    stk.pop();
                }
                stk.pop();
            }
        }
    }
    while(!stk.isEmpty()){
        answer+=stk.top();
        stk.pop();
    }
    cout << answer << endl;
}

void longestValidParentheses(string str){
    int n = str.size();
    Stack<char> stk;
    int ans = 0 , cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if(str[i] == '('){
            stk.push(str[i]);
        }
        else if (str[i] == ')'){
            if (stk.isEmpty()){
                ans = max(ans,cnt);
                cnt=0;
            }
            else if(stk.top() == '('){
                cnt+=2;
                ans=max(ans,cnt);
                stk.pop();
            }
        }
    }
    cout << ans << endl;
}

int main(){
    // infixToPostfix("A + B * C + D");
    longestValidParentheses("");
}