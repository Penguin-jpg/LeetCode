#include <queue>
#include <vector>
using namespace std;

/**
 * 參考解答: 改用 BFS 來做，概念就是做拓撲排序，將所有節點的 in-dgree 找出，並將
 * 所有 in-degree 為 0 的節點放到 queuq，在 queue 為空之前，進入並將 counter+1，
 * 再把所有相連節點的 in-degree-1，若減一後為 0，一樣要放到 queue，由於拓撲排序必
 * 定會走過每個節點，所以若最後 counter=numCourses，則代表能完整做完拓撲排序，也
 * 就是沒有 cycle
 * 時間: O(V+E), V: 節點數(也就是 n); E: 邊數(看 prerequisites 有幾個相連), 空間: O(V+E)
 */

class Solution
{
  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        return !hasCycle(graph, numCourses);
    }

    bool hasCycle(vector<vector<int>> &graph, int n)
    {
        vector<int> indegree(n, 0);
        queue<int> nodes;
        int counter = 0; // number of visited nodes
        // compute in-degree
        for (int i = 0; i < graph.size(); i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                indegree[graph[i][j]]++;
            }
        }
        // push nodes with in-degree=0
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                nodes.push(i);
            }
        }
        // simulate topological sort (we are not really doing it)
        while (!nodes.empty())
        {
            int node = nodes.front();
            nodes.pop();
            counter++;
            for (int i = 0; i < graph[node].size(); i++)
            {
                indegree[graph[node][i]]--;
                if (indegree[graph[node][i]] == 0)
                {
                    nodes.push(graph[node][i]);
                }
            }
        }
        // if counter==n, it means that topological sort succeed
        // else it means that we cannot visit all nodes and topological sort failed
        return counter != n;
    }
};