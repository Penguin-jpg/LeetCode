#include <vector>
using namespace std;

/**
 * 想法: 觀察後可發現，只要有某堂課的先修是另一個還不能修的課程，就是 false，以
 * graph 來理解的話，就是有 cycle 產生，所以先將 prerequisites 轉成 graph，再用
 * DFS 檢查 graph 內是否有 cycle
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
        return !hasCycle(graph);
    }

    bool hasCycleHelper(vector<vector<int>> &graph, int node, vector<bool> &visited, vector<bool> &inStack)
    {
        if (inStack[node]) // current node is already in recursive stack, which means there is a cycle
        {
            return true;
        }
        else if (visited[node]) // already visited, don't need to do it again
        {
            return false;
        }
        visited[node] = true, inStack[node] = true;
        for (int i = 0; i < graph[node].size(); i++)
        {
            if (hasCycleHelper(graph, graph[node][i], visited, inStack))
            {
                return true;
            }
        }
        inStack[node] = false; // end of recursion, remove node out of stack
        return false;
    }

    bool hasCycle(vector<vector<int>> &graph)
    {
        vector<bool> visited(graph.size(), false);
        vector<bool> inStack(graph.size(), false);
        for (int i = 0; i < graph.size(); i++)
        {
            if (hasCycleHelper(graph, i, visited, inStack))
            {
                return true;
            }
        }
        return false;
    }
};