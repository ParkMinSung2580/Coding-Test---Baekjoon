#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int idx = 0;
    
    while(idx < progresses.size()) {
        for(int i = idx; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }

        int count = 0;
        while(idx < progresses.size() && progresses[idx] >= 100) {
            count++;
            idx++;
        }

        if(count > 0) {
            answer.push_back(count);
        }
    }
    
    return answer;
}