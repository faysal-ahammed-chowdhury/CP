#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
using ll = long long;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  ll a[n + 1];
  a[0] = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for(int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  ll low = 0;
  ll ans = INT64_MIN;
  for(int i = 1; i <= n; i++) {
    ans = max(ans, a[i] - low);
    low = min(low, a[i]);
  }
  cout << ans << '\n';
        
  return 0;
}