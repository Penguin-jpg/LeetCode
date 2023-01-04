class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
            參考的方法1
            時間複雜度O(n)、空間複雜度O(1)
            紀錄0,1,2出現的次數，再重新放回陣列
        */

        int counter[3]={0};
        
        for(int i=0;i<nums.size();i++)
        {
            counter[nums[i]]++;
        }
        
        for(int i=0;i<counter[0];i++)
        {
            nums[i]=0;
        }
        
        for(int i=counter[0];i<counter[0]+counter[1];i++)
        {
            nums[i]=1;
        }
        
        for(int i=counter[0]+counter[1];i<counter[0]+counter[1]+counter[2];i++)
        {
            nums[i]=2;
        }      
    }
};