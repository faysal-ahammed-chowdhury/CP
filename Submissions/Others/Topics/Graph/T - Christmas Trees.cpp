#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  queue<int> q;
  map<int, int> mp;
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x] = 0;
    q.push(x);
  }

  long long ans = 0, cnt = 0;
  set<int> se;
  while(cnt < m) {
    int top = q.front(); q.pop();
    if(mp.find(top + 1) == mp.end()) {
      cnt++;
      mp[top + 1] = mp[top] + 1;
      ans += mp[top + 1];
      q.push(top + 1);
      se.insert(top + 1);
    }
    if(cnt >= m) break;
    if(mp.find(top - 1) == mp.end()) {
      cnt++;
      mp[top - 1] = mp[top] + 1;
      ans += mp[top - 1];
      q.push(top - 1);
      se.insert(top - 1);
    }
  }

  cout << ans << '\n';
  for(auto x: se) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}