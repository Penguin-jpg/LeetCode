class Solution {
public:
    int hammingWeight(uint32_t n) {
        /*
            參考的方法
            時間複雜度O(1)(bit長度固定)、空間複雜度O(1)
            方法1的簡化版，每次都將最小且為1的位元翻轉(變成0)，可以不需要每個bit都做檢查
            n&(n-1)要以二進位形式來看
            例子:
            n=100011,n-1=100010 -> n&(n-1)=100010(最小的1被翻轉成0)
        */

        int counter=0;
        
        while(n!=0)
        {
            counter++;
            n=n&(n-1);
        }
        
        return counter;
    }
};