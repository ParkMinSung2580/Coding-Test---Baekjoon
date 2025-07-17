#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int answer = 0;
    int count = 0;
    
    for (bool flag : included)
    {
        if(flag)
        {
            answer += a + (d * count);
            count++;
        }
        else
        {
            count++;
        }
    }
    
    return answer;
}