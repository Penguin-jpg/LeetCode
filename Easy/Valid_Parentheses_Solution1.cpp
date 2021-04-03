class Solution {
public:
    bool isValid(string s) {
        /*
            自己的想法(90%)+參考的想法(10%)
            利用stack的特性，可以方便的找出是否有成對的括號
        */
        //長度為1的不可能成對
        if(s.length()==1)
        {
            return false;
        }
        
        stack<char> parentheses;
        int len=s.length();
        
        //湊成對
        for(int n=0;n<len;n++)
        {
            //如果是左括號就放入stack
            if(s[n]=='('||s[n]=='['||s[n]=='{')
            {
                parentheses.push(s[n]);
            }else if(s[n]==')'||s[n]==']'||s[n]=='}')
            {
                //不為空才能pop
               if(!parentheses.empty())
               {
                    //成對的才能消掉
                   if(s[n]==')'&&parentheses.top()=='(')
                   {
                        parentheses.pop();
                   }else if(s[n]==']'&&parentheses.top()=='[')
                   {
                        parentheses.pop();
                   }else if(s[n]=='}'&&parentheses.top()=='{')
                   {
                        parentheses.pop();
                   }else
                   {
                       return false;
                   }
               }else//如果在遇到右括號前就遇到左括號，就代表不可能有效
               {
                   return false;
               }
            }
        }
        
        return parentheses.empty();
    }
};