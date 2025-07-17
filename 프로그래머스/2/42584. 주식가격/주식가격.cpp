#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    //배열의 크기만큼 모든 원소를 0으로 초기화
    vector<int> answer(prices.size());

    for (int i = 0; i < prices.size(); i++) {
        for (int j = i + 1; j < prices.size(); j++) {
            answer[i]++;
            if (prices[j] < prices[i]) break;
        }
    }

    return answer;
}