#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (x % 4 == 0) {
      mp[2]++;
    }
    else if (x % 2 == 0) {
      mp[1]++;
    }
    else {
      mp[0]++;
    }
  }

  if (mp[0] == 0) {
    cout << "Yes\n";
    return 0;
  }

  if (mp[2] >= mp[0]) {
    cout << "Yes\n";
    return 0;
  } 

  if (mp[0] == mp[2] + 1 and mp[1] == 0) {
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";

  return 0;
}