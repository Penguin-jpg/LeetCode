class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        /*
            我的方法1
            複雜度O(n^2)，利用兩層迴圈判定
        */
        //紀錄索引碼
        int index=0;

        //檢查是否能在陣列內找到
        for(int n=0;n<nums.size();n++)
        {
            if(nums[n]==target)
            {
                index=n;
                return index;
            }
        }

        //插入目標並重新排序
        nums.push_back(target);
        sort(nums.begin(),nums.end());

        for(int n=0;n<nums.size();n++)
        {
            if(nums[n]==target)
            {
                index=n;
            }
        }
        
        return index;
    }
};