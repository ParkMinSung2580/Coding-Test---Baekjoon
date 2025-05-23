#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int k) {
    vector<int> answer;
    int count = k;
    for(int i = 1; count <= n; i++)
    {       
        count = k*i;
        if(count <= n)
        answer.push_back(k*i);
    }
    return answer;
}