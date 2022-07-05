class Solution {
public:
    string decodeString(string s) {
        string ans,t;
        if(s.length()==1){
            if(isdigit(s[0]))
                return "";
            return s;
        }
        int i=0,temp=0,par_count=0;
        
        while(i<s.length()){
            if(isalpha(s[i])){
                ans+=s[i++];
                continue;
            }
            if(isdigit(s[i])){
                temp=0;
                while(i<s.length()&&isdigit(s[i])!=0){
                    temp=temp*10+(s[i++]-'0');
                }
                if(i<s.length()&&s[i++]=='['){
                    par_count=1;
                    t.clear();
                    while(i<s.length()&&par_count){
                        if(s[i]=='[')
                            par_count++;
                        else if(s[i]==']')
                            par_count--;
                        t+=s[i++];
                    }
                    t.pop_back();
                    t=decodeString(t);
                    for(int k=0;k<temp;k++)
                        ans+=t;
                }
            }
        }
        return ans;
    }
};