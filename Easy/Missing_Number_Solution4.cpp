class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
            參考的方法1
            時間複雜度O(n)、空間複雜度O(1)
            利用XOR
            例子:
            nums={0,1,3,4}(size=4)
            則missing=size^(index0^value0)^(index1^value1)^...
            -> 4^(0^0)^(1^1)^(2^3)^(3^4)=2^(0^0)^(1^1)^(3^3)^(4^4)=2
        */

        int missing=nums.size();
        
        for(int i=0;i<nums.size();i++)
        {
            missing^=i^nums[i];
        }
        
        return missing;
    }
};