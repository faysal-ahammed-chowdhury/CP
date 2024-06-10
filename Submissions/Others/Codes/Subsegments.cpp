#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  map<int, int> mp;
  set<int> se;
  for (int l = 1, r = 1; l + k - 1 <= n; l++) {
    while (r <= k) {
      mp[a[r]]++;
      se.insert(a[r]);
      if (mp[a[r]] > 1) se.erase(a[r]);
      r++;
    }
    if (se.empty()) cout << "Nothing\n";
    else cout << *(--se.end()) << '\n';
    mp[a[l]]--;
    if (mp[a[l]] == 1) se.insert(a[l]);
    else se.erase(a[l]);
    mp[a[r]]++;
    se.insert(a[r]);
    if (mp[a[r]] > 1) se.erase(a[r]);
    r++;
  }

  return 0;
}