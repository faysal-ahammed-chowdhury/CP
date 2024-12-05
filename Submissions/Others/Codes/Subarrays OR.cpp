#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, K = 20;
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
      tree[i][k] = tree[i][k - 1] | tree[i + (1 << (k - 1))][k - 1]; 
    }
  }
}

int query(int l, int r) {
  int k = log2_floor(r - l + 1);
  return (tree[l][k] | tree[r - (1 << k) + 1][k]); 
}

bool ok(int l, int r, int last) {
  return query(l, r) > query(l, last);
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(n);
  set<int> se;
  for (int i = 1; i <= n; i++) {
    int last = i;
    while (true) {
      se.insert(query(i, last));
      int l = i, r = n, idx = -1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(i, mid, last)) {
          idx = mid;
          r = mid - 1;
        }
        else {
          l = mid + 1;
        }
      }
      if (idx == -1) break;
      last = idx;
    }
  }

  cout << se.size() << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}