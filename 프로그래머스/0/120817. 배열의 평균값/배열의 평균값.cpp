#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    for(auto a : numbers)
    {
        answer += a;
    }
    answer = answer / numbers.size();
    return answer;
}