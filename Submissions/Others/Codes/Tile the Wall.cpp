#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int a, b, c; cin >> a >> b >> c;
  int n = __gcd(a, b);
  vector<int> divisors;
  for (int i = 1; 1ll * i * i <= n; i++) {
    if (n % i == 0) {
      divisors.push_back(i);
      if (i != (n / i)) {
        divisors.push_back(n / i);
      }
    }
  }

  int side = 1;
  sort(divisors.begin(), divisors.end());
  for (auto x : divisors) {
    if (x & 1) side = x;
  }

  int need = (a / side) * (b / side);
  if (need <= c) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}