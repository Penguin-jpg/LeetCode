class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
            參考的方法1
            時間複雜度O(n)、空間複雜度O(1)
            two pointers
        */

        if(nums.size()<3)
        {
            return nums.size();
        }
        
        int j=1; //要覆蓋的位置(覆蓋的效果類似把數字往前移動)
        int last=nums[0]; //最後重複的數
        int counter=1; //現在的數出現幾次
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=last) 
            {
                nums[j]=nums[i]; //覆蓋j位置的數
                last=nums[i]; //更新最後重複的數
                counter=1;
                j++;
            }else if(counter<2) //重複次數小於兩次
            {
                nums[j]=nums[i];
                counter++;
                j++;
            }
        }
        
        return j;
    }
};