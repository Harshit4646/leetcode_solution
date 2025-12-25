class Solution {
public:
    string toLowerCase(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z'){
                ans+=s[i]-'A'+'a';
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};