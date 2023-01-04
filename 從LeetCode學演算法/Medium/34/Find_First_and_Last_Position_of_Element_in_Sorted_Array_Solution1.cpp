class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        /*
            參考的方法1
            時間複雜度O(log(n))、空間複雜度O(1)
            做兩次二元搜尋法，第一次用來找下界，第二次用來找上界
        */
       
        int begin=0;
        int end=nums.size()-1;
        int mid=(begin+end)/2;
        int lower=-1;
        int upper=-1;
        
        while(begin<=end)
        {
            if(nums[mid]==target)
            {
                lower=mid;
                end=mid-1; //搜尋左半邊找下界(因為如果還有更小的，就一定在更左邊)
            }else if(nums[mid]<target)
            {
                begin=mid+1;
            }else
            {
                end=mid-1;
            }
            
            mid=(begin+end)/2;
        }
        
        if(lower==-1)
        {
            return {-1,-1};
        }
        
        begin=0;
        end=nums.size()-1;
        
        while(begin<=end)
        {
            if(nums[mid]==target)
            {
                upper=mid;
                begin=mid+1; //搜尋右半邊找上界(因為如果還有更大的，就一定在更右邊)
            }else if(nums[mid]<target)
            {
                begin=mid+1;
            }else
            {
                end=mid-1;
            }
            
            mid=(begin+end)/2;
        }
        
        return {lower,upper};
    }
};