class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
            參考的方法2
            時間複雜度O(n)、空間複雜度O(1)
            利用最多只能允許兩個重複數字的情況，當偵測到第三個時就做覆蓋
        */

        int i=0; //要覆蓋的位置
        
        for(int n: nums)
        {
            /*
                1. i<2的時候最多就兩個數字，不可能超出限制，可以直接覆蓋
                2. 因為已由小到大排序，當目前數字和要覆蓋位置的前兩個數字不同，
                   代表數字不同或重複不超過兩次，可以直接覆蓋
            */
            if(i<2||n>nums[i-2])
            {
                nums[i]=n;
                i++;
            }
        }
        
        return i;
    }
};