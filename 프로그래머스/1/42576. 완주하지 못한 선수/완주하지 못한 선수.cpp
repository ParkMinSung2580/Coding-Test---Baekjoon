#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string,int> myhash;
    
    for(string name : participant)
    {
        //참가자 등록
        myhash[name]++;
    }
    
    for(string name : completion)
    {
        //완주자 목록에 있는 이름들을 뺀다.
        myhash[name]--;
    }
    
    //1이상인 사람은 미완주자다
    for(auto pair : myhash) {
        if(pair.second > 0) {
            return pair.first;
        }
    }
}