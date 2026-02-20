#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T = 0; 
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int R = 0; string S;
		cin >> R >> S;

		for (char c : S)
		{
			for (int i = 0; i < R; i++)
			{
				cout << c;
			}
		}
		cout << endl;
	}
}