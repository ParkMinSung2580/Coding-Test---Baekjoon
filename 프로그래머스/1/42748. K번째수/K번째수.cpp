#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(int i =0; i < commands.size(); i++)
    {
        vector<int> subarr = {};
        for(int j = commands[i][0] - 1; j < commands[i][1]; j++)
        {
            subarr.push_back(array[j]);
        }
        sort(subarr.begin(),subarr.end(),[](auto& a, auto& b) {
        return a < b;
        });
        answer.push_back(subarr[commands[i][2] -1]);
    }
    
    return answer;
}