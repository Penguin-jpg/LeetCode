class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        /*
            我的方法1
            時間複雜度O(n^2)、空間複雜度O(n)
        */

        vector<string> results;
        unordered_map<string,int> sums;
        int minSum=INT_MAX;
        
        for(int n=0;n<list1.size();n++)
        {
            for(int k=0;k<list2.size();k++)
            {
                if(list1[n]==list2[k])
                {
                    sums[list1[n]]=n+k;
                    if(sums[list1[n]]<minSum)
                    {
                        minSum=sums[list1[n]];
                    }
                    
                    break;
                }
            }
        }
        
        //將所有符合的放入map
        for(auto& it:sums)
        {
            if(it.second==minSum)
            {
                results.push_back(it.first);
            }
        }
        
        return results;
    }
};