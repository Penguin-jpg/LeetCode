class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
            參考的做法
            使用Two Pointers，複雜度:O(n^2)
        */
        int len=nums.size();
        vector<vector<int>> ans;
        
        //檢查nums的大小能不能湊成3個數
        if(len<3)
        {
            return ans;
        }
        
        int j=0;
        int k=0;
        int target=0;
        
        //排序
        sort(nums.begin(),nums.begin()+len);
        
        //鎖定第一個數，從這個數後面找出與它相加為0的兩個數
        for(int i=0;i<len-2;i++)
        {
            //跳過重複元素
            if(i==0||(i>0&&nums[i]!=nums[i-1]))
            {
                //還需要(0-nums[i])來組成0
                target=0-nums[i];
                
                /*
                    Two pointers
                    (j:指向i後的第一個數(第二小值或等於nums[i]);k:指向nums的最後一個數(最大值)) 
                */
                j=i+1;
                k=len-1;
            
                while(j<k)
                {
                    if(nums[j]+nums[k]==target)
                    {
                        ans.push_back({nums[i],nums[j],nums[k]});
                        //跳過重複元素
                        while(j<k&&nums[j]==nums[j+1])
                        {
                            j++;
                        }
                        while(j<k&&nums[k]==nums[k-1])
                        {
                            k--;
                        }
                        j++;
                        k--;
                    }else if(nums[j]+nums[k]>target)
                    {
                        k--;
                    }else
                    {
                        j++;
                    }
                } 
            }
        }
        return ans;
    }
};