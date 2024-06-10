#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;
string s;

map<char, int> merge(map<char, int> l, map<char, int> r) {
  map<char, int> ans;
  for (auto [c, x] : l) {
    ans[c] += x;
  }
  for (auto [c, x] : r) {
    ans[c] += x;
  }
  return ans;
}

struct ST {
  map<char, int> tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n][s[b]]++;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, char x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n][x]++;
      tree[n][s[i]]--;
      if (tree[n][s[i]] == 0) {
        tree[n].erase(s[i]);
      }
      s[i] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = merge(tree[l], tree[r]);
  }
  map<char, int> query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) {
      map<char, int> ans;
      return ans;
    }
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    map<char, int> L = query(l, b, mid, i, j);
    map<char, int> R = query(r, mid + 1, e, i, j);
    return merge(L, R);
  }
} st;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  cin >> s;
  s = '.' + s;

  st.build(1, 1, n);

  int q; cin >> q;
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int i; char c; cin >> i >> c;
      st.upd(1, 1, n, i, c);
    }
    else {
      int l, r; cin >> l >> r;
      cout << st.query(1, 1, n, l, r).size() << '\n';
    }
  }

  return 0;
}