#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    string answer = "";
    int length = str2.length() * 2;
    int index = 0;
    int str1index = 0;
    int str2index = 0;
    while(index < length)
    {
        if(index % 2 == 0)
            answer += str1[str1index++]; 
        else
            answer += str2[str2index++];
        
        index++;
    }
    return answer;
}