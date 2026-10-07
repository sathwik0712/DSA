class Solution {
public:
    string reverse(string s){
        string s1="";
        for(int i=s.size()-1;i>=0;i--){
            s1+=s[i];
        }
        return s1;
    }
    string reversePrefix(string word, char ch) {
        string s="";
        bool present=false;
        for(int i=0;i<word.size();i++){
            s+=word[i];
            if(word[i]==ch){
                s=reverse(s);
                present = true;
                break;
            }
        }
        
        if(present){
            for(int i=0;i<s.size();i++){
            word[i]=s[i];
        }}
        return word;
    }
};