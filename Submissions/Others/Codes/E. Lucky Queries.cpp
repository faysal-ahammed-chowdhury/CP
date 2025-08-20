#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 9;
string s;

struct node {
  int cnt4, cnt7;
  int ans1; // ans1 = ans where starts with 4
  int ans2; // ans2 = ans where starts with 7 and assume 7 => 4 and 4 => 7 (after flip)
};

node merge(node &l, node &r) {
  if (l.cnt4 == -1) return r;
  if (r.cnt4 == -1) return l;

  node tmp;
  tmp.cnt4 = l.cnt4 + r.cnt4;
  tmp.cnt7 = l.cnt7 + r.cnt7;

  tmp.ans1 = max(l.ans1, r.ans1);
  tmp.ans1 = max(tmp.ans1, l.ans1 + r.cnt7);
  tmp.ans1 = max(tmp.ans1, l.cnt4 + r.cnt7);
  tmp.ans1 = max(tmp.ans1, l.cnt4 + r.cnt4);
  tmp.ans1 = max(tmp.ans1, l.cnt4 + r.ans1);

  tmp.ans2 = max(l.ans2, r.ans2);
  tmp.ans2 = max(tmp.ans2, l.ans2 + r.cnt4);
  tmp.ans2 = max(tmp.ans2, l.cnt7 + r.cnt4);
  tmp.ans2 = max(tmp.ans2, l.cnt7 + r.cnt7);
  tmp.ans2 = max(tmp.ans2, l.cnt7 + r.ans2);

  return tmp;
}

struct ST {
  node tree[4 * N];
  bool lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    swap(tree[n].cnt4, tree[n].cnt7);
    swap(tree[n].ans1, tree[n].ans2);
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
      if (s[b] == '4') tree[n] = {1, 0, 1, 0};
      else tree[n] = {0, 1, 0, 1};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
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
    if (b > j || e < i) return { -1, -1, -1, -1};
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
      auto tmp = st.query(1, 1, n, 1, n);
      cout << max(tmp.ans1, tmp.cnt7) << '\n';
    }
    else {
      int l, r; cin >> l >> r;
      st.upd(1, 1, n, l, r);
    }
  }

  return 0;
}