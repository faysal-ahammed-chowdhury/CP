#include <bits/stdc++.h>
using namespace std;

int power(int a, int b) {
  int ans = 1;
  for (int i = 0; i < b; i++) {
    ans *= a;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m; cin >> m;
  vector<int> ans;
  while (m > 0) {
    for (int i = 10; i >= 0; i--) {
      int x = power(3, i);
      if (x <= m) {
        ans.push_back(i);
        m -= x;
        break;
      }
    }
  }
  cout << ans.size() << '\n';
  for (auto x : ans) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}