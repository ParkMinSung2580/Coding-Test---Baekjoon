using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Study.Backjoon
{
    internal class _24479
    {
        /*dfs(V, E, R) {
         # V : 정점 집합, E : 간선 집합, R : 시작 정점
        visited[R] < -YES;  # 시작 정점 R을 방문 했다고 표시한다.
        for each x ∈ E(R)  # E(R) : 정점 R의 인접 정점 집합.(정점 번호를 오름차순으로 방문한다)
            if (visited[x] = NO) then dfs(V, E, x);
        }*/
        // 그래프의 인접 리스트를 저장할 변수
        // 각 인덱스는 정점 번호를 나타내며, 해당 리스트에는 인접한 정점들이 저장됩니다.
        static List<List<int>> graph;
        // 방문 여부를 저장할 배열
        static bool[] visited;
        // 각 정점의 방문 순서를 저장할 배열
        static int[] visitOrder;
        // 방문 순서를 기록할 카운터
        static int orderCounter;

        static void Main(string[] args)
        {
            // 첫 번째 줄 입력: 정점의 수 N, 간선의 수 M, 시작 정점 R
            string[] firstLine = Console.ReadLine().Split();
            int N = int.Parse(firstLine[0]); // 정점의 수
            int M = int.Parse(firstLine[1]); // 간선의 수
            int R = int.Parse(firstLine[2]); // 시작 정점 (1부터 시작하므로 0-인덱스로 변환)

            // 그래프, 방문 여부, 방문 순서 배열 초기화
            graph = new List<List<int>>();
            for (int i = 0; i <= N; i++) // 정점 번호 1부터 N까지 사용하므로 N+1 크기로 초기화
            {
                graph.Add(new List<int>());
            }
            visited = new bool[N + 1];
            visitOrder = new int[N + 1];
            orderCounter = 1; // 방문 순서는 1부터 시작

            // 간선 정보 입력 및 그래프 구성
            for (int i = 0; i < M; i++)
            {
                string[] edge = Console.ReadLine().Split();
                int u = int.Parse(edge[0]); //시작
                int v = int.Parse(edge[1]); //도착

                // 양방향 간선 추가
                graph[u].Add(v);
                graph[v].Add(u);
            }

            //각 리스트방문 할 때 여러개의 노드중 방문 기준을 어떻게 할 것 인지
            //정렬하면 해당 정렬된 순서대로 방문 하게 된다.
            //오름차순 
            /*for (int i = 1; i <= N; i++)
            {
                graph[i].Sort((int a, int b) => { return a.CompareTo(b); });
            }*/

            //내림차순
            for (int i = 1; i <= N; i++)
            {
                graph[i].Sort((int a, int b) => { return b.CompareTo(a); });
            }

            // DFS 호출 (시작 정점 R) 
            DFS(R);
            StringBuilder sb = new StringBuilder();
            for (int i = 1; i <= N; i++)
            {
                sb.AppendLine(visitOrder[i].ToString());
            }
            Console.WriteLine(sb.ToString());

        }

        static void DFS(int currentNode)
        {
            /*dfs(V, E, R) {
            # V : 정점 집합, E : 간선 집합, R : 시작 정점
            visited[R] < -YES;  # 시작 정점 R을 방문 했다고 표시한다.
            for each x ∈ E(R)  # E(R) : 정점 R의 인접 정점 집합.(정점 번호를 오름차순으로 방문한다)
                if (visited[x] = NO) then dfs(V, E, x);
            }*/

            visited[currentNode] = true;
            visitOrder[currentNode] = orderCounter++; // 방문 순서 기록

            foreach (var x in graph[currentNode])
            {
                if (!visited[x])
                {
                    DFS(x);
                }
            }
        }
    }
}