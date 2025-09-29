#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9;
int a[N];
int n, k, l, r;

ll f(int k) {
  int i = 1, j = 1;
  map<int, int> mp;
  ll ans = 0;
  while (i <= n) {
    while (j <= n and mp.size() < k) {
      mp[a[j]]++;
      j++;
    }

    if (mp.size() == k) {

      int L = i + l - 1;
      int R = i + r - 1;

      L = max(L, j - 1);
      R = min(R, n);

      ans += max(0, R - L + 1);

      // cout << i << ' ' << j << ' ' << L << ' ' << R << ' ' << R - L + 1 << '\n';
    }

    mp[a[i]]--;
    if (mp[a[i]] == 0) mp.erase(a[i]);
    i++;
  }

  return ans;
}

void solve() {
  cin >> n >> k >> l >> r;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  cout << f(k) - f(k + 1) << '\n';
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