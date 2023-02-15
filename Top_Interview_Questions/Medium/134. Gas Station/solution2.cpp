#include <vector>
using namespace std;

/**
 * 參考解答: 透過證明可知若
 * gas[0]-cost[0]+gas[1]-cost[1]+...+gas[i]-cost[i]>=0，則必存在一個起始點 i+1
 * 使 gas[i+1]-cost[i+1]+...+gas[n-1]-cost[n-1]+gas[0]-cost[0]+gas[1]-cost[1]+...+gas[j]-cost[j]>=0, 0<=j<=i，
 * 詳細證明可看這個連結：https://leetcode.com/problems/gas-station/solutions/42572/proof-of-if-total-gas-is-greater-than-total-cost-there-is-a-solution-c/
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
            // if totalSum is smaller than subSum, it means that when we go from
            // current start point, there will be a negative gas[k]-cost[k] exists.
            // if every gas[k]-cost[k]>=0, totalSum should always be greater
            // than sumSum
            if (totalSum < subSum)
            {
                subSum = totalSum; // update subSum
                start = i + 1;     // to next start point
            }
        }
        // if totalSum < 0, means that there is no way we can travel clockwise and back to start point
        // if totalSum >=0, means that there exists a start point can make this happen
        return totalSum < 0 ? -1 : start % gas.size();
    }
};