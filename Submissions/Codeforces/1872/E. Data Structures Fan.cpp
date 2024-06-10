#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e5 + 9;
int a[N], arr[N];

struct node {
  int cnt;
  int one_xor;
  int zero_xor;
};

node merge(node l, node r) {
  node ans;
  ans.cnt = l.cnt + r.cnt;
  ans.one_xor = l.one_xor ^ r.one_xor;
  ans.zero_xor = l.zero_xor ^ r.zero_xor;
  return ans;
}

node tree[4 * N];
struct ST {
  int lazy[4 * N];
  ST() {
    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));
  }
  void push(int n, int b, int e) {
    if(lazy[n] == 0) return;
    tree[n].cnt = (e - b + 1) - tree[n].cnt; // change here
    swap(tree[n].one_xor, tree[n].zero_xor);
    if(b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] += lazy[n]; // change here
      lazy[l] = lazy[l] % 2;
      lazy[r] += lazy[n]; // change here
      lazy[r] = lazy[r] % 2;
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if(b == e) {
      tree[n].cnt = a[b]; // change here
      if(a[b] == 1) {
        tree[n].one_xor = arr[b];
        tree[n].zero_xor = 0;
      }
      else {
        tree[n].one_xor = 0;
        tree[n].zero_xor = arr[b];
      }
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]); // change here
  }
  void upd(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) return;
    if(b >= i && e <= j) {
      lazy[n] += 1; // change here
      lazy[n] = lazy[n] % 2;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j);
    upd(r, mid + 1, e, i, j);
    tree[n] = merge(tree[l], tree[r]); // change here
  }
 } st;

void solve() {
  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for(int i = 1; i <= n; i++) {
    char c; cin >> c;
    a[i] = c - '0';
  }
  st.build(1, 1, n);
  int q; cin >> q;
  for(int i = 1; i <= q; i++) {
    int type; cin >> type;
    if(type == 1) {
      int l, r; cin >> l >> r;
      st.upd(1, 1, n, l, r);
    }
    else {
      int x; cin >> x;
      node ans = tree[1];
      if(x == 0) {
        cout << ans.zero_xor << ' ';
      }
      else {
        cout << ans.one_xor << ' ';
      }
    }
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}