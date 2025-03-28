#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		string input;
		cin >> input;
		stack<char> st;
		string answer = "YES";

		for (int j = 0; j < input.length();j++) {
			if (input[j] == '(') {
				st.push(input[j]);
			}
			else if(!st.empty() && input[j] == ')') {
				st.pop();
			}
			else {
				answer = "NO";
			}
		}
		if (!st.empty()){
			answer = "NO";
		}
		cout << answer << endl;
	}
}