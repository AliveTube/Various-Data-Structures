#include "stack.h"

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