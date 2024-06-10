#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  set<int> missing_numbers;
  for (int i = 0; i <= n + 5; i++) {
    missing_numbers.insert(i);
  }
  map<int, int> mp;
  int z_cnt = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x]++;
    z_cnt += x == 0;
    missing_numbers.erase(x);
  }

  int mx_mex = *missing_numbers.begin();

  if (z_cnt == 0) {
    cout << 0 << '\n';
  }
  else if (z_cnt == 1) {
    for (int i = 1; i <= mx_mex; i++) {
      if (mp[i] == 1) {
        cout << i << '\n';
        return;
      }
    }
    cout << mx_mex << '\n';
  }
  else {
    bool first = true;
    for (int i = 1; i <= mx_mex; i++) {
      if (mp[i] == 1) {
        if (first) {
          first = false;
          continue;
        }
        cout << i << '\n';
        return;
      }
    }
    cout << mx_mex << '\n';
  }
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