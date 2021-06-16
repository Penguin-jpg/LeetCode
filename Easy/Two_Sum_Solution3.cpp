class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
            參考的方法2
            時間複雜度O(nlog(n))、空間複雜度O(n)
        */

        vector<int> ans(2);
        int i=0;
        int j=nums.size()-1;
        vector<pair<int,int>> temp(nums.size());
        
        for(int n=0;n<nums.size();n++)
        {
            temp[n]=make_pair(nums[n],n);
        }
        
        sort(temp.begin(),temp.end(),cmp);
        
        
        while(i<j)
        {
            if(target-temp[i].first==temp[j].first)
            {
                ans[0]=temp[i].second;
                ans[1]=temp[j].second;
                break;
            }else if(target-temp[i].first<temp[j].first)
            {
                j--;
            }else
            {
                i++;
            }
        }
        
        return ans;
    }
    
    static bool cmp(pair<int,int> p1,pair<int,int> p2)
    {
        return p1.first<p2.first;
    }
};