#include <string>
#include <vector>

using namespace std;

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') return c + ('a' - 'A');
    return c;
}

int solution(string myString, string pat) {
    
    if(myString.length() < pat.length())
        return 0;
        
    int answer = 0;
    for(int i = 0; i <= myString.length() - pat.length(); i++)
    {
        bool flag = true;
        for(int j = 0; j < pat.length(); j++){
            if(toLower(myString[i+j]) != toLower(pat[j]))
            {
                flag = false;
                break;
            }    
        }
        if(flag)
            answer = 1;
    }
    return answer;
}