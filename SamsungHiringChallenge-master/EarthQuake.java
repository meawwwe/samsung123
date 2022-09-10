import java.io.*;
import java.util.*;
public class EarthQuake {
    public static void main(String args[] ) throws Exception {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int M = scan.nextInt();
        int K = scan.nextInt();
        int j = 0;
        int[] affCity = new int[K];
        int u = 0; // starting point
        int v = 0; // ending point
        int I = 0; // presence of road
        int sum = 0;
        for (int i = 0; i < K; i ++){
            affCity[i] = scan.nextInt(); 
        }
        int len = affCity.length;
        int x = 0;
        for (int i = 1 ; i <= M; i ++){      
            u = scan.nextInt();
            v = scan.nextInt();
            I = scan.nextInt();
            if (len == 1){
                    if (I < x){
                        sum += I;
                        sum = sum * 2;
                    }
                    x = I;
                }
                if (len > 1){
                  if (I < x){
                       if ((v == affCity[j]) && (j == 0)){
                            sum += I;
                            j ++;
                        }
                        else if ((v == affCity[j]) && (u == affCity[j - 1])){
                            sum += I;
                            j ++;
                            if (j > K - 1){
                                sum = (sum * 2); 
                                break;
                            }
                        }
                    }
                    x = I;    
                }
            }
        System.out.println(sum);
   }
}
