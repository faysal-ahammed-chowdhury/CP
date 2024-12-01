#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  int a[n + 1];
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }

  vector<int> v;
  for (auto [x, cnt] : mp) {
    if (cnt >= x) v.push_back(x);
  }

  mp.clear();

  int pref[n + 1][v.size()];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < v.size(); j++) {
      pref[i][j] = pref[i - 1][j] + (a[i] == v[j]);
    }
  }

  while (q--) {
    int l, r; cin >> l >> r;
    int ans = 0;
    for (int j = 0; j < v.size(); j++) {
      int cnt = pref[r][j] - pref[l - 1][j];
      if (cnt == v[j]) ans++;
    }
    cout << ans << '\n';
  }

  return 0;
}