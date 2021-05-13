class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
            參考的方法1
            時間複雜度O(n)、空間複雜度O(1)
            Boyer–Moore majority vote algorithm(摩爾投票算法)
        */

        //假設第一個元素就是majority element
        int result=nums[0];
        //計算出現次數
        int counter=1;
        
        for(int n=1;n<nums.size();n++)
        {
            //如果是同一個元素，就counter++
            if(nums[n]==result)
            {
                counter++;
            }else if(counter>0)//如果是不同元素且counter>0，就counter--，代表此元素和目前的result湊成一對後刪去
            {
                counter--;
            }else //如果是不同元素且counter==0，就讓此元素成為新的majority element
            {
                result=nums[n];
                counter++;
            }
        }
        
        return result;
    }
};