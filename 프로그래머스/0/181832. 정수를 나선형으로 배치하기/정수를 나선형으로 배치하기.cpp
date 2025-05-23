#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> solution(int n) {
    /*
    행(시작 -> 끝) -> 열(시작 ->끝) ->행(끝->시작) ->열(끝->시작-1)
    4번에 한바퀴 끝
    순서 → ↓ ← ↑  <- 한루틴
    */
    vector<vector<int>> answer(n, vector<int>(n, 0)); // n x n 2D 벡터 초기화
    int count = 1;
    int x = 0; int y = 0;
    
    char dic = 'r';       //right, down, left ,up
    
    while(count <= n * n)
    {
        answer[x][y] = count;
        count++;
        switch(dic)
        {
            case 'r':
                y += 1;
                if(y == n - 1 || answer[x][y+1] != 0)       //먼저 확인해야함 다음 좌표꺼를
                    dic = 'd';
                break;
            case 'd':
                x += 1;
                if(x == n - 1 || answer[x+1][y] != 0)
                    dic = 'l';
                break;
            case 'l':
                y -= 1;
                if(y == 0 || answer[x][y-1] != 0)        //왼쪽은 0일 때 까지나 다음 좌표값이 있을때 까지
                    dic = 'u';
                break;
            case 'u':
                x -= 1;
                if(x == 0 || answer[x-1][y] != 0)
                    dic = 'r';
                break;
        }
    }
    
    return answer;
}