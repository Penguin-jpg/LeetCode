class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        /*
            參考的方法2
            時間複雜度O(n)、空間複雜度O(1)
            上一個方法的簡化版，只要左邊指到的數為基數就交換，
            換完後就把right減1，如果左邊不是奇數，就遞增left
        */

        int left=0;
        int right=nums.size()-1;
        
        while(left<right)
        {
            if(nums[left]%2!=0)
            {
                swap(nums[left],nums[right]);
                right--;
            }else
            {
                left++;
            }
        }
        
        return nums;
    }
};