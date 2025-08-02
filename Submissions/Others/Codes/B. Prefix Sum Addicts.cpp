#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  int pref[k + 1];
  for (int i = 1; i <= k; i++) {
    cin >> pref[i];
  }

  if (k == 1) {
    cout << "YES\n";
    return;
  }

  vector<int> v;
  for (int i = 2; i <= k; i++) {
    v.push_back(pref[i] - pref[i - 1]);
  }

  if (!is_sorted(v.begin(), v.end())) {
    cout << "NO\n";
    return;
  }

  int rem = n - k + 1;
  int mx = (v[0]);
  int need = (pref[1]);

  ll possible = 1ll * rem * mx;

  if (possible >= need) cout << "YES\n";
  else cout << "NO\n";
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