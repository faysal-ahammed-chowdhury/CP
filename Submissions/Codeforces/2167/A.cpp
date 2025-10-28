#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  vector<int> v;
  int x; cin >> x;
  v.push_back(x);
  cin >> x;
  v.push_back(x);
  cin >> x;
  v.push_back(x);
  cin >> x;
  v.push_back(x);

  sort(v.begin(), v.end());

  if (v[0] == v[3]) cout << "YES\n";
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