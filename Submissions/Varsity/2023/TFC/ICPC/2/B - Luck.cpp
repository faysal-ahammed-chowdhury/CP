#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  map<int, int> mp;
  for(int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x]++;
  }
  for(auto i: mp) {
    if((i.second) > n / 2) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";

  return 0;
}