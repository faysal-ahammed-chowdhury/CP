#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 1e5 + 9;
int m, n;
vector<pair<int, int>> segmenst;
vector<int> queries;

bool ok(int mid) {
  vector<int> v(m + 1, 0);
  for(int i = 1; i <= mid; i++) {
    v[queries[i - 1]] = 1;
  }
  for(int i = 1; i <= m; i++) {
    v[i] += v[i - 1];
  }
  for(auto i: segmenst) {
    int mn = i.second - i.first + 1;
    int cnt = v[i.second] - v[i.first - 1];
    if(cnt > mn / 2) return true;
  }
  return false;
}

void solve() {
  segmenst.clear(), queries.clear();
  cin >> m >> n;
  for(int i = 1; i <= n; i++) {
    int x, y; cin >> x >> y;
    segmenst.push_back({x, y});
  }
  int q; cin >> q;
  for(int i = 1; i <= q; i++) {
    int x; cin >> x;
    queries.push_back(x);
  }

  int l = 1, r = q, ans = -1;
  while(l <= r) {
    int mid = (l + r) / 2;
    if(ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}