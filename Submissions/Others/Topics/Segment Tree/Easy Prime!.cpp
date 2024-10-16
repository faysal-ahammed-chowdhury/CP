#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, MAX = 1e7 + 9;
vector<bool> is_prime(MAX, true);

void sieve() {
  is_prime[1] = false;
  int lim = sqrt(MAX + 1);
  for (int i = 2; i <= lim; i++) {
    if (is_prime[i]) {
      for (int j = i + i; j < MAX; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int a[N];

struct ST {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = is_prime[a[b]];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r];
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = is_prime[x];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = tree[l] + tree[r];
  }
  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R);
  }
} st;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st.build(1, 1, n);
  int q; cin >> q;
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int l, r; cin >> l >> r;
      cout << st.query(1, 1, n, l, r) << '\n';
    }
    else {
      int i, x; cin >> i >> x;
      st.upd(1, 1, n, i, x);
    }
  }

  return 0;
}