#include<string>
#include<stack>
#include <iostream>

using namespace std;

bool solution(string s)
{
    stack<char> mystack;
    bool answer = true;
    int count = 0;   
    
    while(count < s.length())
    {
        if(s[count] == '(')
        {
            mystack.push(s[count]);
            count++;
        }
        else if(s[count] == ')')
        {
            if(mystack.empty()) return false;
            mystack.pop();
            count++;
        }
    }
    
    if(!mystack.empty()) return false;
    
    return answer;
}