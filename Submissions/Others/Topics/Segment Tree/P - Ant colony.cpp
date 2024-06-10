#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

#define int long long
const int N = 1e5 + 9, INF = 2e9;
int a[N];

struct node {
  int g, num, cnt;
};

node merge(node l, node r) {
  node ans;
  ans.g = __gcd(l.g, r.g);
  if(l.num == r.num) {
    ans.num = l.num;
    ans.cnt = l.cnt + r.cnt;
  }
  else if(l.num < r.num) {
    ans.num = l.num;
    ans.cnt = l.cnt;
  }
  else {
    ans.num = r.num;
    ans.cnt = r.cnt;
  }
  return ans;
}

struct ST {
  node tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = {a[b], a[b], 1};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]); // change here
  }
  node query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return {0, INF, 0};
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    node L = query(l, b, mid, i, j);
    node R = query(r, mid + 1, e, i, j);
    return merge(L, R); // change this
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st.build(1, 1, n);
  int q; cin >> q;
  while(q-- > 0) {
    int l, r; cin >> l >> r;
    node ans = st.query(1, 1, n, l, r);
    int eat = r - l + 1;
    if(ans.g == ans.num) {
      eat -= ans.cnt;
    }
    cout << eat << '\n';
  }

  return 0;
}