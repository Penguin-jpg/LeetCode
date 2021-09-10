class Solution
{
public:
    int numberOfSteps(int num)
    {
        /*
            參考的方法
            時間複雜度O(1)、空間複雜度O(n)
            以二進位來說，減1就是將1變成0，除以2就是將位元往右移一格
            所以只需要計算有幾個1(需要翻轉成0的次數)加上
            最高位的1離最後一個位元多遠(需要做幾次除以2)就是答案
            (取log2相當於找到最高位元是2的幾次方，與所求剛好相等)
        */

        return num == 0 ? 0 : log2(num) + bitset<32>(num).count();
    }
};