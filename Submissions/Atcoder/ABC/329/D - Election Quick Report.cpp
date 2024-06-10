#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  map<int, int> mp;
  priority_queue<pair<int, int>> pq;
  for (int i = 1; i <= m; i++) {
    int x; cin >> x;
    mp[x]++;
    pq.push({mp[x], -x});
    cout << -pq.top().second << '\n';
  }

  return 0;
}