class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
            我的方法1
            時間複雜度O(n^2)、空間複雜度O(1)
        */

        int missing=0;
        for(int i=1;i<nums.size()+1;i++)
        {
            if(find(nums.begin(),nums.end(),i)==nums.end())
            {
                missing=i;
                break;
            }
        }
        
        return missing;
    }
};