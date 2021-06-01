class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        /*
            參考的方法1
            時間複雜度O(n)、空間複雜度O(1)
            從最左邊開始，如果現在這格不是奇數就繼續往下找，
            從最右邊開始，如果現在這格不是偶數就繼續往下找，
            條件都符合就交換
        */

        int left=0;
        int right=nums.size()-1;
        
        while(left<right)
        {
            if(nums[left]%2==0)
            {
                left++;
                continue;
            }
            
            if(nums[right]%2!=0)
            {
                right--;
                continue;
            }
            
            swap(nums[left],nums[right]);
        }
        
        return nums;
    }
};