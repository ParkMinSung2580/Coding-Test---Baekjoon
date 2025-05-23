#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    
    for(int j = 0; j < strArr.size(); j++)
    {
        for(int i = 0; i < strArr[j].length(); i++)
        {
            char& ch = strArr[j][i];
            
            if(j % 2 != 0) { // 홀수 인덱스 - 대문자로 변환
                if(ch >= 'a' && ch <= 'z') {
                    ch -= 32;
                }
            } else { // 짝수 인덱스 - 소문자로 변환
                if(ch >= 'A' && ch <= 'Z') {
                    ch += 32;
                }
            }
        }
    }
    answer = strArr;
    return answer;
}