//https://www.geeksforgeeks.org/product-nodes-k-th-level-tree-represented-string/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        string str;
        int k;
        cin>>str>>k;

        int level=-1;
        int ans=0;
        int i=0;
        bool flag=false;
        while(i<str.size()){
            if(str[i]=='('){
                level++;
            }
            else if(str[i]==')'){
                level--;
            }
            else {
                if(level==k){
                    int isNeg=false;
                    if(str[i]=='-'){
                        isNeg=true;
                        i++;
                    }
                    int x=str[i]-'0';
                    while(str[i+1]!='('&& str[i+1]!=')'){
                        x = (x*10) + (str[i+1]-'0');
                        i++;
                    }
                    if(isNeg){
                        x=-x;
                    }
                    ans+=x;
                    flag=true;
                }
            }
            i++;
        }
        if(flag==false) ans=-1;
        cout<<ans<<endl;
    }
}
