#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e5 + 9, K = 20; 
int n, a[N], tree[N][K];

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build(int n) {
  for (int i = 1; i <= n; i++) {
    tree[i][0] = a[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree[i][k] = __gcd(tree[i][k - 1], tree[i + (1 << (k - 1))][k - 1]); 
    }
  }
}

int query(int l, int r) {
  int k = log2_floor(r - l + 1);
  return __gcd(tree[l][k], tree[r - (1 << k) + 1][k]); 
}

struct ST {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if(lazy[n] == 0) return;
    tree[n] = max(tree[n], lazy[n]);
    if(b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] = max(lazy[l], lazy[n]); 
      lazy[r] = max(lazy[r], lazy[n]); 
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if(b == e) {
      tree[n] = 0; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]); 
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if(b > j || e < i) return;
    if(b >= i && e <= j) {
      lazy[n] = x; 
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = max(tree[l], tree[r]); 
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return max(L, R); 
  }
} st;

bool ok(int i, int j) {
  // cout << i << ' ' << j << ' ' << query(i, j) << '\n';
  return query(i, j) > 1;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i  =1; i <= n; i++) {
    cin >> a[i];
  }
  build(n);
  st.build(1, 1, n);

  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) continue;
    int l = i, r = n, ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (ok(i, mid)) {
        ans = mid;
        l = mid + 1;
      }
      else r = mid - 1;
    }
    int len = ans - i + 1;
    st.upd(1, 1, n, i, ans, len);
    // cout << i << ' ' << ans << ' ' << len << '\n';
  }

  for (int i = 1; i <= n; i++) {
    cout << st.query(1, 1, n, i, i) << ' ';
  }
  cout << '\n';

  return 0;
}