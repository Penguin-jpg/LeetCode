class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
            參考的方法1
            時間複雜度O(n)、空間複雜度O(1)
            先將整個陣列反轉，再將0~(k-1)及k~(nums.size()-1)各自反轉即為答案
        */
        if(k==0)
        {
            return;
        }
        
        k%=nums.size();
        
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};