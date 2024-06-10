#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  map<int, int> mp;
  for (int i = 1; i <= 3 * n; i++) {
    int x; cin >> x;
    mp[x]++;
  }

  int y = 0;
  for (auto [x, cnt] : mp) {
    if (cnt % 3 != 0) y++;
  }  
  if (y >= 2) {
    cout << "Y\n";
    return 0;
  }
  cout << "N\n";

  return 0;
}