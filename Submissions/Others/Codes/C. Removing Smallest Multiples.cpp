#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int a[n + 1];
  for(int i = 0; i < n; i++) {
    if(s[i] == '0') a[i + 1] = 0;
    else a[i + 1] = 1;
  }
  int cost[n + 1];
  for(int i = n; i > 0; i--) {
    for(int j = i; j <= n; j += i) {
      if(a[j] == 1) break;
      cost[j] = i;
    }
  }
  long long ans = 0;
  for(int i = 1; i <= n; i++) {
    if(a[i] == 0) {
      ans += cost[i];
    }
  }
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