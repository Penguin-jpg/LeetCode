#include <vector>
using namespace std;

/**
 * 想法: 暴搜，把 gas[i] >= cost[i] 的地方當做起點，全部找一遍就會有答案了 (TLE)
 * 時間: O(n^2), 空間: O(1)
 */

class Solution
{
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int j = 0, k = 0, currentGas = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            if (gas[i] >= cost[i])
            {
                currentGas = gas[i];
                j = (i + 1) % gas.size(), k = i;
                while (j != i)
                {
                    currentGas -= cost[k];
                    if (currentGas < 0)
                    {
                        break;
                    }
                    currentGas += gas[j];
                    j = (j + 1) % gas.size();
                    k = (k + 1) % gas.size();
                }
                // check if we can go back to starting point
                if (currentGas >= cost[k])
                {
                    return i;
                }
            }
        }
        return -1;
    }
};