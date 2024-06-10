#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll lcm(int a, int b) {
  return (1ll * a * b) / __gcd(a, b);
}

vector<int> get_divs(int n) {
  vector<int> divs;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      divs.push_back(i);
      if (i != (n / i)) divs.push_back(n / i);
    }
  }
  return divs;
}

void solve() {
  int n; cin >> n;
  int a[n + 1], mx = 0;
  set<int> se;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    se.insert(a[i]);
    mx = max(mx, a[i]);
  }
  ll lc = 1;
  for (int i = 1; i <= n; i++) {
    lc = lcm(lc, a[i]);
    if (lc > mx) {
      cout << n << '\n';
      return;
    }
  }
  int ans = 0;
  vector<int> divs = get_divs(mx);
  for (auto d : divs) {
    if (se.find(d) != se.end()) continue;
    int lc = 1, cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (d % a[i] == 0) {
        lc = lcm(lc, a[i]);
        cnt++;
      }
    }
    if (lc == d) {
      ans = max(ans, cnt);
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