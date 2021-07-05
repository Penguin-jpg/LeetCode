class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        /*
            參考的方法2
            時間複雜度O(log(n))、空間複雜度O(1)
        */

        int begin=0;
        int end=nums.size()-1;
        int mid=(begin+end)/2;
        vector<int> pos(2,-1);
        int index=-1;
        
        while(begin<=end)
        {
            if(nums[mid]==target)
            {
                index=mid;
                break;
            }else if(nums[mid]<target)
            {
                begin=mid+1;
            }else
            {
                end=mid-1;
            }
            
            mid=(begin+end)/2;
        }
        
        if(index==-1)
        {
            return pos;
        }
        
        while(index-1>=0&&nums[index-1]==target) //看左邊有沒有更小的
        {
            index--;
        }
        
        pos[0]=index;
        index=mid;
        
        while(index+1<nums.size()&&nums[index+1]==target) //看右邊有沒有更大的
        {
            index++;
        }
        
        pos[1]=index;
        
        return pos;
    }
};