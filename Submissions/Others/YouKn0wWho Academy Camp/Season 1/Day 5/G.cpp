#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury


const int N = 1e6 + 9, mod = 1e9 + 7;
int fact[N];

int power(int a, int power_val) {
  if(power_val == 0) return 1;
  if(power_val & 1) {
    int val = power(a, power_val / 2);
    return ((1LL * val * val) % mod) * a % mod;
  }
  else {
    int val = power(a, power_val / 2);
    return (1LL * val * val) % mod;
  }
}

void solve() {
  int n, m; cin >> n >> m;
  int calc = power(2, n) - 1;
  cout << power(calc, m) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fact[0] = 1;
  for(int i = 1; i < N; i++) {
    fact[i] = (1ll * fact[i - 1] * i) % mod;
  }

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}