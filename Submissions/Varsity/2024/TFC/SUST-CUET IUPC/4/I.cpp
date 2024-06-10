#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, mod = 1000000007;
int fact[N];

void prec() { 
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1ll * fact[i - 1] * i % (mod - 1);
  }
}

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

void solve() {
  int a, b, n; cin >> a >> b >> n;
  int x = 0;
  if (a < b) {
    x = fact[a];
  }
  else {
    x = fact[b];
  }
  cout << power(n, x, mod) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  prec();

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}