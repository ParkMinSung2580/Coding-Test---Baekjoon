#include <iostream>

using namespace std;

void swap(int& a,int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int N, M;
	cin >> N >> M;

	int* arr = new int[N+1];

	for (int i = 1; i < N + 1; i++)
	{
		arr[i] = i;
	}

	for (int i = 1; i < M + 1; i++)
	{
		int a, b;
		cin >> a >> b;
		swap(arr[a], arr[b]);
	}

	for (int i = 1; i < N + 1; i++)
	{
		cout << arr[i] << "\n";
	}
}