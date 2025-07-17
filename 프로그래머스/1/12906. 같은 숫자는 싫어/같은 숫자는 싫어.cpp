#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int prevNumber = -1;
    for(auto a : arr)
    {
        if(a != prevNumber)
        {
            answer.push_back(a);
            prevNumber = a;
        }
    }
    
    return answer;
}