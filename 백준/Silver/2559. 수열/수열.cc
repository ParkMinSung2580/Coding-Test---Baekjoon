#include <iostream>
using namespace std;

int main()
{
	int N, K;
	
	cin >> N >> K;

	int* num = new int[N];
	int* sum = new int[N+1];
	sum[0] = 0;
	
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
		sum[i + 1] = sum[i] + num[i];
	}

	
	int sumMax = 0;
	sumMax = sum[N] - sum[N-K];

	for (int i = N; i-K >= 0; i--)
	{
		if (sumMax < sum[i] - sum[i - K])
			sumMax = sum[i] - sum[i - K];	
	}
	cout << sumMax << endl;
}