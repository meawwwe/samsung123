
#include<bits/stdc++.h>
using namespace std;

int tree[4*(7+1)];
int arr[8];
void build(int L,int R,int pos){
    if(L==R){
        tree[pos]=arr[L];
        return;
    }
    int mid = (L+R)/2;
    int leftNode = pos*2;
    int rightNode = pos*2+1;
    build(L,mid,leftNode);
    build(mid+1,R,rightNode);
    tree[pos] = tree[leftNode]+tree[rightNode];
}

void update(int value,int index,int l,int r,int pos){
    if(l==r){
        tree[pos]=value;
        return;
    }
    int mid = (l+r)/2;
    int leftNode = pos*2;
    int rightNode = pos*2+1;
    if(index<=mid)
        update(value,index,l,mid,leftNode);
     else
        update(value,index,mid+1,r,rightNode);

    tree[pos] = tree[leftNode]+tree[rightNode];
}
int query(int l,int r,int L,int R,int pos){
    if(l>R||r<L) return 0;
    if(l<=L&&R<=r){ //if segment matches the range we need
        return tree[pos];
    }
    int mid=(L+R)/2;
    int leftNode = pos*2;
    int rightNode = pos*2+1;
    int s1 = query(l,r,L,mid,leftNode); //Visiting left
    int s2 = query(l,r,mid+1,R,rightNode); //Visiting right
    return s1+s2; //return s1+s2 after Visiting
}
/*Main function*/
int main()
{
        cout<<"Enter eight number:\n";
        int i;
        for(i=0;i<8;i++){
            cin>>arr[i];
        }
        build(0/*start index*/,7/*end index*/,1/*begining node of the tree*/);
        int l,r;
        cout<<"Enter ranger l to r to query 0<=l<=r<=<=7 (0 based index):\n";
        cin>>l>>r;
        cout<<query(l,r,0,7,1)<<endl;
        cout<<"Enter a value and index to update at index:\n";
        int index,value;
        cin>>value>>index;
        update(value,index,0,7,1);
        cout<<"Enter ranger l to r to query 0<=l<=r<=<=7 (0 based index):\n";
        cin>>l>>r;
        cout<<query(l,r,0,7,1)<<endl;

        return 0;
}
