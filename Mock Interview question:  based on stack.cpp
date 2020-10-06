class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int l=s.length();
        string ans;
        string final="";
        for(int i=0;i<l;i++){
            if(s[i]>='0' && s[i]<='9')  
                st.push(s[i]);
            if(s[i]=='[')
                st.push(s[i]);
            if((s[i]>='a' && s[i]<='z' )||(s[i]>='A' && s[i] <='Z'))
                st.push(s[i]);
            if(s[i]==']'){
                string temp="";
                while(st.top()!='['){
                    temp=st.top() + temp;
                    st.pop();
                }
                st.pop();
                int num=0;
                string use="";
                while(!st.empty() && (st.top()>=0 && st.top()<='9')){
                   use=st.top()+use;
                    st.pop();
                }
                num=stoi(use);
                while(num--)
                ans=ans+(temp);
                if(!st.empty()){
                    for(int i=0;i<ans.length();i++)
                    {
                        st.push(ans[i]);
                    }
                    
                }
                else{
                    final=final+ans;
                }
                ans="";
            }
        
        }
        string left="";
        while(!st.empty())
        {
            left=st.top()+left;
            st.pop();
        }
        return final+left;
    }
};
