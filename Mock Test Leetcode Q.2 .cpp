class Solution {
public:
    string code(unordered_map<char,int> m1,string s,int len1){
        int i=1;
        string a="";
        for(int j=0;j<len1;j++){
            if(m1.find(s[j])!=m1.end())
            {
                a+=m1[s[j]];
            }
            else{
                a+=to_string(i);
                m1[s[j]]=i;
                i++;
            }
        }
        return a;
    }
    
    bool isIsomorphic(string s, string t) {
        int len1=s.length();
        int len2=t.length();
        if(len1!=len2)
            return false;
        if(len1==0 && len2==0)
            return true;
        if(len1==0||len2==0)
            return false;
        unordered_map<char,int> m1;
        string a=code(m1,s,len1);
        string b= code(m1,t,len2);
        if(a==b)
            return true;
        else 
            return false;
    }
};
