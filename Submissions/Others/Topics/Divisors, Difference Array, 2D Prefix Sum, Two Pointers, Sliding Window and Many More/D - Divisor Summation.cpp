#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int old_n = n;
  map<int, int> prime_factors;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      prime_factors[i]++;
      n /= i;
    }
  }
  if (n > 1) prime_factors[n]++;


  int sum = 1;
  for (auto [p, pw] : prime_factors) {
    sum *= (round(pow(p, pw + 1)) - 1) / (p - 1);
  }
  sum -= old_n;
  cout << sum << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}