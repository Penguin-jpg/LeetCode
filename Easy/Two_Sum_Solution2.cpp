class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
            參考的方法(hashmap)
            複雜度:O(n)
        */
        vector<int> indices;
        unordered_map<int,int> map;
        int len=nums.size();
        
        //預留空間
        indices.reserve(2);
        
       //尋訪整個vector
        for(int i=0;i<len;i++)
        {
            //如果能在hashmap找到(target-nums[i])所對應的key，就能湊成答案
            int complement=target-nums[i];
            if(map.count(complement)==1)
            {
                indices.emplace_back(i);
                indices.emplace_back(map[complement]);
                break;
            }
            if(map.count(nums[i])==0)
            {
                /*
                如果找不到，就將目前的nums[i]和i放進map中，
                下次尋訪到可和nums[i]組成target的數時，
                就能直接輸出答案
                */
                map.insert(make_pair(nums[i],i));
            }
        }  
        return indices;
    }
};