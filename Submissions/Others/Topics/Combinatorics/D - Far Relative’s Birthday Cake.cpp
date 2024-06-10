#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (auto c : a[i]) {
      cnt += c == 'C';
    }
    ans += (cnt * (cnt - 1)) / 2;
  }

  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      cnt += a[j][i] == 'C';
    }
    ans += (cnt * (cnt - 1)) / 2;
  }

  cout << ans << '\n';

  return 0;
}