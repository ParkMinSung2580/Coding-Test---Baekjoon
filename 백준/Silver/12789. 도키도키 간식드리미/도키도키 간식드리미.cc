#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	int num = 0;
	int count = 1;
	queue<int> low;
	stack<int> temp;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int input;
		cin >> input;
		low.push(input);
	}

    while (!low.empty())
    {
        if (low.front() == count)  //줄의 처음이 count면
        {
            low.pop();
            count++;
        }
        else if (!temp.empty() && temp.top() == count) //줄의 순서에 맞지 않고 스택이 비어있지 않을때 스택을 검사 -> 순서가 맞는 친구면 pop후 count 증가
        {
            temp.pop();
            count++;
        }
        else            //줄의 처음도 아니고 순서에 맞지도 않으면 일단 스택에 넣기
        {
            temp.push(low.front());
            low.pop();
        }
    }

    //두번째 스택을 처리 
    while (!temp.empty())
    {
        if (temp.top() == count) //만약 스택에 빼는데 스택 제일 앞의 순서가 과자를 받는 순서가 맞으면 pop후 순서 증가
        {
            temp.pop();
            count++;
        }
        else            //아니면 순서가 잘못된 친구가 받아야함으로 Sad 
        {
            cout << "Sad" << endl;
            return 0;
        }
    }

    //모든 조건 완결
	cout << "Nice" << endl;
}