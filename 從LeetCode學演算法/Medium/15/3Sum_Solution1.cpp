class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
            我的方法
            複雜度:O(n^3)，會超時
        */
        int len=nums.size();
        vector<vector<int>> ans;

        //先檢查nums的大小夠不夠湊成3個
        if(len<3)
        {
            return ans;
        }
        
        vector<int> temp;
        int sum=0;
        
        //將元素排序(這樣在push進temp時就不用重新排序)
        sort(nums.begin(),nums.begin()+len);
         
        for(int i=0;i<len;i++)
        {
            temp.reserve(3);
            sum=nums[i];
            for(int j=i+1;j<len;j++)
            {
                sum+=nums[j];
                for(int k=j+1;k<len;k++)
                {
                    if(sum+nums[k]==0)
                    {
                        temp.emplace_back(nums[i]);
                        temp.emplace_back(nums[j]);
                        temp.emplace_back(nums[k]);
                        ans.push_back(temp);
                        temp.clear();
                    }
                }
                sum=nums[i];
            }
        }

        //將ans排序
        sort(ans.begin(),ans.end());
        //去除重複元素
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};