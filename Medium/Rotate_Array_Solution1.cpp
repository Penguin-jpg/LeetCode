class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
            我的方法
            時間複雜度O(n)、空間複雜度O(n)
            按照移動過的index存成新陣列，再將新陣列傳給nums
        */

        if(k==0)
        {
            return;
        }
        
        vector<int> temp(nums.size(),0);
        
        //算出新的index
        for(int n=0;n<nums.size();n++)
        {
            temp[(n+k)%nums.size()]=nums[n];
        }
        
        //傳給nums
        nums=temp;
    }
};