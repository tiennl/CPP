/*
Illiteracy is a simple puzzle game. You can find it here: https://le-slo.itch.io/illiteracy

There is a string of icons. The icons in the game are very artistic, but for simplicity, we'll just call them A..F. Clicking any icon has a unique effect on the other icons, based on which icon is clicked and its position. Most of the icons Rotate other icons. That means that they change an A to a B, B to C, C to D, D to E, E to F, and F to A.

There are 8 places ofr an icon. Let's number them left to right, 1 to 8.

Here's what the icons do when you click on one:
A: Rotate the icon immediately to the left if there is one, and immediately to the right, if there is one.
B: If not on the end, change the icon immediately to the right to be same as the one immediately to the left. (Do nothing on the ends.)
C: Rotate the icon in the mirror position. (If in position x, rotate 9-x. e.g. 1 rotates 8, 2 rotates 7, and so on.)
D: Rotate all of the icons past this one toward the closest end. (e.g. 3 rotates 1 and 2, 5 rotates 6, 7 and 8. The ends do nothing.)
E: Do nothing if an end.  Otherwise rotate the closest end, and also the position which is the same distance in the opposite direction from the clicked icon. (1 does nothing, 2 rotates 1 and 3, 3 rotates 1 and 5, 4 rotates 1 and 7, 5 rotates 8 and 2, 6 rotates 8 and 4, 7 rotates 8 and 6.)
F: Rotate another position with this pattern: 1->5, 2->1, 3->6, 4->2, 5->7, 6->3, 7->8, 8->4. In other words, an odd position x rotate the (x+9)/2 position; an even position x rotates the x/2 position.

Given a starting and target configuration, what is the minimal number of steps to get from the start to the target?

Examples:  We show possible minimal sequences to get from the top configuration to the bottom one.  The carets indicate the click position for the previous line to generate the following line.

One sequence:

ABCDEFCD
   ^
BCDDEFCD
     ^
BCEDEFCD

Another sequence:

DCDAFCBA
   ^
DCEAACBA
      ^
DCEAACBC
 ^
DCEAACCC
  ^
ECEABCCC

The Input

The input will consist of exactly two lines, Each line will have exactly eight letters, consisting only of capital letters A, B, C, D, E, or F.  The first line is the starting state; the second is the target.  It will always be possible to reach the target from the given start.

The Output

Output a single integer, indicating the smallest number of icon presses to get from the start to the target.

samples

ABCDEFCD
BCEDEFCD
2

DCDAFCBA
ECEABCCC
4

ACFEFBEB
EDBFEFDE
22

*/


import java.util.*;
import java.lang.Math;

public class IlliteracyArrayMid
{
    static final int PIECES = 8;
    static final int LASTPIECE = PIECES - 1;
    static final int MOD = 6;
    static final int DEBUG = 1;
    static final int MASK = (1<<24) - 1;

    private static int[] a = new int[PIECES]; // current seq

    static void s2a(String s) { // letter string to current int array
       for( int i = 0; i < PIECES; i++) 
            a[i] = s.charAt(i) - 'A';
    }

    static void showA() { 
       for( int i = 0; i < PIECES; i++) 
            System.err.print(a[i] + " ");
       System.err.println(); 
    }

    static int a2i() { // current int array to bitfield
       int c = 0;
       for( int i = LASTPIECE; i >= 0; i--) {
           c <<= 3;
           c += a[i];
       }
       return c;
    }

    static void i2a(int c) { // bitfield to current int array
       for( int i = 0; i < PIECES; i++) {
            a[i] = c & 7;
            c >>= 3;
        }
    }

    static void i2seq(int c, boolean showCarot) // DEBUG display
    {        // bitfield c includes high order click index if showCarot
         i2a(c);
         for (int i = 0; i < PIECES; i++)
            System.err.print((char)('A' + a[i]));
         System.err.println();
         if (showCarot) {
             for (int i = 0; i < (c >> 24); i++)
                System.err.print(' ');
             System.err.println('^');
         } // mark click
    }

    static void rot(int i)
    {
        a[i] = (a[i] + 1) % MOD;
    }

    public static void main(String[] args){
        Stack<Integer> swap, last = new Stack<Integer>(), 
                             next = new Stack<Integer>();
        boolean[] used = new boolean[1<<24];
        int[] prev = new int[1<<24]; // DEBUG show seq
        Scanner in = new Scanner(System.in);
        s2a(in.next());
        int start = a2i();
        // System.err.print(start + " ");
        // showA();
        s2a(in.next());
        int target = a2i();
        if (start == target) {
            System.out.println(0);
            return;
        }
        last.push(start);
        prev[start] = -1;
        used[start] = true;
        int steps = 0;
        while(true) { 
            steps++;
            if (last.empty()) { 
                System.out.println(-1);
                return;
            }
            while(!last.empty())
            {
               int cPop = last.pop();
               // System.err.print("Popped " + cPop + " ");
               i2a(cPop);
               // showA();
               for (int i  = 0; i < PIECES; i++){
                   i2a(cPop);
                   switch (a[i]){
                        case 0:
                            if (i > 0)
                                rot(i-1);
                            if ( i < LASTPIECE)
                                rot(i+1);
                            break;
                        case 1:
                            if (i > 0 && i < LASTPIECE)
                                a[i+1] = a[i-1];
                            break;
                        case 2:
                            rot(LASTPIECE-i);
                            break;
                        case 3:
                            if (i < 4)
                                for (int j = 0; j < i; j++)
                                    rot(j);
                            else
                                for (int j = i+1; j < PIECES; j++)
                                    rot(j);
                            break;
                        case 4:
                            int d = Math.min(i, LASTPIECE-i);
                            if (d > 0) {
                                rot(i-d);
                                rot(i+d);
                            }
                            break;
                        case 5:
                            if (i%2 == 0)
                                rot((i+PIECES)/2);
                            else
                                rot(i/2);
                            break;
                        default:
                            System.err.println("Error in index " + a[i]);
                            // showA();
                   } //switch
                   int cn = a2i();
                   if (!used[cn]) {
                      next.push(cn);
                      // System.err.print("Push for "  + i + " " + cn + " ");
                      // showA();
                      used[cn] = true;
                      prev[cn] = cPop + (i << 24);
                      // System.err.println("Prev " + prev[cn] + " masked " + (prev[cn] & MASK) + " i " + (prev[cn] >> 24));
                   }
                   if (cn == target) {
                        if (DEBUG > 0) {   // show seq
                           last.clear();  // handy stack
                           System.err.format("%nSolution seq:%n");
                           for(;;) { // recover seq 
                              cn = prev[cn & MASK];
                              if (cn == -1) 
                                  break;
                              last.push(cn);
                              // System.err.println("Prev seq " + cn + " masked " + (cn & MASK) + " i " + (cn >> 24));
                           }
                           while (!last.empty()) //print with carets
                               i2seq(last.pop(), true);
                           i2seq(target, false);
                        }
                        System.out.println(steps);
                        return;
                   }
               } // click on each piece
            } //through stack
            swap = next;  // next stack becomes last stack
            next = last;
            last = swap;
        } // until return after answer
    } //main
}