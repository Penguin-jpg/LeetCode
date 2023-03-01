#include <vector>
using namespace std;

/**
 * 參考解答: 改用 color 紀錄三種狀態：
 *      WHITE: 未走訪
 *      GRAY: 走訪中(在 stack 內)
 *      BLACK: 走完了
 * 用這樣的方式可以省掉不需要 visited 和 inStack 陣列，只需要一個 color 陣列，直接用三種狀態紀錄
 * 時間: O(V+E), V: 節點數(也就是 n); E: 邊數(看 prerequisites 有幾個相連), 空間: O(V+E)
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
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        return !hasCycle(graph);
    }

    bool hasCycleHelper(vector<vector<int>> &graph, int node, vector<Color> &color)
    {
        if (color[node] == GRAY) // current node is already in recursive stack, which means there is a cycle
        {
            return true;
        }
        else if (color[node] == BLACK) // already visited, don't need to do it again
        {
            return false;
        }
        color[node] = GRAY;
        for (int i = 0; i < graph[node].size(); i++)
        {
            if (hasCycleHelper(graph, graph[node][i], color))
            {
                return true;
            }
        }
        color[node] = BLACK; // end of recursion, remove node out of stack
        return false;
    }

    bool hasCycle(vector<vector<int>> &graph)
    {
        vector<Color> color(graph.size(), WHITE);
        for (int i = 0; i < graph.size(); i++)
        {
            if (hasCycleHelper(graph, i, color))
            {
                return true;
            }
        }
        return false;
    }
};