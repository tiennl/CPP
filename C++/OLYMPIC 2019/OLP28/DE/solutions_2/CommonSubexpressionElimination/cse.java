// problem: Common Subexpression Elimination
// author : Walter Guttmann
// date   : 2009.05.24
// method : recursive-descent, bottom-up merging
// runtime: O(n*hashing)

import java.io.*;
import java.util.*;

public class cse {

  enum kind { ptr, leaf, inner };

  static class node {
    // pointer to node #n
    node(int n) { type=kind.ptr; num=n; }
    // leaf with label s and #n
    node(String s, int n) { type=kind.leaf; id=s; num=n; }
    // inner node with label s and #n and index c of right child
    node(String s, int n, int c) { type=kind.inner; id=s; num=n; child=c; }
    kind type;
    String id;
    int num, child;
  }

  static String expr;       // whole expression
  static int eptr;          // number of chars already parsed
  static StringBuilder out; // output expression
  static int cnt;           // sequential numbering
  static Vector<node> tree = new Vector<node>(); // preorder sequence of nodes
  static Map<String,Integer> nodes = new HashMap<String,Integer>(); // numbers of unique subtrees
  // a subtree is represented by its label and the numbers of its two children, if any

  // look at next char in expression
  static char peek() {
    return expr.charAt(eptr);
  }

  static void input() {
    // read label
    String s = "";
    while ('a' <= peek() && peek() <= 'z')
      s += expr.charAt(eptr++);
    if (peek() == '(') {
      // inner node
      int ix = tree.size(); // index in preorder sequence
      // allocate a new #, insert node
      tree.add(new node(s, ++cnt, 0));
      // skip '(' and parse left subtree
      ++eptr;
      input();
      int ix2 = tree.size(); // index of right child
      tree.elementAt(ix).child = ix2;
      // skip ',' and parse right subtree and skip ')'
      ++eptr;
      input();
      ++eptr;
      // lookup this combination of label and children in table
      s += tree.elementAt(ix+1).num + " " + tree.elementAt(ix2).num;
      if (nodes.containsKey(s)) {
        // seen before, remove both children (which are pointers)
        tree.setSize(tree.size()-2);
        // replace node by pointer
        tree.set(tree.size()-1, new node(nodes.get(s)));
        // deallocate #
        --cnt;
      } else {
        // store # in table
        nodes.put(s, tree.elementAt(ix).num);
      }
    } else {
      // leaf
      if (nodes.containsKey(s)) {
        // seen before, get # from table, insert pointer
        tree.add(new node(nodes.get(s)));
      } else {
        // allocate new #, store in table, insert leaf
        nodes.put(s, ++cnt);
        tree.add(new node(s, cnt));
      }
    }
  }

  // append graph representation of subtree with root ix to out
  static void output(int ix) {
    switch (tree.elementAt(ix).type) {
      case ptr: out.append(tree.elementAt(ix).num); break;
      case leaf: out.append(tree.elementAt(ix).id); break;
      case inner:
        out.append(tree.elementAt(ix).id);
        out.append('(');
        output(ix+1); // due to preorder
        out.append(',');
        output(tree.elementAt(ix).child);
        out.append(')');
    }
  }

  public static void main(String[] arg) throws Exception {
    StreamTokenizer st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    st.wordChars('(', ',');
    st.nextToken();
    for (int t = (int) st.nval ; t > 0 ; t--) {
      st.nextToken();
      expr = st.sval + " ";
      eptr = cnt = 0;
      tree.clear();
      nodes.clear();
      // parse expression and build graph
      input();
      // traverse graph
      out = new StringBuilder();
      output(0);
      System.out.println(out.toString());
    }
  }

}

