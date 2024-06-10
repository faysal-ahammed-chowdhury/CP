#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int inf = 2e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = inf;
  for(int mask = 0; mask < (1 << n); mask++) {
    long long w1 = 0, w2 = 0;
    for(int i = 0; i < n; i++) {
      if(mask & (1 << i)) {
        w1 += a[i];
      }
      else {
        w2 += a[i];
      }
    }
    ans = min(1ll * ans, abs(w1 - w2));
  }
  cout << ans << '\n';

  return 0;
}