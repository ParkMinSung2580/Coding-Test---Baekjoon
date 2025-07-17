#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    bool mode = false;
    
    for(int idx =0; idx < code.length(); idx++)
    {
        if(!mode)
        {
            if(code[idx] == '1')
            {
                mode = !mode; 
            }
            else if(idx % 2 == 0)
            {
                answer += code[idx];
            }
        }
        else
        {
            if(code[idx] == '1')
            {
                mode = !mode; 
            }
            else if(idx % 2 != 0)
            {
                answer += code[idx];
            }          
        }
    }
    if(answer.length() != 0)
        return answer;
    else 
        return "EMPTY";
}