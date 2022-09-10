/*
https://www.geeksforgeeks.org/samsung-interview-experience-set-40-campus-white-box-testing/
https://www.geeksforgeeks.org/samsung-rd-sri-noida-on-campus-interview-experience/
https://code.hackerearth.com/01ac52j?key=b462f0a802c8c1faf1d87f2b1353b9ce
Company  A  is discarding product numbers that contain few specific digits a specific number of time or 
more than that. You are given a range and you need to find product numbers that are possible.
Example-
Range: 24 to 12943
Numbers that should not come: 1, 3, 5
Number of times these number should not occur: 3 or more
In above case all two digit numbers are valid.
In three digit: 111, 113, 115, 311, 331, 333, 511, 533, 555 are not valid.
In four digit: All the numbers containing above 3 digit numbers are not valid.
Eg: 11223 is not valid, 11222 is valid.
*/

#include <bits/stdc++.h>
using namespace std;

int numberOminous(int r1, int r2, int k, vector<int>& numList, int n){
    int count=0;
    for(int i=r1;i<=r2;i++){
        vector<int> digitsArr(10,0);
        int x = i;
        while(x){
            digitsArr[x%10]++;
            x=x/10;
        }

        int wrongNumbers = 0;
        for(int l=0;l<n;l++){
            wrongNumbers+=digitsArr[numList[l]];
        }
        if(wrongNumbers < k){
            count++;
        }
    }
    return count;
}

int main() {
    int r1, r2, k, n;
    cin >> r1 >> r2 >> k >> n;
    vector<int> numList(n);
    for(int i=0; i<n; i++){
        cin >> numList[i];
    }
    cout << numberOminous(r1, r2, k, numList, n) <<endl;
    return 0;
}