#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x; cin >> n >> x;
  int y = n / x;
  int ans = 0;
  vector<int> divisors;
  int lim = sqrt(n + 1);

  for (int i = 1; i <= lim; i++) {
    if (n % i == 0 and i <= y) {
      divisors.push_back(i);
      if (i != (n / i) and (n / i) <= y) {
        divisors.push_back(n / i);
      }
    }
  }

  for (auto i : divisors) {
    if (n % i == 0) {
      ans = max(ans, i);
    }
    else if ((n % i) % i == 0) {
      ans = max(ans, i);
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}