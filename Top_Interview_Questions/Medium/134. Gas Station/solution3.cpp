#include <vector>
using namespace std;

/**
 * 參考解答: 用另一種角度來看solution2 subSum的部分
 * 時間: O(n), 空間: O(1)
 */

class Solution
{
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int totalSum = 0; // total sum of gas[i]-cost[i] for i=0,1,...,n-1
        int subSum = 0;   // sum of gas[j]-cost[j] for j=0,1,...,i
        int start = 0;    // start point
        for (int i = 0; i < gas.size(); i++)
        {
            totalSum += gas[i] - cost[i];
            subSum += gas[i] - cost[i];
            // if subSum < 0, means that gas[0]-cost[0]+gas[1]-cost[1]+...+gas[j]-cost[j] < 0, 0<=j<=i
            // there is no way we can start from i can finish the trip
            if (subSum < 0)
            {
                subSum = 0;    // initialize subSum
                start = i + 1; // to next start point
            }
        }
        // if totalSum < 0, means that there is no way we can travel clockwise and back to start point
        // if totalSum >=0, means that there exists a start point can make this happen
        return totalSum < 0 ? -1 : start % gas.size();
    }
};