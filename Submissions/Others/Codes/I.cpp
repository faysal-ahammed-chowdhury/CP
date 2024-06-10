#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int x; cin >> x;
  int last = __lg(x);
  int a = x;
  int b = x;
  b += (1 << ++last);
  int c = x;
  c += (1 << ++last);
  cout << a << ' ' << b << ' ' << c << '\n';
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