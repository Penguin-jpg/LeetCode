class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
            參考的方法
            時間複雜度O(nlog(n))、空間複雜度O(n)
            利用hash table，將排序過的字串當成key，並將排序前的字串放入作為value的vector
        */

        vector<vector<string>> results;
        unordered_map<string,vector<string>> anagrams;
        
        for(int n=0;n<strs.size();n++)
        {
            string temp=strs[n];
            sort(strs[n].begin(),strs[n].end());
            anagrams[strs[n]].push_back(temp);
        }
        
        for(auto it:anagrams)
        {
            results.push_back(it.second);
        }
        
        return results;
    }
};