#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<bool> submitted(30, false);
    int input = 0;

    for (int i = 0; i < 28; i++)
    {
        cin >> input;
        submitted[input - 1] = true;
    }

    for (int i = 0; i < 30; i++)
    {
        if (!submitted[i])
            cout << i + 1 << "\n";
    }
}