#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stack<pair<int,int>> s;
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int height;
		cin >> height;
				
		//Input height와 스택 top위치에 있는 height와 비교해서 만약 내가 더크면 pop()
		//계속확인
		while (!s.empty() && s.top().first < height) {
			s.pop();
		}

		//큐가 비어있으면 0출력 나보단 더큰놈이 스택에 존재하지 않기 때문에 아무도 못받음
		if (s.empty()) {
			cout << "0 ";
		} //받을 사람이 있으면 해당 탑의 인덱스값제공
		else {
			cout << s.top().second << " ";
		}
		//다음 input데이터를 위해 저장 //이전 데이터는 필요없다 어차피 나보다
		s.push({ height, i });
	}
}