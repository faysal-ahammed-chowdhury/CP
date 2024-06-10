#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> v;
  int last = 0, cnt = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == last) {
      cnt++;
    }
    else {
      if (cnt != -1) v.push_back(cnt);
      cnt = 1, last = a[i];
    }
  }
  v.push_back(cnt);
  int ans = 0;
  for (auto x : v) {
    ans += x / 2;
  }
  cout << ans << '\n';

  return 0;
}