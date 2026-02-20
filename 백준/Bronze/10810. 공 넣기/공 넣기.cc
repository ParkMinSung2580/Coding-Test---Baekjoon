#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    int *array = new int[N]; 
    
    for(int i = 0; i < M; i++)
	{
		int I,J,K;
		cin >> I >> J >> K;
		for(int start = I - 1; start <= J - 1; start++)
        {
            array[start] = K;
        }
	}
    
    // 결과 출력
    for(int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}