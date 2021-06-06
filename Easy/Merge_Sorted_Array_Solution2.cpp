class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*
            參考的方法
            時間複雜度O(m+n)、空間複雜度O(1)
            只要從大放到小，就不用怕覆蓋nums1的值所造成的錯誤
        */

        if(n==0)
        {
            return;
        }else if(m==0)
        {
            for(int i=0;i<n;i++)
            {
                nums1[i]=nums2[i];
            }
            return;
        }
        
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        
        while(i>=0&&j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[k]=nums1[i];
                k--;
                i--;
            }else
            {
                nums1[k]=nums2[j];
                k--;
                j--;
            }
        }
        
        while(j>=0)
        {
            nums1[k]=nums2[j];
            k--;
            j--;
        }
    }
};