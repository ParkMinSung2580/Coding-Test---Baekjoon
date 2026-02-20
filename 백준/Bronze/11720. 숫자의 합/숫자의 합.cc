#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;

    string s;
    cin >> s;

    int sum = 0;

    for (char c : s)
    {
        sum += c - '0';
    }

    cout << sum;
}