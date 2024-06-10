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

  long long n; cin >> n;
  int ans = (n % mod + mod) % mod;
  cout << ans << '\n';
        
  return 0;
}