/*#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//sort를 통해 정렬하여 substr로 인접한 두개의 string을 비교 -> Hash의 의도에 벗어난것같음
bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(),phone_book.end());
    
    for(int i = 0; i < phone_book.size()-1; i++)
    {
        string str = phone_book[i+1].substr(0, phone_book[i].size());
        if(phone_book[i] == str)
            return false;
    }
    
    return answer;
}*/

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string,int> myhash;
    //한글자씩 접두사를 만들어서 비교해보기
    
    //1로 초기화 
    for(string str : phone_book)
    {
        myhash[str]++;
    }
    
    //순회
    for(int i =0; i < phone_book.size();i++)
    {
        string myPhone_number = "";
        for(int j = 0; j < phone_book[i].size(); j++)
        {
            //한글자씩 추가
            myPhone_number += phone_book[i][j];
            //조합된 접두어가 해시테이블에 존재하면서 동시에 해당값이 자신이 자기 자신을 가르키는 것이 아닐 때 
            if(myhash[myPhone_number] && myPhone_number != phone_book[i])
            {
                return false;
            }
        }
    }
    //반복문안에서 return 안했을 경우는 접두어가 존재하지 않을 때
    return true;
}