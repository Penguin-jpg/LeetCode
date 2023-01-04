class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*
            我的方法
            時間複雜度O(m+n)、空間複雜度O(m)
            標準merge sort作法
        */

        if(n==0)
        {
            return;
        }
        
        vector<int> temp(nums1.begin(),nums1.begin()+m+1);
        temp[temp.size()-1]=INT_MAX;
        nums2.insert(nums2.end(),INT_MAX);
        int leftIndex=0;
        int rightIndex=0;
        
        for(int i=0;i<m+n;i++)
        {
            if(temp[leftIndex]<nums2[rightIndex])
            {
                nums1[i]=temp[leftIndex];
                leftIndex++;
            }else
            {
                nums1[i]=nums2[rightIndex];
                rightIndex++;
            }
        }
    }
};