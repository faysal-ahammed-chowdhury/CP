#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int t[n + 1], x[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> x[i];
  }

  map<int, int> mp2;
  for (int i = 1; i <= n; i++) {
    if (t[i] == 1) {
      mp2[x[i]]++;
    }
    else {
      if (mp2[x[i]] <= 0) {
        cout << -1 << '\n';
        return 0;
      }
      mp2[x[i]]--;
    }
  }

  map<int, vector<int>> mp;
  int ans[n + 1];
  memset(ans, 0, sizeof(ans));
  set<int> se;
  for (int i = 1; i <= n; i++) {
    if (t[i] == 1) {
      mp[x[i]].push_back(i);
    }
    else {
      auto y = mp[x[i]].back();
      ans[y]++;
      ans[i]--;
      mp[x[i]].pop_back();
      se.insert(y);
    }
  }

  for (int i = 1; i <= n; i++) {
    ans[i] += ans[i - 1];
  }
  int mx = *max_element(ans, ans + 1 + n);
 
  cout << mx << '\n';
  for (int i = 1; i <= n; i++) {
    if (t[i] == 1) {
      if (se.find(i) != se.end()) {
        cout << 1 << ' ';
      }
      else {
        cout << 0 << ' ';
      }
    }
  }
  cout << '\n';

  return 0;
}