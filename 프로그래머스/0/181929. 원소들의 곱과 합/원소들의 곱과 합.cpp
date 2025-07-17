#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int sum = 0;
    int mul = 1;
    
    for(auto a : num_list)
    {
        sum += a;
        mul *= a;
    }
    
    if(mul < sum*sum)
        return 1;
    else
        return 0;
}