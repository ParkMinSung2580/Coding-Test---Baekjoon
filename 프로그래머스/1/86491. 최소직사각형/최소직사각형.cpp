#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int width = 0;
    int height = 0;
    
    for(int i = 0; i < sizes.size(); i++)
    {
        if(sizes[i][0] < sizes[i][1])
        {
            swap(sizes[i][0],sizes[i][1]);
        }
        if(sizes[i][0] > width)
        {
            width = sizes[i][0];
        }
        if(sizes[i][1] > height)
        {
            height = sizes[i][1];
        }
    }
    answer = height * width;
    return answer;
}