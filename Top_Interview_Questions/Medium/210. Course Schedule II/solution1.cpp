#include <queue>
#include <vector>
using namespace std;

/**
 * 想法: 因為除了要確定課程表是否valid，還要印出順序，所以使用 topological sort
 * (用 BFS 做)會比較直覺，因為能同時得出是否 valid 以及 valid path
 * 時間: O(V+E), V: 點數(n); E: 邊數(相關的課程數量) 空間: O(n*m), m: 最多的先修課程數量
 */

class Solution
{
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        return topologicalSort(graph);
    }

    vector<int> topologicalSort(vector<vector<int>> &graph)
    {
        vector<int> indegree(graph.size(), 0);
        queue<int> nodes;
        vector<int> path;
        // compute in-degree
        for (int i = 0; i < graph.size(); i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                indegree[graph[i][j]]++;
            }
        }
        // push all nodes with in-degree=0 (don't have any prerequisites)
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                nodes.push(i);
            }
        }
        int counter = 0; // counter to check if we traverse all nodes
        // topological sort
        while (!nodes.empty())
        {
            int node = nodes.front();
            nodes.pop();
            path.push_back(node); // push this node to path
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
        return counter == graph.size() ? path : vector<int>();
    }
};