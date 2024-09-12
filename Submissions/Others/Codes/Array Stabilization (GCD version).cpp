#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, K = 25; 
int st[K + 1][N], n, gc;
vector<int> a;

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build(int n) {
  copy(a.begin(), a.end(), st[0]);
  for (int i = 1; i <= K; i++) {
    for (int j = 0; j + (1 << i) <= n; j++) {
      st[i][j] = __gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }
}

int query(int l, int r) {
  int i = log2_floor(r - l + 1);
  return __gcd(st[i][l], st[i][r - (1 << i) + 1]);
}

bool ok(int x) {
  for (int i = 1; i <= n; i++) {
    int g = query(i, min(n, i + x));
    if (i + x > n) {
      g = __gcd(g, query(1, (i + x) - n));
    }
    if (g != gc) return false;
  }
  return true;
}

void solve() {
  cin >> n;
  a.resize(n + 1);
  gc = 0;
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    gc = __gcd(gc, a[i]);
  }
  build(n + 1);
  int l = 0, r = n - 1, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';
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