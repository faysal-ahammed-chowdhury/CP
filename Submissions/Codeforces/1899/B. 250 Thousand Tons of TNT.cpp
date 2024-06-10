#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e18;

void solve() {
  int n; cin >> n;
  vector<int> divisors;
  int lim = sqrt(n + 1);
  for (int i = 1; i <= lim; i++) {
    if (n % i == 0) {
      divisors.push_back(i);
      if (i != (n / i)) {
        divisors.push_back(n / i);
      }
    }
  }
  sort(divisors.begin(), divisors.end());
  int a[n + 1];
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  divisors.pop_back();
  for (auto x : divisors) {
    int cnt = 0, sum = 0;
    int mx = -inf, mn = inf;
    for (int i = 1; i <= n; i++) {
      cnt++;
      sum += a[i];
      if (cnt == x) {
        mn = min(mn, sum);
        mx = max(mx, sum);
        cnt = 0;
        sum = 0;
      }
    }
    ans = max(ans, abs(mn - mx));
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