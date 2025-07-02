#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e5 + 9, inf = 1e18;
int n, T;
int a[N];

bool ok(int profit) {
  int mn = inf;
  for (int i = 1; i <= n; i++) {
    int need = a[i] - profit;
    if (mn <= need) return true;
    mn = min(mn, a[i]);
  }

  return false;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> T;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int l = 0, r = 1e9, profit = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      profit = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }

  // cout << profit << '\n';
  // cout << ok(149) << '\n';
  // cout << ok(150) << '\n';
  // cout << ok(151) << '\n';

  map<int, int> mp;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int need = a[i] - profit;
    ans += mp[need];
    mp[a[i]]++;
  }
  cout << ans << '\n';

  return 0;
}