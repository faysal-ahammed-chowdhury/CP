#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n; cin >> n;
  string s = to_string(n);
  int sz = s.size();
  vector<int> ans;
  int p = 1;
  for (int i = 1; i < sz; i++) {
    p *= 10;
    if (n % (p + 1) == 0) {
      ans.push_back(n / (p + 1));
    }
  }
  sort(ans.begin(), ans.end());

  cout << ans.size() << '\n';
  for (auto x : ans) {
    cout << x << ' ';
  }
  if (ans.size() > 0) cout << '\n';
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