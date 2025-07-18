using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Study.Backjoon
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Graph<int> graph = new Graph<int>();
            GraphNode<int> inputNode;

            string input1 = Console.ReadLine(); //컴퓨터 개수
            string input2 = Console.ReadLine(); //간선의 개수

            int number1, number2;
            int.TryParse(input1, out number1);
            int.TryParse(input2, out number2);


            //그래프 정점 추가
            for (int i = 0; i < number1; i++)
            {
                graph.AddNode(i);
            }

            //그래프 간선 추가
            for (int i = 0; i < number2; i++)
            {
                // 1. 입력 받기
                string[] edge = Console.ReadLine().Split();

                int a = int.Parse(edge[0]) - 1; // 1-based 입력이면 -1 해주기
                int b = int.Parse(edge[1]) - 1;

                // 2. 그래프에서 노드 찾기
                if (graph.TryGetNode(a, out GraphNode<int> nodeA) &&
                    graph.TryGetNode(b, out GraphNode<int> nodeB))
                {
                    // 3. 중복 연결 방지 & 간선 추가 (양방향)
                    if (!nodeA.IsConnect(nodeB)) nodeA.AddEdge(nodeB);
                    if (!nodeB.IsConnect(nodeA)) nodeB.AddEdge(nodeA);
                }
            }

            graph.TryGetNode(0, out inputNode);
            //방문한 노드
            int answer = BFS(inputNode);
            Console.WriteLine(answer);
        }

        static int BFS(GraphNode<int> start)
        {
            var visited = new HashSet<GraphNode<int>>();
            var queue = new Queue<GraphNode<int>>();
            queue.Enqueue(start);
            visited.Add(start);

            int count = 0;

            while (queue.Count > 0)
            {
                var current = queue.Dequeue();
                foreach (var neighbor in current.edges)
                {
                    if (!visited.Contains(neighbor))
                    {
                        visited.Add(neighbor);
                        queue.Enqueue(neighbor);
                        count++;
                    }
                }
            }

            return count;
        }
    }

    public class GraphNode<T>
    {
        public T Value { get; set; }
        public List<GraphNode<T>> edges = new List<GraphNode<T>>();

        public GraphNode(T value)
        {
            Value = value;
        }

        public void AddEdge(GraphNode<T> node)
        {
            edges.Add(node);
        }

        public void RemoveEdge(GraphNode<T> node)
        {
            edges.Remove(node);
        }

        public bool IsConnect(GraphNode<T> node)
        {
            return edges.Contains(node);
        }
    }

    public class Graph<T>
    {
        private List<GraphNode<T>> _nodes = new();

        public GraphNode<T> AddNode(T value)
        {
            GraphNode<T> node = new(value);
            _nodes.Add(node);
            return node;
        }

        public void AddEdge(GraphNode<T> from,GraphNode<T> to)
        {
            from.AddEdge(to);
        }

        public void RemoveNode(GraphNode<T> node)
        {
            //정점 노드들을 순회하면서 해당 노드와의 연결 리스트를 삭제
            foreach(var n in _nodes)
            {
                n.RemoveEdge(node);
            }

            //마지막으로 그래프에서도 삭제
            _nodes.Remove(node);
        }

        //특정 노드를 찾는 식
        public bool TryGetNode(T value, out GraphNode<T> result)
        {
            foreach (var node in _nodes)
            {
                if (EqualityComparer<T>.Default.Equals(node.Value, value))
                {
                    result = node;
                    return true;
                }
            }
            result = null;
            return false;
        }
    }
}