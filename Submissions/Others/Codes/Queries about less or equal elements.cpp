#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto &x : a) {
    cin >> x;
  }
  for (auto &x : b) {
    cin >> x;
  }
  
  sort(a.begin(), a.end());

  for (auto x : b) {
    cout << upper_bound(a.begin(), a.end(), x) - a.begin() << ' ';
  }
  cout << '\n';

  return 0;
}