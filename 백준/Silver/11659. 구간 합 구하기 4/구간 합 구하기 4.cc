#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	int* num = new int[N+1];
	int* sum = new int[N+1];
	sum[0] = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
		sum[i + 1] = sum[i] + num[i];
	}

	while (M--)
	{
		int start, end = 0;
		cin >> start >> end;
		cout << sum[end] - sum[start-1] << "\n";
	}
}