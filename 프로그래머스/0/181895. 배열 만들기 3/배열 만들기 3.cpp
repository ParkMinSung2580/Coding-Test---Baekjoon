#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    for(int i = 0; i < intervals.size(); i++)
    {
        for(int k = intervals[i][0]; k <= intervals[i][1]; k++)
        {
            answer.push_back(arr[k]);
        }
    }
    return answer;
}