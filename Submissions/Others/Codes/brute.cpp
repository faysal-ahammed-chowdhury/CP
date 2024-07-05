#include <bits/stdc++.h>
using namespace std;

int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  int mx = 0;
  do {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += power(a[i], i, m);
    }
    mx = max(mx, ans);
  } while (next_permutation(a + 1, a + n + 1));
  cout << mx << '\n';

  return 0;
}