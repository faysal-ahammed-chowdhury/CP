#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int ans = 1;
  for(int i = 1; i <= n; i++) {
    ans = 1LL * ans * i % mod;
  }
  cout << ans << '\n';
        
  return 0;
}