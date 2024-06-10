#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> odd, even;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x & 1) odd.push_back(x);
    else even.push_back(x);
  }

  sort(odd.rbegin(), odd.rend());
  sort(even.begin(), even.end());

  for (auto x : odd) {
    cout << x << ' ';
  }
  for (auto x : even) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}