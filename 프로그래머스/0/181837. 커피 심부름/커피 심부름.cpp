#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    
    /*
    americano -> 4500원
    cafelatte -> 5000원
    anything -> 4500원
    */
    string target1 = "americano";
    string target2 = "cafelatte";
        
    
    for(auto v : order)
    {
        if(v.find(target1) != std::string::npos)
            answer += 4500;
        if(v.find(target2) != std::string::npos)
            answer += 5000;
        if(v == "anything")
            answer += 4500;
    }
     return answer;
}