// problem: Common Subexpression Elimination
// author : Walter Guttmann
// date   : 2009.05.24
// method : recursive-descent, bottom-up merging
// runtime: O(n*log n)

#include <iostream>
#include <map>
#include <vector>

using namespace std;

enum kind { ptr, leaf, inner };

struct node {
  kind type;
  // label, sequential #, index of right child
  string id;
  int num, right;
};

typedef pair<int,int> pi;
typedef pair<string,pi> tsii;

int cnt;                // sequential numbering
vector<node> tree;      // preorder sequence of nodes
map<tsii,int> nodes;    // (s,(n1,n2)) |-> n : node #n has label s and children with #n1 and #n2
map<string,int> leaves; // s |-> n : leaf #n has label s

void input() {
  // index in preorder sequence (not #), insert node
  int ix = tree.size();
  tree.resize(ix+1);
  // allocate a new #
  tree[ix].num = ++cnt;
  // read label
  tree[ix].id = "";
  while (islower(cin.peek()))
    tree[ix].id += cin.get();
  if (cin.peek() == '(') { // inner node
    // skip '(' and parse left subtree
    cin.get();
    input();
    // index of right child in preorder sequence
    tree[ix].right = tree.size();
    // skip ',' and parse right subtree and skip ')'
    cin.get();
    input();
    cin.get();
    // lookup this combination of label and children in table
    tsii t(tree[ix].id, pi(tree[ix+1].num, tree[tree[ix].right].num));
    if (nodes.find(t) != nodes.end()) { // seen before
      // remove subtree (just two pointers)
      tree.resize(ix+1);
      // replace node by pointer, deallocate #
      tree[ix].type = ptr;
      tree[ix].num = nodes[t];
      --cnt;
    } else { // new
      // store # in table
      tree[ix].type = inner;
      nodes[t] = tree[ix].num;
    }
  } else { // leaf
    // lookup this label in table
    if (leaves.find(tree[ix].id) != leaves.end()) { // seen before
      // replace node by pointer, deallocate #
      tree[ix].type = ptr;
      tree[ix].num = leaves[tree[ix].id];
      --cnt;
    } else { // new
      // store # in table
      tree[ix].type = leaf;
      leaves[tree[ix].id] = tree[ix].num;
    }
  }
}

// output graph representation of subtree with root ix
void output(int ix) {
  switch (tree[ix].type) {
    case ptr: cout << tree[ix].num; break;
    case leaf: cout << tree[ix].id; break;
    case inner:
      cout << tree[ix].id << '(';
      output(ix+1); // due to preorder
      cout << ',';
      output(tree[ix].right);
      cout << ')';
  }
}

int main() {
  int c;
  cin >> c;
  while (c--) {
    cnt = 0;
    tree.clear();
    nodes.clear();
    leaves.clear();
    cin >> ws;
    // parse expression and build graph
    input();
    // traverse graph
    output(0);
    cout << endl;
  }
  return 0;
}

