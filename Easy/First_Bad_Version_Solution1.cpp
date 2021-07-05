// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        /*
            我的方法(大部分人都是這樣解)
            時間複雜度O(log(n))、空間複雜度O(1)
            二元搜尋法
        */

        long long int begin=1;
        long long int end=n;
        long long int mid=(begin+end)/2;
        int firstBad=1;
        
        while(begin<=end)
        {
            if(!isBadVersion(mid))
            {
                begin=mid+1;
            }else
            {
                firstBad=mid;
                end=mid-1;
            }
            mid=(begin+end)/2;
        }
        
        return firstBad;
    }
};