#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_map<int,int> hash;
    
    for(int pokemon : nums)
    {
        hash[pokemon]++;
    }
    
    answer = min((nums.size() / 2),hash.size());
    
    return answer;
}