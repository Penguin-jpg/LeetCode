class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
            參考的方法1
            時間複雜度O(n)、空間複雜度O(1)
            利用XOR的特性(a XOR a = 0、a XOR 0 = a -> a XOR (b XOR b) = a XOR 0 = a)，
            當全部數字做XOR後，最後答案只會留下只做一次XOR的那個數
        */
        
        int ans=0;
        
        for(int n=0;n<nums.size();n++)
        {
            ans^=nums[n];
        }
        
        return ans;
    }
};