class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /*
            參考的方法3
            時間複雜度O(n*2^n)、空間複雜度O(n)
        */

        vector<vector<int>> results;
        int size=pow(2,nums.size());
        
        for(int i=0;i<size;i++)
        {
            int mask=i; //遮罩(用來看現在的數要不要加到subset)
            int index=0;
            vector<int> subset;
            
            /*
                power set總共會有2^n個元素
                以n=3為例，總用有2^3=8個元素(index=0~7)
                又可以看成000,001,010,...,111
                power set={{},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}}
                方法為mask最右邊的位元和1取交集，如果是1，則將該數加入subset，並將mask右移一個位元
                例子:
                    1. 101最右邊為1 -> 和1取交集為1 -> 將nums[index=0]加入subset -> mask=010
                    2. 010最右邊為0 -> 和1取交集為0 -> 不將nums[index=1]加入subset -> mask=001
                    3. 001最右邊為1 -> 和1取交集為1 -> 將nums[index=2]加入subset -> mask=000
                    4. 停止 -> subset={1,3}(以power set來看第5(也就是101)個元素剛好是{1,3})
            */
            while(mask>0)
            {
                if(mask&1) //看mask最右邊的位元和1取交集是否為1
                {
                    subset.push_back(nums[index]);
                }
                mask=mask>>1; //將mask右移一個位元
                index++;
            }
            
            results.push_back(subset);
        }
        
        return results;
    }
};