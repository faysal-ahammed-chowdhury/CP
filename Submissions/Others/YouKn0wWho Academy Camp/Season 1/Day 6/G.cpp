#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  map<int, int> mp;
  int a[n + 1], mx = 0;
  bool one = false;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
    mx = max(mx, a[i]);
    one |= a[i] == 1;
  }

  if (one) {
    cout << n << '\n';
    return;
  }

  sort(a + 1, a + n + 1);

  set<int> se;

  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1]) continue;
    int val = a[i];
    if (se.find(val) != se.end()) continue;
      for (int j = val * 2; j <= mx; j += val) {
        if (mp.find(j) != mp.end()) {
          mp[val] += mp[j];
          se.insert(j);
          mp.erase(j);
        }
      }
  }

  long long ans = 0;
  for (auto [x, cnt] : mp) {
    ans += 1ll * x * cnt;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}