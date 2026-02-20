#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int total = 0;

    //한번누르면 초기화인데 하나당 1초가 더걸린다고 생각
    for (char c : s)
    {
        if (c >= 'A' && c <= 'C') total += 3;
        else if (c <= 'F') total += 4;
        else if (c <= 'I') total += 5;
        else if (c <= 'L') total += 6;
        else if (c <= 'O') total += 7;
        else if (c <= 'S') total += 8;
        else if (c <= 'V') total += 9;
        else total += 10;
    }

    cout << total;
}