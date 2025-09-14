#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }

  for (auto [x, cnt] : mp) {
    if (cnt % k != 0) {
      cout << 0 << '\n';
      return;
    }
  }

  map<int, int> freq;
  int l = 1, r = 1;
  ll ans = 0;
  while (l <= n) {
    while (r <= n) {
      freq[a[r]]++;
      if (freq[a[r]] > mp[a[r]] / k) {
        freq[a[r]]--;
        break;
      }
      r++;
    }
    ans += r - l;
    // cout << l << ' ' << r - 1 << '\n';
    freq[a[l]]--;
    l++;
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