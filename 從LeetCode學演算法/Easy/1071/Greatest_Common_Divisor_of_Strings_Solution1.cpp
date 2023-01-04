class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        /*
            我的方法
            時間複雜度O(n^2)、空間複雜度O(m)(m:較短字串的長度)
        */

        if (str1.length() == str2.length())
        {
            if (str1 == str2)
            {
                return str1;
            }
            else
            {
                return "";
            }
        }

        string result = "";

        if (str1.length() < str2.length())
        {
            for (int i = 1; i <= str1.length(); i++)
            {
                string compare = str1.substr(0, i);
                if (!match(str1, compare))
                {
                    continue;
                }
                else
                {
                    if (match(str2, compare))
                    {
                        result = compare.length() > result.length() ? compare : result;
                    }
                }
            }
        }
        else
        {
            for (int i = 1; i <= str2.length(); i++)
            {
                string compare = str2.substr(0, i);
                if (!match(str2, compare))
                {
                    continue;
                }
                else
                {
                    if (match(str1, compare))
                    {
                        result = compare.length() > result.length() ? compare : result;
                    }
                }
            }
        }

        return result;
    }

    bool match(string str, string &compare)
    {
        class Solution
        {
        public:
            string gcdOfStrings(string str1, string str2)
            {
                if (str1.length() == str2.length())
                {
                    if (str1 == str2)
                    {
                        return str1;
                    }
                    else
                    {
                        return "";
                    }
                }

                string result = "";

                if (str1.length() < str2.length())
                {
                    for (int i = 1; i <= str1.length(); i++)
                    {
                        string compare = str1.substr(0, i);
                        if (!match(str1, compare))
                        {
                            continue;
                        }
                        else
                        {
                            if (match(str2, compare))
                            {
                                result = compare.length() > result.length() ? compare : result;
                            }
                        }
                    }
                }
                else
                {
                    for (int i = 1; i <= str2.length(); i++)
                    {
                        string compare = str2.substr(0, i);
                        if (!match(str2, compare))
                        {
                            continue;
                        }
                        else
                        {
                            if (match(str1, compare))
                            {
                                result = compare.length() > result.length() ? compare : result;
                            }
                        }
                    }
                }

                return result;
            }

            bool match(string str, string &compare)
            {
                int end = str.find(compare, 0);

                while (str.length() > 0)
                {
                    if (end != 0)
                    {
                        return false;
                    }
                    str = str.substr(compare.length());
                    end = str.find(compare, 0);
                }

                return true;
            }
        };
        int end = str.find(compare, 0);

        while (str.length() > 0)
        {
            if (end != 0)
            {
                return false;
            }
            str = str.substr(compare.length());
            end = str.find(compare, 0);
        }

        return true;
    }
};