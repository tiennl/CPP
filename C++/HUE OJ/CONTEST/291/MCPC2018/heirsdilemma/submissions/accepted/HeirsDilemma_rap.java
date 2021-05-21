import java.util.Scanner; 
class HeirsDilemma_rap // modified to input limits
{ 
    public static void main(String args[]) 
    {    
        Scanner in = new Scanner(System.in);
        System.out.println(count(in.nextInt(), in.nextInt())); 
    } 
    
    static int count(int first, int last) 
    { 
        int ans = 0; 
          
        for (int i = first; i <= last; i++)  
            if (test(i)) {
                ans += 1; 
                System.err.print(" "+ i);
            } 
        return ans; 
    } 
    
    static boolean test(int n) 
    { 
        int m = n; 
        int c = 0;
        int[] used = new int[10];
      
        while (n > 0) 
        { 
            int d = n % 10;
            if (d==0 || m % d != 0)
                return false;
            used[d]=1;  
            n /= 10; 
        } 
        for(int i=0; i<10; i++)
            c += used[i];
        return (c==6); 
    } 
}
