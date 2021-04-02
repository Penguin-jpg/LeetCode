class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        /*
            我的方法2
            複雜度O(logn)，利用二元搜尋法做搜尋
        */
        return binarySearch(nums,target);
    }
    
    int binarySearch(vector<int>& nums, int target)
    {
        //下界
        int left=0;
        //上界
        int right=nums.size()-1;
        //中點
        int mid=(left+right)/2;
        
        while(left<right)
        {
            //如果目標比中點位置的數小，就將代表下界到中點都比中點位置小
            if(nums[mid]<target)
            {
                left=mid+1;
            }else if(nums[mid]>target)//如果目標比中點位置的數大，就將代表中點到上界都比中點位置大
            {
                right=mid-1;   
            }else
            {
                return mid;
            }
            mid=(left+right)/2;
        }
        
        //目標不在陣列裡的話，額外判斷插入位置
        if(target>nums[mid])
        {
            return mid+1;
        }else 
        {
            return mid;
        }
    }
};