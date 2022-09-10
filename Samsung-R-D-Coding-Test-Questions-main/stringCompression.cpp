// Leetcode 443
#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& s) {
    s.push_back(' ');
    vector<char> ans;
    int c=1;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            c++;
        }
        else{
            ans.push_back(s[i]);
            if(c!=1){
                vector<char> ch;
                while(c!=0){                        
                    ch.push_back(c%10+'0');
                    c = c/10;
                }
                for(int j=ch.size()-1;j>=0;j--){
                    ans.push_back(ch[j]);
                }
            }
            c=1;
        }
    }
    s = ans;
    return ans.size();
    
}

int main() {
    int n;
    cin>>n;
    vector<char> s;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    cout<<compress(s);
}