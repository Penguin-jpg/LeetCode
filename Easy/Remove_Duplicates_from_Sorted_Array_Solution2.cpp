class Solution {
public:
    int removeDuplicates(vector<int>& nums) {  
        /*
            我的方法2
            每三個數為一組，檢查中間那個數的左邊及右邊，將相同的數移除
        */
        //數量小於2的不可能重複
        if(nums.size()<2)
        {
            return nums.size();
        }
        
        //檢查
        for(int n=1;n<=nums.size()-1;)
        {
            if(nums[n]==nums[n-1])
            {
                nums.erase(nums.begin()+(n-1));
                if((n+1)<nums.size()&&nums[n]==nums[n+1])
                {
                    nums.erase(nums.begin()+(n+1));
                }
            }else
            {
                n++;
            }    
        }

        return nums.size();
    }
};