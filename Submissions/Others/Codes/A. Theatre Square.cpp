#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, a; cin >> n >> m >> a;
  long long ans = 1LL * ceil(double(n) / a) * ceil(double(m) / a);
  cout << ans << '\n';
        
  return 0;
}