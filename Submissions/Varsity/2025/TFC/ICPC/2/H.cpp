#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9, K = 20;
int n, a[N], tree[N][K];
vector<bool> is_prime(N, true);

void sieve() {
  is_prime[1] = false;
  int lim = sqrt(N + 1);
  for (int i = 2; i <= lim; i++) {
    if (is_prime[i]) {
      for (int j = i + i; j < N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

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

bool ok(int l, int r) {
  return query(l, r) > 1;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  build(n);

  int ans = -1;
  for (int i = 1; i <= n; i++) {
    int l = 1, r = i, idx = i;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (ok(mid, i)) {
        idx = mid;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }

    // cout << i << ' ' << idx << '\n';

    int gc = query(idx, i);
    if (is_prime[gc]) ans = max(ans, i - idx + 1);
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}