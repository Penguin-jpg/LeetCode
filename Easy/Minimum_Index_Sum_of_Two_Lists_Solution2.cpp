class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        /*
            自己想(95%)加參考(5%)的方法
            時間複雜度O(n)、空間複雜度O(n)
        */

        vector<string> results;
        unordered_map<string,int> sums;
        int minSum=INT_MAX;
        
        for(int n=0;n<list1.size();n++)
        {
           sums[list1[n]]=n;
        }
        
        for(int n=0;n<list2.size();n++)
        {
            if(sums.count(list2[n])==1)
            {
                sums[list2[n]]+=n;
                if(sums[list2[n]]<minSum)
                {
                    minSum=sums[list2[n]];
                }
            }
        }
        
        //將所有符合的放入map
        for(int n=0;n<list2.size();n++)
        {
            if(sums.count(list2[n])&&sums[list2[n]]==minSum)
            {
                results.push_back(list2[n]);
            }
        }

        return results;
    }
};