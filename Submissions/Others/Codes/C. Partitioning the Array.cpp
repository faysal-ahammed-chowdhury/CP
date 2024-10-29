#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> divs;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      divs.push_back(i);
      if (i != (n / i)) divs.push_back(n / i);
    }
  }

  int ans = 0;
  for (auto k : divs) {
    int gc = 0;
    for (int i = 1; i + k <= n; i++) {
      gc = __gcd(gc, abs(a[i] - a[i + k]));
    }
    if (gc != 1) ans++;
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