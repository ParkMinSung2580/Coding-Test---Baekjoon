#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> count(26, 0);   //a~z까지 수 - 가장많이쓴거 대소 구분없이 카운팅이므로 
    string input;

    cin >> input;

    for (char c : input)
    {
        c = toupper(c);     //대문자 변환
        count[c - 'A']++;
    }

    //최대값이 두번이상 나오면 ?처리 해야함
    //최대값을 구하고 같은 개수의 값이 또존재하면 bool값으로 판단할 수 있도록
    //최고값 갱신되면 다시 bool값 초기화

    int maxVal = 0;
    int maxIndex = -1;
    bool IsDuplicate = false;

    for (int i = 0; i < 26; i++)
    {
        if (count[i] > maxVal)
        {
            maxVal = count[i];
            maxIndex = i;
            IsDuplicate = false;
        }
        else if (count[i] == maxVal)
        {
            IsDuplicate = true;
        }
    }

    if (IsDuplicate)
        cout << "?";
    else
        cout << char(maxIndex + 'A');
}