class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
            參考的方法
            Kadane's algorithm(用來處理找最大子數列的問題)
            複雜度O(n)
        */
        int max=nums[0];//目前的最大值
        int current=nums[0];//包含第n個元素的最大值
        int len=nums.size();
        
        for(int n=1;n<len;n++)
        {
            current+=nums[n];
            /*
            如果current比nums[n+1]還小，
            代表目前的連續子字串必須重新從nums[n+1]重新開始找;
            如果current<0，代表最大值因為加了負的數導致變小，
            所以目前的連續子字串必須從nums[n+1]重新開始找
            */
            if(current<nums[n]||current<0)
            {
                current=nums[n];
            }
            
            //更新最大值
            if(current>max)
            {
                max=current;
            }
        }
        
        return max;
    }
};