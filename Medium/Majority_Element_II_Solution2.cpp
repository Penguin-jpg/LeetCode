class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /*
            我的方法2
            時間複雜度O(n)、空間複雜度O(n)
            用unordered_map儲存每個數字出現的次數，再找出majority elements
        */

        unordered_map<int,int> elements;
        vector<int> results;
        int third=nums.size()/3;
        unordered_map<int,int>::iterator it;
        
        for(int n=0;n<nums.size();n++)
        {
            elements[nums[n]]++;
        }
        
        for(it=elements.begin();it!=elements.end();it++)
        {
            if(it->second>third)
            {
                results.push_back(it->first);
            }
        }
        
        return results;
    }
};