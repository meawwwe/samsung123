/* Problem description and Greedy Solution - https://www.geeksforgeeks.org/samsung-semiconductor-institute-of-researchssir-software-intern-fte-set-2/ */

/* Backtracking solution -- PASSED ALL 50 CASES IN SAMSUNG  */

/* DEEPANKAR CHAUDHARY IITKGP */

#include <iostream>
using namespace std;

//array for values and balloons already burst
int a[15];
bool burst[15];

// final answer and number of balloons
int ans;
int n;

int findleft(int x)
{
    for(int i=x-1;i>=0;i--)
    {
        if(burst[i]==true)
            continue;
        return i;    
    }
}

int findright(int x)
{
    for(int i=x+1;i<=n+1;i++)
    {
        if(burst[i]==true)
            continue;
        
        return i;    
    }
}

void maxscore(int temp,int balloon)
{
    // terminating condition for recursion
    if(balloon==n)
    {
        if(temp>ans)
            ans=temp;
        return;    
    }
    
    // explore all the paths
    for(int i=1;i<=n;i++)
    {
    
        if(burst[i]==false)
        {
            //choose
            burst[i]=true;
            
            int l=findleft(i); // find balloon which is not popped in left
            int r=findright(i); // find balloon which is not popped in right
            
            int p;
            
            if(l==0 && r==n+1)
                p=a[i]; // for end element
            else
                p=a[l]*a[r]; // for rest of elements
            
            temp+=p;
            
            // back track
            maxscore(temp,balloon+1);
            
            
            //unchoose
            temp-=p;
                       
            burst[i]=false;
        }
    }
    
}

/*
	1
	4
	1 2 3 4 --->20
	
*/

int main() {
	int t;
	cin>>t;
	int index=1;
	
	while(t--)
	{
	  cin>>n;
	  
	  ans=0;
	  
    // make first and last value as '1' for ease in mutliplication of end balloons
	  a[0]=1;
	  a[n+1]=1;
	  
	  burst[0]=false;
	  burst[n+1]=false;
	  
	  for(int i=1;i<=n;i++)
	  {
	      cin>>a[i];
	      burst[i]=false; //initialise
	  } 
	  
    // max score ( temp_score ,balloons burst till now)
	  maxscore(0,0);
	  
	  cout<<"#"<<index++<<" "<<ans<<endl;
	    
	}
	return 0;
}
