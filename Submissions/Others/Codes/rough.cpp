#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 1];
  bool all_zero = true;
  int mx_msb = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    all_zero &= a[i] == 0;
    if (a[i] == 0) continue;
    int msb = 63 - __builtin_clzll(a[i]);
    mx_msb = max(mx_msb, msb);
  }

  if (all_zero) {
    return;
  }


  vector<vector<int>> teams;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) continue;
    int msb = 63 - __builtin_clzll(a[i]);
    if (msb == mx_msb) {
      teams.push_back({a[i]});
    }
    else {
      if (teams.empty()) teams.push_back({a[i]});
      else teams[0].push_back(a[i]);
    }
  }

  bool ok = true;
  for (auto team : teams) {
    for (int i = 0; i < team.size(); i++) {
      for (int j = i + 1; j < team.size(); j++) {
        ok &= (team[i] ^ team[j]) >= min(team[i], team[j]);
        cout << team[i] << ' ' << team[j] << ' ' << ((team[i] ^ team[j]) >= min(team[i], team[j])) << '\n';
      }
    }
  }
  cout << ok << '\n';
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