#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int lcm(int a, int b) {
  return ((1LL * a * b) / __gcd(a, b));
}

void solve() {
  int a, b; cin >> a >> b;
  cout << __gcd(a, b) << ' ' << lcm(a, b) << '\n';
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