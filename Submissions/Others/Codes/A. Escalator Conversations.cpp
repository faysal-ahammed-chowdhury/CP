#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, k, h; cin >> n >> m >> k >> h;
  int heights[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> heights[i];
  } 
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    int height_diff = abs(h - heights[i]);
    if(height_diff % k == 0 && height_diff != 0 && height_diff + k <= m * k) {
      ans++;
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