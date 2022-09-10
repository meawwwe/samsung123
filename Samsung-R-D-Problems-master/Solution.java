import java.util.*;
public class coor {
int x;
int y;
int level;
 coor(int x,int y, int level)
 {
	 this.x=x;
	 this.y=y;
	 this.level=level;
 }
}
public class node {
 coor n;
 node next;
  node(coor n)
  {
	  this.n=n;
	  next=null;
  }
}

public class linkedlist
{
	node root;
	
	void add(coor n)
	{
		node c=new node(n);
		if(root==null)
		{
			root= c;
		}
		else
		{
			node d=root;
			while(d.next!=null)
			{
				d=d.next;
			}
			d.next=c;
		}
	}
	boolean contains(coor e)
	{
		node d=root;
		while(d!=null)
		{
			if((d.n.x==e.x)&&(d.n.y==e.y))
			{
				return true;
			}
			d=d.next;
		}
		return false;
	}
}
public class queue {
	node front;
	node rear;
	void enqueue(node d)
	{
		node d1=d;
		if(front==null&&rear==null)
		{
			front=rear=d1;
		}
		else
		{
			rear.next=d;
			rear=d;
		}
	}
	node poll()
	{
		node d2= front;
		if(front==rear)
		{
			front= rear= null;
		}
		else
		{
		front=front.next;
		}
		return d2;
	}
	boolean isempty()
	{
		if(front==null&&rear==null)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
public class endo
{
	queue q;
	linkedlist l;
	int len=0;
	int wid=0;
	int elen=0;
	int count=0;
	int findmax(int arr2[][], int a, int b, int c)
	{
		q= new queue();
	    l=new linkedlist();
		coor e=new coor(a,b,1);
		node d=new node(e);
		if(arr2[a][b]!=0)
		{
			q.enqueue(d);
			l.add(e);
			count++;
		}
		while(q.isempty()!=true)
		{
			node check=q.poll();
			 int val=arr2[check.n.x][check.n.y];
			// System.out.println();
//	System.out.println(check.n.x +" "+ check.n.y);
 //   System.out.println("val1"+arr2[check.n.x][check.n.y]);
			 if(val==1)
			 {
				 if((check.n.x-1)!=-1)
				 {
					//System.out.println("val1"+arr2[check.n.x-1][check.n.y]);
					 if((arr2[check.n.x-1][check.n.y]==1)||(arr2[check.n.x-1][check.n.y]==2)||(arr2[check.n.x-1][check.n.y]==5)||(arr2[check.n.x-1][check.n.y]==6))
					 {
						 coor e1=new coor(check.n.x-1, check.n.y, check.n.level+1);
						 node d1=new node(e1);
						 if((l.contains(e1)!=true)&&(e1.level<=elen))
						 {
						 q.enqueue(d1);
						 l.add(e1);
						 count++;
						 }
						 
					 }
			    }
				if((check.n.x+1)!=len)
				{
				if((arr2[check.n.x+1][check.n.y]==1)||(arr2[check.n.x+1][check.n.y]==2)||(arr2[check.n.x+1][check.n.y]==4)||(arr2[check.n.x+1][check.n.y]==7))
				{
				 coor e1=new coor(check.n.x+1, check.n.y, check.n.level+1);
				 node d1=new node(e1);
				 if((l.contains(e1)!=true)&&(e1.level<=elen))
				 {
				 q.enqueue(d1);
				 l.add(e1);
				 count++;
				 }
				}
				}
				if((check.n.y-1)!=-1)
				{
				if((arr2[check.n.x][check.n.y-1]==1)||(arr2[check.n.x][check.n.y-1]==3)||(arr2[check.n.x][check.n.y-1]==4)||(arr2[check.n.x][check.n.y-1]==5))
				{
				 coor e1=new coor(check.n.x, check.n.y-1, check.n.level+1);
				 node d1=new node(e1);
				 if((l.contains(e1)!=true)&&(e1.level<=elen))
				 {
				 q.enqueue(d1);
				 l.add(e1);
				 count++;
				 }
				}
				}
				if((check.n.y+1)!=wid)
				{
					//System.out.println("width "+(check.n.y+1)+" "+wid);
				if((arr2[check.n.x][check.n.y+1]==1)||(arr2[check.n.x][check.n.y+1]==3)||(arr2[check.n.x][check.n.y+1]==6)||(arr2[check.n.x][check.n.y+1]==7))
				{
				 coor e1=new coor(check.n.x, check.n.y+1, check.n.level+1);
				 node d1=new node(e1);
				 if((l.contains(e1)!=true)&&(e1.level<=elen))
				 {
				 q.enqueue(d1);
				 l.add(e1);
				 count++;
				 }
				}
				}
			 }
			 if(val==2)
			 {
				 if((check.n.x-1)!=-1)
				 {
			 if((arr2[check.n.x-1][check.n.y]==2)||(arr2[check.n.x-1][check.n.y]==1)||(arr2[check.n.x-1][check.n.y]==5)||(arr2[check.n.x-1][check.n.y]==6))
					{
					 coor e1=new coor(check.n.x-1, check.n.y, check.n.level+1);
					 node d1=new node(e1);
					 if((l.contains(e1)!=true)&&(e1.level<=elen))
					 {
					 q.enqueue(d1);
					 l.add(e1);
					 count++;
					 }
					}
				 }
				 if((check.n.x+1)!=len)
				 {
				 if((arr2[check.n.x+1][check.n.y]==2)||(arr2[check.n.x+1][check.n.y]==1)||(arr2[check.n.x+1][check.n.y]==4)||(arr2[check.n.x+1][check.n.y]==7))
					{
					 coor e1=new coor(check.n.x+1, check.n.y, check.n.level+1);
					 node d1=new node(e1);
					 if((l.contains(e1)!=true)&&(e1.level<=elen))
					 {
					 q.enqueue(d1);
					 l.add(e1);
					 count++;
					 }
					}
				 }
			 }
			 if(val==3)
			 {
				 if((check.n.y-1)!=-1)
					{
					// System.out.println("val2 "+arr2[check.n.x][check.n.y-1]);
				 if((arr2[check.n.x][check.n.y-1]==3)||(arr2[check.n.x][check.n.y-1]==1)||(arr2[check.n.x][check.n.y-1]==4)||(arr2[check.n.x][check.n.y-1]==5))
					{
					// System.out.println("val2 "+arr2[check.n.x][check.n.y-1]);
					 coor e1=new coor(check.n.x, check.n.y-1, check.n.level+1);
					 node d1=new node(e1);
					 if((l.contains(e1)!=true)&&(e1.level<=elen))
					 {
					// System.out.println("val2 "+arr2[check.n.x][check.n.y-1]);
					 q.enqueue(d1);
					 l.add(e1);
					 count++;
					// System.out.println(count);
					 }
					}
					}
				 if((check.n.y+1)!=wid)
					{
					 //System.out.println("val1 "+arr2[check.n.x][check.n.y-1]);
				 if((arr2[check.n.x][check.n.y+1]==3)||(arr2[check.n.x][check.n.y+1]==1)||(arr2[check.n.x][check.n.y+1]==6)||(arr2[check.n.x][check.n.y+1]==7))
					{
					// System.out.println("val1 "+arr2[check.n.x][check.n.y-1]);
					 coor e1=new coor(check.n.x, check.n.y+1, check.n.level+1);
					 node d1=new node(e1);
					 if((l.contains(e1)!=true)&&(e1.level<=elen))
					 {
					//	 System.out.println("val1 "+arr2[check.n.x][check.n.y-1]);
					 q.enqueue(d1);
					 l.add(e1);
					 count++;
				//	 System.out.println(count);
					 }
					}
				}
			 }
			 if(val==4)
			 {
				 if((check.n.x-1)!=-1)
				 {
				 if((arr2[check.n.x-1][check.n.y]==2)||(arr2[check.n.x-1][check.n.y]==1)||(arr2[check.n.x-1][check.n.y]==5)||(arr2[check.n.x-1][check.n.y]==6))
					{
					 coor e1=new coor(check.n.x-1, check.n.y, check.n.level+1);
					 node d1=new node(e1);
					 if((l.contains(e1)!=true)&&(e1.level<=elen))
					 {
					 q.enqueue(d1);
					 l.add(e1);
					 count++;
					 }
					}
				 }
				 if((check.n.y+1)!=wid)
					{
				 if((arr2[check.n.x][check.n.y+1]==1)||(arr2[check.n.x][check.n.y+1]==3)||(arr2[check.n.x][check.n.y+1]==6)||(arr2[check.n.x][check.n.y+1]==7))
					{
					 coor e1=new coor(check.n.x, check.n.y+1, check.n.level+1);
					 node d1=new node(e1);
					 if((l.contains(e1)!=true)&&(e1.level<=elen))
					 {
					 q.enqueue(d1);
					 l.add(e1);
					 count++;
					 }
					}
					}
			 }
			 if(val==5)
			 {
				// System.out.println("i am in 1");
				 if((check.n.y+1)!=wid)
					{
					// System.out.println("i am in 2");
				 if((arr2[check.n.x][check.n.y+1]==6)||(arr2[check.n.x][check.n.y+1]==7)||(arr2[check.n.x][check.n.y+1]==3)||(arr2[check.n.x][check.n.y+1]==1))
					{
					// System.out.println("i am in 3");
					 coor e1=new coor(check.n.x, check.n.y+1, check.n.level+1);
					 node d1=new node(e1);
					 if((l.contains(e1)!=true)&&(e1.level<=elen))
					 {
						// System.out.println("i am in 4");
					 q.enqueue(d1);
					 l.add(e1);
					 count++;
					 }
					}
					}
				 if((check.n.x+1)!=len)
				 {
					// System.out.println("i am in 22");
				 if((arr2[check.n.x+1][check.n.y]==7)||(arr2[check.n.x+1][check.n.y]==1)||(arr2[check.n.x+1][check.n.y]==2)||(arr2[check.n.x+1][check.n.y]==4))
					{
					// System.out.println("i am in 33");
					 coor e1=new coor(check.n.x+1, check.n.y, check.n.level+1);
					 node d1=new node(e1);
					 if((l.contains(e1)!=true)&&(e1.level<=elen))
					 {
						// System.out.println("i am in 44");
					 q.enqueue(d1);
					 l.add(e1);
					 count++;
					 }
					}
				 }
			 }
			 if(val==6)
			 {
				 if((check.n.x+1)!=len)
				 {
				 if((arr2[check.n.x+1][check.n.y]==7)||(arr2[check.n.x+1][check.n.y]==2)||(arr2[check.n.x+1][check.n.y]==4)||(arr2[check.n.x+1][check.n.y]==1))
					{
					 coor e1=new coor(check.n.x+1, check.n.y, check.n.level+1);
					 node d1=new node(e1);
					 if((l.contains(e1)!=true)&&(e1.level<=elen))
					 {
					 q.enqueue(d1);
					 l.add(e1);
					 count++;
					 }
					}
				 }
				 if((check.n.y-1)!=-1)
					{
					if((arr2[check.n.x][check.n.y-1]==1)||(arr2[check.n.x][check.n.y-1]==3)||(arr2[check.n.x][check.n.y-1]==4)||(arr2[check.n.x][check.n.y-1]==5))
					{
					 coor e1=new coor(check.n.x, check.n.y-1, check.n.level+1);
					 node d1=new node(e1);
					 if((l.contains(e1)!=true)&&(e1.level<=elen))
					 {
					 q.enqueue(d1);
					 l.add(e1);
					 count++;
					 }
					}
					}
			 }
			 if(val==7)
			 {
				 if((check.n.x-1)!=-1)
				 {
				 if((arr2[check.n.x-1][check.n.y]==1)||(arr2[check.n.x-1][check.n.y]==2)||(arr2[check.n.x-1][check.n.y]==5)||(arr2[check.n.x-1][check.n.y]==6))
					{
					 coor e1=new coor(check.n.x-1, check.n.y, check.n.level+1);
					 node d1=new node(e1);
					 if((l.contains(e1)!=true)&&(e1.level<=elen))
					 {
					 q.enqueue(d1);
					 l.add(e1);
					 count++;
					 }
					}
				 }
				 if((check.n.y-1)!=-1)
					{
				 if((arr2[check.n.x][check.n.y-1]==1)||(arr2[check.n.x][check.n.y-1]==3)||(arr2[check.n.x][check.n.y-1]==4)||(arr2[check.n.x][check.n.y-1]==5))
					{
					 coor e1=new coor(check.n.x, check.n.y-1, check.n.level+1);
					 node d1=new node(e1);
					 if((l.contains(e1)!=true)&&(e1.level<=elen))
					 {
					 q.enqueue(d1);
					 l.add(e1);
					 count++;
					 }
					}
					}
			 }
		}
		return 0;
	}
	public static void main(String args[])
	{
		Scanner sc= new Scanner(System.in);
		endo e=new endo();
		int n=sc.nextInt();
		int i=0;
		int j=0;
		int k=0;
		int l=0;
		int arr1[]=new int[5];
		int arr2[][];
		for(i=0;i<n;i++)
		{
			for(j=0;j<5;j++)
			{
				arr1[j]=sc.nextInt();
			}
			e.len=arr1[0];
			e.wid=arr1[1];
			e.elen=arr1[4];
			e.count=0;
			arr2=new int[arr1[0]][arr1[1]];
			for(k=0;k<arr1[0];k++)
			{
				for(l=0;l<arr1[1];l++)
				{
					arr2[k][l]=sc.nextInt();
				}
			}
			
			e.findmax(arr2, arr1[2], arr1[3], arr1[4]);
		//	System.out.println(arr2[25][49]);
			//System.out.println(arr2[24][50]);
			 System.out.println(e.count);
			
		}
	}
}
