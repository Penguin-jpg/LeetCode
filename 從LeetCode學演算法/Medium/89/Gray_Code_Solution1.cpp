class Solution {
public:
    vector<int> grayCode(int n) {
        /*
            參考的方法1
            複雜度(2^n)，雖然是用格雷瑪，但數列內要放的是用2進位計算的數
        */
        vector<int> nums;//數列
        int msb=1;//最左邊的位元(初始值為2^0=1)
        
        //最開始的數為0
        nums.push_back(0);
        
        for(int i=1;i<=n;i++)
        {
            for(int j=nums.size()-1;j>=0;j--)
            {
                /*
                運算方式為最大位元加上後面對稱的位元
                */
                nums.push_back(msb+nums[j]);
            }
            
            //做完一次後，最大位元就要變2倍(格雷碼規律)
            msb*=2;
        }
        
        return nums;
    }
};