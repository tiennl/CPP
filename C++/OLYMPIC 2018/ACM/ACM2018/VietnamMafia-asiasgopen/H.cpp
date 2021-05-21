#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

const string YES = "possible";
const string NO = "impossible";

void noAnswer(void) {
    cout << NO << endl;
    exit(EXIT_SUCCESS);
}

#define LEFT   0
#define RIGHT   1
#define UP   2
#define DOWN   3
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const char ch[] = "<>^v";

#define REV_DIR(dir) ((dir) ^ 1)

int getPrev(set<int> &s, int x) {
    __typeof(s.begin()) it = s.find(x);
    assert(it != s.end());
    return it == s.begin() ? -1 : *(--it);
}

int getNext(set<int> &s, int x) {
    __typeof(s.begin()) it = s.find(x);
    assert(it != s.end()); it++;
    return it == s.end() ? -1 : *it;
}

#define MAX   400400

int numRow, numCol, numBlock;
pair<int, int> blocks[MAX];
map<pair<int, int>, int> blockID;

int par[MAX], dirToPar[MAX];
vector<int> children[MAX];

bool done[MAX];
vector<int> popOrder;
set<int> rows[MAX], cols[MAX];

void init(void) {
    scanf("%d%d%d", &numRow, &numCol, &numBlock);
    FOR(i, 1, numBlock) {
        int x, y; scanf("%d%d", &x, &y);
        blocks[i] = make_pair(x, y);
        blockID[blocks[i]] = i;
    }
}

int getBlockID(int x, int y) {
    if (x < 1 || x > numRow || y < 1 || y > numCol) return -1;
    __typeof(blockID.begin()) it = blockID.find(make_pair(x, y));
    return it == blockID.end() ? -1 : it->se;
}

void buildTree(int u) {
    int ux = blocks[u].fi, uy = blocks[u].se;
    REP(d, 4) {
        int vx = ux + dx[d];
        int vy = uy + dy[d];
        int id = getBlockID(vx, vy);
        if (id < 0 || id == par[u]) continue;
        par[id] = u;
        children[u].push_back(id);
        dirToPar[id] = REV_DIR(d);
        buildTree(id);
    }
}

bool checkFree(int id) {
    assert(id > 1);

    int x = blocks[id].fi, y = blocks[id].se;

    if (dirToPar[id] == LEFT) return getNext(rows[x], y) < 0;
    if (dirToPar[id] == RIGHT) return getPrev(rows[x], y) < 0;
    if (dirToPar[id] == UP) return getNext(cols[y], x) < 0;
    if (dirToPar[id] == DOWN) return getPrev(cols[y], x) < 0;

    assert(false);
}

bool checkLeaf(int id) {
    FORE(it, children[id]) if (!done[*it]) return false;
    return true;
}

bool canPop(int id) {
    return checkLeaf(id) && checkFree(id);
}

bool checkSolution(void) {
    if (numBlock == 1) {
        cout << YES << endl;
        exit(EXIT_SUCCESS);
    }

    buildTree(1);

    FOR(i, 1, numBlock) {
        int x = blocks[i].fi, y = blocks[i].se;
        rows[x].insert(y);
        cols[y].insert(x);
    }

    queue<int> q;
    FOR(i, 1, numBlock) if (canPop(i)) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        popOrder.push_back(u);

        int x = blocks[u].fi, y = blocks[u].se;

        vector<pair<int, int> > cells;
        cells.push_back(make_pair(x, getPrev(rows[x], y)));
        cells.push_back(make_pair(x, getNext(rows[x], y)));
        cells.push_back(make_pair(getPrev(cols[y], x), y));
        cells.push_back(make_pair(getNext(cols[y], x), y));

        rows[x].erase(y);
        cols[y].erase(x);
        done[u] = true;

        FORE(it, cells) {
            int id = getBlockID(it->fi, it->se);
            if (id > 1 && canPop(id)) q.push(id);
        }
    }

    return popOrder.size() == numBlock - 1;
}

void trace(void) {
    if (!checkSolution()) noAnswer();

    cout << YES << endl;
    reverse(ALL(popOrder));
    FORE(it, popOrder) {
        int pos = dirToPar[*it] == LEFT || dirToPar[*it] == RIGHT ? blocks[*it].fi : blocks[*it].se;
        printf("%c %d\n", ch[dirToPar[*it]], pos);
    }
}

int main(void) {
    init();
    trace();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
