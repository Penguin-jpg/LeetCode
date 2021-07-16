class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        /*
            我的方法1
            時間複雜度O(2^n)、空間複雜度O(n)
            利用power set的解法，但這題是mask有k個bit為1的才需要加入陣列，
            所以就利用bitset將i轉換成二進位後檢查1的數量，數量等於k的話就做
        */

        vector<vector<int>> results;
        vector<int> nums(n);
        
        for(int i=0;i<n;i++)
        {
            nums[i]=i+1;
        }
        
        if(n==k)
        {
            results.push_back(nums);
            return results;
        }
        
        int size=pow(2,n);
        for(int i=0;i<size;i++)
        {
            bitset<32> set(i);
            if(set.count()==k) //計算1的數量
            {
                int current=i;
                int index=0;
                int combIndex=0;
                vector<int> comb(k);
                while(current>0)
                {
                    if(current&1)
                    {
                        comb[combIndex]=nums[index];
                        combIndex++;
                    }
                    current=current>>1;
                    index++;
                }
                results.push_back(comb);
            }
        }
        
        return results;
    }
};