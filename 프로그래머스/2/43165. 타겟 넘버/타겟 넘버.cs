using System;
    
public class Solution {
    public int solution(int[] numbers, int target) {            
        int answer = 0;
        
        answer = DFS(0,0,numbers,target,ref answer);
        return answer;
    }
    /// <summary>
    /// 재귀를 통한 모든 경우의 수 탐색
    /// </summary>
    /// <param name="current_index_"> 현재 카드의 위치 인덱스 </param>
    /// <param name="current_index_"> 현재 까지의 누적total </param>
    public int DFS(int current_index, int current_sum,int[] numbers,int target,ref int answer)
    {
        //숫자를 다 썼는데 타겟과 같으면 answer 1증가
        if(current_index == numbers.Length)
            if(current_sum == target)
            {
                answer++;
            }
            else{ return 0; } //다 썼는데 같지 않으면 종료
        else //숫자를 다 안썼으면 
        {
            //다음 카드로 갈 때 조건 (+,- 두가지 경우의 수 존재)
            DFS(current_index + 1, current_sum + numbers[current_index], numbers, target, ref answer);
            
            DFS(current_index + 1, current_sum - numbers[current_index], numbers, target, ref answer);
        }
        
        return answer;
    }
}