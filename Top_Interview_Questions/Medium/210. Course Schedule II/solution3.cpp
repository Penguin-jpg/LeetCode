#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

/**
 * 想法: 改用 DFS 配上 color
 * 時間: O(V+E), V: 點數(n); E: 邊數(相關的課程數量) 空間: O(n*m), m: 最多的先修課程數量
 */

enum Color
{
    WHITE,
    GRAY,
    BLACK
};

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

    bool hasCycle(vector<vector<int>> &graph, int node, vector<Color> &color, vector<int> &path)
    {
        if (color[node] == GRAY) // found cycle
        {
            return true;
        }
        else if (color[node] == BLACK) // already visited
        {
            return false;
        }
        color[node] = GRAY;
        for (int i = 0; i < graph[node].size(); i++)
        {
            if (hasCycle(graph, graph[node][i], color, path))
            {
                return true;
            }
        }
        color[node] = BLACK; // end of recursion
        path.push_back(node);
        return false;
    }

    vector<int> topologicalSort(vector<vector<int>> &graph)
    {
        vector<Color> color(graph.size(), WHITE);
        vector<int> path;
        for (int i = 0; i < graph.size(); i++)
        {
            if (hasCycle(graph, i, color, path))
            {
                return {};
            }
        }
        // because of order of stack, we need to reverse path
        reverse(path.begin(), path.end());
        return path;
    }
};