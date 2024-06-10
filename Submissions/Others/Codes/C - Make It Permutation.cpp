#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

#define int long long
const int INF = 2e18;

void solve() {
  int n, c, d; cin >> n >> c >> d;
  vector<int> a;
  set<int> se;
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    if(se.find(x) == se.end()) a.push_back(x);
    se.insert(x);
  }
  sort(a.begin(), a.end());
  int x = a.size();
  int ans = INF, cost = (n - x) * c;
  for(int i = 1; i <= x; i++) {
    int right = a.end() - upper_bound(a.begin(), a.end(), a[i - 1]);
    int left = a[i - 1] - (upper_bound(a.begin(), a.end(), a[i - 1]) - a.begin());
    ans = min(ans, cost + (right * c) + (left * d));
  }
  for(int i = 1; i <= x; i++) {
    int right = a.end() - upper_bound(a.begin(), a.end(), i);
    int left = i - (upper_bound(a.begin(), a.end(), i) - a.begin());
    ans = min(ans, cost + (right * c) + (left * d));
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}