// You have to place an electronic banner of a company as high as it can be, so that whole the city can view the banner standing on top of TWO PILLERS.
// The height of two pillers are to be chosen from given array.. say [1, 2, 3, 4, 6]. We have to maximise the height of the two pillars standing side by side, so that the pillars are of EQUAL HEIGHT and banner can be placed on top of it.
// In the above array, (1, 2, 3, 4, 6) we can choose pillars like this, say two pillars as p1 and p2..
// Then pillars can be,
// p1 = 3 unit… Choosing element (3) from array,
// Similarly p2 = 3 choosing (2 + 1) from array.
// Since, two pillars are equal, we can put board on it…
// But we have two maximise the height of the pillars,
// And if we check for other heights, we can see p1 = 6 p2 = 4 + 2 which is greater than 3 ( the previous height)..
// We have to see if we can further maximize the height… Yes it can be 8.
// I.e. p1 = 6 + 2 = 8. p2 = 4 + 3 + 1 = 8.
// Both pillars are equal and banner can be placed… And since this is the maximum height attainable for two pillars, we print the answer as 8. In case, there is no combination possible, print 0 (zero).

// INPUT :
// 1
// 5
// 1 2 3 4 6
// First line is  T  number of test cases to be followed.
// Second line of input is number of different pillars.
// Third line of input is  different available heights of pillars.
// Note : heights of given pillars can be same .. I.e. array can have same elements repeated.

// Output.
// 8

// Simply print the maximum height attainable so that board/ banner can be placed.
// In case there is no possible combination for placing banner with equal weighted pillars, then print 0.


#include <bits/stdc++.h>
using namespace std;
int ans;
void dfs(int s, vector<int>& ar, int p1, int p2){
    if(p1==p2){
        ans=max(ans,p1);
    }

    if(s==ar.size()){
        return;
    }

    dfs(s+1,ar,p1+ar[s],p2);
    dfs(s+1,ar,p1,p2+ar[s]);
    dfs(s+1,ar,p1,p2);
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> ar(n);
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }

        ans=0;

        dfs(0,ar,0, 0);

        cout<<ans<<endl;
    }
}