class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
            我的方法
            時間複雜度O(nlog(n))、空間複雜度O(1)
            因為題目說要in-place的排序，所以不能用merge sort，要用quicksort
        */

        quickSort(nums,0,nums.size()-1);
    }
    
    int partition(vector<int>& nums,int begin,int end)
    {
        int pivot=nums[end];
        int i=begin-1;
        
        for(int j=begin;j<end;j++)
        {
            if(nums[j]<pivot)
            {
                i++;
                swap(nums[i],nums[j]);
            }
        }
        
        i++;
        swap(nums[i],nums[end]);
        
        return i;
    }
    
    void quickSort(vector<int>& nums,int begin,int end)
    {
        if(begin<end)
        {
            int pivot=partition(nums,begin,end);    
            quickSort(nums,begin,pivot-1);
            quickSort(nums,pivot+1,end);
        }
    }
};