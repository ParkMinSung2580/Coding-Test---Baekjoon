#include <iostream>
#include <string>
using namespace std;

bool isStringDigit(const string& str) {
	for (char c : str) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return !str.empty();  // 빈 문자열이 아닌 경우에만 true
}

int main()
{
	string arr[3];
	int answer;
	bool notfound = false;
	for (int i = 0; i < 3; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 3; i++)
	{
		if (isStringDigit(arr[i]))
		{
			answer = stoi(arr[i]) + (3 - i);
		}
		else {
			notfound = true;
		}
	}
	//숫자열을 찾지 못하면 
	if (!notfound)
	{
		cout << arr[0] << "\n";
	}
	else
	{
		if ((answer % 3 == 0) && (answer % 5 == 0))
		{
			cout << "FizzBuzz" << "\n";
		}
		else if ((answer % 3 == 0) || (answer % 5 == 0))
		{
			if (answer % 3 == 0)
				cout << "Fizz" << "\n";
			if (answer % 5 == 0)
				cout << "Buzz" << "\n";
		}
		else
		{
			cout << answer << endl;
		}
	}
}