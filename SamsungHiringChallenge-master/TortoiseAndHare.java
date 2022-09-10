import java.io.*;
import java.util.*;
public class TortoiseAndHare {
    public static void main(String args[] ) throws Exception {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt(); // number of hills
        int M = scan.nextInt(); // number of roads
        int u;
        int v;
        int t;
        int h;
        int ui = 0;
        int vi = 0;
        int ti = 0;
        int hi = 0;
        int count = 0;
        int time = 0;
        int[] timeTor = new int[M];
        int[] timeHar = new int[M]; 
        int j = 0;
        int count1 = 0;
        for (int i = 1; i <= M; i ++){
            u = scan.nextInt(); // starting point
            v = scan.nextInt(); // ending point
            t = scan.nextInt(); // time taken by tortoise
            h = scan.nextInt(); // time taken by hare
            if (ui == v){
                if ((count1 < count) && (count1 != 0)){
                    count ++;
                    timeTor[j] = ti;
                    timeTor[j + 1] = t;
                    timeHar[j] = hi;
                    timeHar[j + 1] = h;
                    j ++;
                }
                else if (count1 == 0){
                    count ++;
                    timeTor[j] = ti;
                    timeTor[j + 1] = t;
                    timeHar[j] = hi;
                    timeHar[j + 1] = h;
                    j ++; 
                }
                else if (count1 > count){
                    count = 0;
                }
            }
            else{
                count1 = count;
                j = 0;
            }
            ui = u;
            vi = v;
            ti = t; 
            hi = h;

        }
        int sumT = 0;
        int sumH = 0;
        int result = 0;
        int len = timeHar.length;
        for (int i = 0; i < len; i++){
            sumT += timeTor[i];
            sumH += timeHar[i];
        }
        result = Math.abs(sumT - sumH);
        count *= 2; 
        System.out.println(count + " " + result);
        
   }
}
