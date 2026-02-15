#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer = num_list;

    int last = num_list[num_list.size() - 1];
    int prev = num_list[num_list.size() - 2];

    int n = (last > prev) ? (last - prev) : (last * 2);

    answer.push_back(n);
    return answer;
}