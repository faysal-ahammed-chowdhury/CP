#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x] = i;
  }

  cout << mp[-1] << ' ';
  int last = mp[-1];
  for (int i = 2; i <= n; i++) {
    cout << mp[last] << ' ';
    last = mp[last];
  }
  cout << '\n';

  return 0;
}