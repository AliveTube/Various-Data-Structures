#include "stack.h"

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