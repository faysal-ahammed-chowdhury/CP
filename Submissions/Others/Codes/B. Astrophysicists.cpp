#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int n, k, g; cin >> n >> k >> g;
  long long kintog = 1LL * k * g;
  int half = g / 2;
  if(g % 2 == 0) {
    half--;
  }
  long long ans = 1LL * half * (n - 1);
  ans = min(kintog, ans);
  long long x = kintog - ans;
  long long r = x % g;
  long long pay = 0;
  if(r >= ceil(g / 2.0)) {
    pay += (x + (g - r));
  }
  else {
    pay += x - r;
  }
  ans += x - pay;
  cout << ans << '\n';
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