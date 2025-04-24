#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string str; 	
	cin >> str >> n;

	int sum[26][200001] = { 0 }; //배열초기화

	//누적 합 및 sum[0]값 초기화
	for (int i = 0; i < 26 ; i++)
	{
		sum[i][0] = 0;
	}
	

	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			// 이전까지의 누적값 복사
			sum[j][i + 1] = sum[j][i];
		}

		//현재 문자 확인해서 sum[문자열][누적합]에 값 추가
		int chIndex = str[i] - 'a'; 
		sum[chIndex][i + 1]++;
	}

	
	while (n--)
	{
		char ch;
		int start, end;
		cin >> ch >> start >> end;
		int chIndex = ch - 'a';
		// 알파벳 별로 배열 메모리 만들어서 sum을 통한 각 구간별 a의 개수를 설정해주기
		cout << sum[chIndex][end+1] - sum[chIndex][start] << "\n";
	}
}