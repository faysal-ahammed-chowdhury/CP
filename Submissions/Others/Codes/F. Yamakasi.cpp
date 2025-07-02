#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n, s, x; cin >> n >> s >> x;
  int a[n + 1];
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == x) v.push_back(i);
  }

  map<int, vector<int>> mp;
  int psum[n + 1];
  psum[0] = 0;
  for (int i = 1; i <= n; i++) {
    psum[i] = psum[i - 1] + a[i];
    mp[psum[i]].push_back(i);
  }

  stack<pair<int, int>> st;
  int left[n + 1];
  for (int i = n; i >= 1; i--) {
    while (!st.empty() and st.top().first < a[i]) {
      left[st.top().second] = i + 1;
      st.pop();
    }

    st.push({a[i], i});
  }
  while (!st.empty()) {
    left[st.top().second] = 1;
    st.pop();
  }

  int ans = 0;
  for (int j = 0; j < v.size(); j++) {
    int en = (j + 1 < v.size() ? v[j + 1] - 1 : n);
    for (int i = v[j]; i <= en; i++) {
      if (a[i] > a[v[j]]) break;
      int need = psum[i] - s;
      if (need == 0) {
        if (left[v[j]] == 1) ans++;
      }
      int tmp = upper_bound(mp[need].begin(), mp[need].end(), v[j] - 1) - lower_bound(mp[need].begin(), mp[need].end(), left[v[j]] - 1);
      ans += tmp;
    }
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