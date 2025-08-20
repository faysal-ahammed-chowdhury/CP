#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 9;
string s;

struct node {
  int cnt4, cnt7;
  int ans, ans2; // ans2 = ans where starts with 4
  int ans3; // ans3 = ans where starts with 7 and assume 7 < 4
};

node merge(node &l, node &r) {
  if (l.cnt4 == -1) return r;
  if (r.cnt4 == -1) return l;

  node tmp;
  tmp.cnt4 = l.cnt4 + r.cnt4;
  tmp.cnt7 = l.cnt7 + r.cnt7;

  tmp.ans2 = max(l.ans2, r.ans2);
  tmp.ans2 = max(tmp.ans2, l.ans2 + r.cnt7);
  tmp.ans2 = max(tmp.ans2, l.cnt4 + r.cnt7);
  tmp.ans2 = max(tmp.ans2, l.cnt4 + r.cnt4);
  tmp.ans2 = max(tmp.ans2, l.cnt4 + r.ans2);

  tmp.ans3 = max(l.ans3, r.ans3);
  tmp.ans3 = max(tmp.ans3, l.ans3 + r.cnt4);
  tmp.ans3 = max(tmp.ans3, l.cnt7 + r.cnt4);
  tmp.ans3 = max(tmp.ans3, l.cnt7 + r.cnt7);
  tmp.ans3 = max(tmp.ans3, l.cnt7 + r.ans3);

  tmp.ans = max(l.ans, r.ans);
  tmp.ans = max(tmp.ans, tmp.ans2);
  tmp.ans = max(tmp.ans, l.ans2 + r.cnt7);
  tmp.ans = max(tmp.ans, l.cnt7 + r.cnt7);

  // cout << "here:\n";
  // cout << l.cnt4 << ' ' << l.cnt7 << ' ' << l.ans2 << ' ' << l.ans << '\n';
  // cout << r.cnt4 << ' ' << r.cnt7 << ' ' << r.ans2 << ' ' << r.ans << '\n';
  // cout << tmp.cnt4 << ' ' << tmp.cnt7 << ' ' << tmp.ans2 << ' ' << tmp.ans << '\n';

  return tmp;
}

struct ST {
  node tree[4 * N];
  bool lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    // if (b == 1 and e == 2) {
    //   cout << "here:\n";
    //   cout << tree[n].ans2 << ' ' << tree[n].ans3 << '\n';
    // }
    swap(tree[n].cnt4, tree[n].cnt7);
    swap(tree[n].ans2, tree[n].ans3);
    tree[n].ans = max(tree[n].cnt4, tree[n].cnt7);
    tree[n].ans = max(tree[n].ans, tree[n].ans2);
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] ^= lazy[n];
      lazy[r] ^= lazy[n];
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if (b == e) {
      if (s[b] == '4') {
        tree[n].ans = 1;
        tree[n].cnt4 = 1;
        tree[n].cnt7 = 0;
        tree[n].ans2 = 1;
        tree[n].ans3 = 0;
      }
      else {
        tree[n].ans = 1;
        tree[n].cnt4 = 0;
        tree[n].cnt7 = 1;
        tree[n].ans2 = 0;
        tree[n].ans3 = 1;
      }
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    // cout << '\n' << b << ' ' <<  e << '\n'; 
    tree[n] = merge(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] ^= 1;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j);
    upd(r, mid + 1, e, i, j);
    tree[n] = merge(tree[l], tree[r]);
  }
  node query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return { -1, -1, -1, -1, -1};
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    node L = query(l, b, mid, i, j);
    node R = query(r, mid + 1, e, i, j);
    return merge(L, R);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  cin >> s;
  s = '.' + s;

  st.build(1, 1, n);
  while (m--) {
    string type; cin >> type;
    if (type == "count") {
      cout << st.query(1, 1, n, 1, n).ans << '\n';
    }
    else {
      int l, r; cin >> l >> r;
      st.upd(1, 1, n, l, r);
    }
  }

  return 0;
}