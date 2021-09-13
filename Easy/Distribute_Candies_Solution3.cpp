class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        /*
            參考的方法2
            時間複雜度O(nlog(n))、空間複雜度O(1)
            先排序，再找有幾個不同的，最後做和方法2一樣的判斷
        */

        sort(candyType.begin(), candyType.end());
        int counter = 1;

        for (int i = 1; i < candyType.size(); i++)
        {
            cout << candyType[i - 1] << " " << candyType[i] << endl;
            if (candyType[i - 1] != candyType[i])
            {
                counter++;
            }
        }

        return counter <= candyType.size() / 2 ? counter : candyType.size() / 2;
    }
};