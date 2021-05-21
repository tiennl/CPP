/*
Illiteracy is a simple puzzle game. You can find it here: https://le-slo.itch.io/illiteracy

There is a sequence of eight icons. The icons in the game are very artistic, but for simplicity, we'll just call the choices A..F. Clicking any icon has a unique effect on the other icons, based on which icon is clicked and its position in the sequence. Most of the icons Rotate other icons. That means that they change an A to a B, B to C, C to D, D to E, E to F, and F to A.

Let's number the icons/letters left to right, 1 to 8.

Here's what the icons do when you click on one:
A: Rotate the icon immediately to the left if there is one, and immediately to the right, if there is one.
B: If not on the end, change the icon immediately to the right to be same as the one immediately to the left. (Do nothing on the ends.)
C: Rotate the icon in the mirror position. (If in position x, rotate position 9-x. e.g. 1 rotates 8, 2 rotates 7, and so on.)
D: Rotate all of the icons past this one toward the closest end. (e.g. 3 rotates 1 and 2, 5 rotates 6, 7 and 8. The ends do nothing.)
E: Do nothing if an end.  Otherwise rotate the closest end, and also the position which is the same distance in the opposite direction from the clicked icon. (1 does nothing, 2 rotates 1 and 3, 3 rotates 1 and 5, 4 rotates 1 and 7, 5 rotates 8 and 2, 6 rotates 8 and 4, 7 rotates 8 and 6.)
F: Rotate another position with this pattern: 1->5, 2->1, 3->6, 4->2, 5->7, 6->3, 7->8, 8->4. In other words, an odd position x rotates the (x+9)/2 position; an even position x rotates the x/2 position.

Given a starting and target configuration, what is the minimal number of clicks to get from the start to the target?

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
*/


import java.util.*;
import java.lang.Math;

public class IlliteracyBitF_ANH
{
    static final int PIECES = 8;
    static final int LASTPIECE = PIECES - 1;
    static final int MOD = 6;
    static int DEBUG = 1;
    static final int MASK = (1<<24) - 1;
    static Random rand = new Random();
    static int maxSteps; // find JUDGE'S solutions

    static int s2bf(String s) { // letter string to bitField
       int bf = 0;
       for( int i = 0; i < PIECES; i++) {
           bf = set(i, s.charAt(i) - 'A', bf);
       }
       return bf;
    }

    static int get(int i, int bf)
    {
        return (bf >> 3*i) & 7;
    }

    static int set(int i, int v, int bf)
    {
        return (bf &  ~(7 << 3*i)) + (v << 3*i);
    }

    static void i2seq(int bf, boolean showCarot) // DEBUG display
    {        // bitfield bf includes high order click index if showCarot
         for (int i = 0; i < PIECES; i++)
            System.err.print((char)('A' + get(i, bf)));
         System.err.println();
         if (showCarot) {
             for (int i = 0; i < (bf >> 24); i++)
                System.err.print(' ');
             System.err.println('^');
         } // mark click
    }

    static int rot(int i, int bf)
    {
        return set(i, (get(i, bf) + 1) % MOD, bf);
    }

    public static int rCode() 
    {
        int code = 0;
        for( int i = 0; i < PIECES; i++) {
            code <<= 3;
            code += rand.nextInt(6);
        }
        return code;
    }

    // public static void manySteps() { // find big judge solutions
    //      DEBUG = 0;
    //         int start = s2bf("CBFBCECA"); // or rCode() ....
    //         int target = s2bf("GGGGGGGG"); // imposible so go through all
    //         int steps = solve(start, target);
    //         if (steps == -1 && maxSteps > 19) {
    //             System.err.format("%nmax %d steps with start ", maxSteps);
    //             i2seq(start, false);
    //             return;
    //         }
    // }

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int start = s2bf(in.next());
        int target = s2bf(in.next());
        System.out.println(solve(start, target));
    }

    public static int solve(int start, int target) {
        Stack<Integer> swap, last = new Stack<Integer>(), 
                             next = new Stack<Integer>();
        boolean[] used = new boolean[1<<24];
        int[] prev = new int[1<<24]; // DEBUG show seq
        Scanner in = new Scanner(System.in);
        if (start == target) 
            return 0;
        last.push(start);
        prev[start] = -1;
        used[start] = true;
        int steps = 0;
        while(true) { 
            if (last.empty()) {
                maxSteps = steps;
                return -1;
            } 
            steps++;
            // if (steps == 20) {  // find big judge data
            //     System.err.print("at desired steps: ");
            //     i2seq(last.get(last.size()/2), false);
            // }
            while(!last.empty())
            {
               int cNew, cPop = last.pop();
               for (int i  = 0; i < PIECES; i++){
                   cNew = cPop;
                   switch (get(i, cPop)){
                        case 0:
                            if (i > 0)
                                cNew = rot(i-1, cNew);
                            if ( i < LASTPIECE)
                                cNew = rot(i+1, cNew);
                            break;
                        case 1:
                            if (i > 0 && i < LASTPIECE)
                                cNew = set(i+1, get(i-1, cNew), cNew);
                            break;
                        case 2:
                            cNew = rot(LASTPIECE-i, cNew);
                            break;
                        case 3:
                            if (i < 4)
                                for (int j = 0; j < i; j++)
                                    cNew = rot(j, cNew);
                            else
                                for (int j = i+1; j < PIECES; j++)
                                    cNew = rot(j, cNew);
                            break;
                        case 4:
                            int d = Math.min(i, LASTPIECE-i);
                            if (d > 0) {
                                cNew = rot(i-d, cNew);
                                cNew = rot(i+d, cNew);
                            }
                            break;
                        case 5:
                            if (i%2 == 0)
                                cNew = rot((i+PIECES)/2, cNew);
                            else
                                cNew = rot(i/2, cNew);
                            break;
                        default:
                            System.err.println("Error in index " + get(i, cNew));
                   } //switch
                   if (!used[cNew]) {
                      next.push(cNew);
                      used[cNew] = true;
                      prev[cNew] = cPop + (i << 24);
                      if (steps > 21) {
                          System.err.println("Big Steps: " + steps);
                          i2seq(cNew, false);
                      }
                   }
                   if (cNew == target) {
                        if (DEBUG > 0) {   // show seq
                           last.clear();  // handy stack
                           System.err.format("%nSolution seq:%n");
                           for(;;) { // recover seq 
                              cNew = prev[cNew & MASK];
                              if (cNew == -1) 
                                  break;
                              last.push(cNew);
                           }
                           while (!last.empty()) //print with carets
                               i2seq(last.pop(), true);
                           i2seq(target, false);
                        }
                        return steps;
                   }
               } // click on each piece
            } //through stack
            swap = next;  // next stack becomes last stack
            next = last;
            last = swap;
        } // until return after answer
    } //solve
}