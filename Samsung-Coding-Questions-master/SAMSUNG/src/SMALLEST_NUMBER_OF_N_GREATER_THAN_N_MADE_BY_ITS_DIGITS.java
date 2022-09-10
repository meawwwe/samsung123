/*
Given a number n, find the smallest number that has same set of digits as n and is greater than n.
If x is the greatest possible number with its set of digits, then print “not possible”.
 */
import java.util.*;
public class SMALLEST_NUMBER_OF_N_GREATER_THAN_N_MADE_BY_ITS_DIGITS {
    public static String swap(String s,int i,int j){
        char ch[]=s.toCharArray();
        char temp=ch[i];
        ch[i]=ch[j];
        ch[j]=temp;       
        return String.valueOf(ch);
    }
    public static void permute(String s,int l,int r, Set li){
        if(l==r){
            //System.out.println(s);
            li.add(s);
        }
        else{
            for(int i=l;i<=r;i++){
                s=swap(s,l,i);
                permute(s,l+1,r,li); //permute the remaining element lefting lth item
                s=swap(s,l,i); //backtracking
            }
        }
    }
    public static void main(String args[]){
        Scanner scan=new Scanner(System.in);
        int t=scan.nextInt();
        while(t!=0){
            int n=scan.nextInt(),i=0;
            String s=String.valueOf(n);
            Set<String> li=new LinkedHashSet<String>();
            permute(s,0,s.length()-1,li);
            String arr[]=new String[li.size()];   
            Iterator iterator = li.iterator(); 
            while(iterator.hasNext()){
                arr[i]=String.valueOf(iterator.next());
                i++;
            }
            boolean bool=false;
            int a=0;
            Arrays.sort(arr);
            for(int j=0;j<arr.length;j++){
                if(n<Integer.parseInt(arr[j])){
                    bool=true;
                    a=Integer.parseInt(arr[j]);
                    break;
                }         
            }
            if(bool)
                System.out.println(a);
            else
                System.out.println("not possible");
            t--;
        }
    }
}
