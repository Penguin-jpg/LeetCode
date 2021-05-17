class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /*
            我的方法1
            時間複雜度O(n^2)、空間複雜度(the number of majority elements)
            先將所有majority elements存到set，再轉成vector
        */

        set<int> elements;
        int third=nums.size()/3;
        int result=0;
        int counter=0;
        
        for(int n=0;n<nums.size();n++)
        {
            if(elements.find(nums[n])!=elements.end())
            {
                continue;
            }
            result=nums[n];
            for(int k=0;k<nums.size();k++)
            {
                if(result==nums[k])
                {
                    counter++;
                }
            }
            
            if(counter>third)
            {
                elements.insert(result);
            }
            counter=0;
        }
        
        return vector<int>(elements.begin(),elements.end());
    }
};