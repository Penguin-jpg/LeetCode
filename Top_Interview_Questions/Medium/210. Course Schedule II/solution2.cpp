#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

/**
 * 參考解答: 改用 DFS，path 的插入時機為遞迴結束時
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

    bool hasCycle(vector<vector<int>> &graph, int node, vector<bool> &visited, vector<bool> &inStack, vector<int> &path)
    {
        if (inStack[node]) // found cycle
        {
            return true;
        }
        else if (visited[node]) // already visited
        {
            return false;
        }
        visited[node] = true, inStack[node] = true;
        for (int i = 0; i < graph[node].size(); i++)
        {
            if (hasCycle(graph, graph[node][i], visited, inStack, path))
            {
                return true;
            }
        }
        inStack[node] = false; // end of recursion
        path.push_back(node);
        return false;
    }

    vector<int> topologicalSort(vector<vector<int>> &graph)
    {
        vector<bool> visited(graph.size(), false);
        vector<bool> inStack(graph.size(), false);
        vector<int> path;
        for (int i = 0; i < graph.size(); i++)
        {
            if (hasCycle(graph, i, visited, inStack, path))
            {
                return {};
            }
        }
        // because of order of stack, we need to reverse path
        reverse(path.begin(), path.end());
        return path;
    }
};