#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int x, y; cin >> x >> y;
  int max_multiple = y - y % x;
  int n;
  if(x == y) {
    n = x;
  }
  else if(x > y) {
    n = x + y;
  }
  else {
    n = (max_multiple + y) / 2;
  }
  cout << n << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}