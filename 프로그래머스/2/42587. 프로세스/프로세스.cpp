#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int count = 0;
    
    while(priorities.size() > 0) {
        int max = *max_element(priorities.begin(), priorities.end());
        
        if(priorities[0] == max) {
            count++;
            if(location == 0) break;
            priorities.erase(priorities.begin());
            location--;
        } else {
            priorities.push_back(priorities[0]);
            priorities.erase(priorities.begin());
            location = (location == 0) ? priorities.size() - 1 : location - 1;
        }
    }
    
    return count;
}
    
    