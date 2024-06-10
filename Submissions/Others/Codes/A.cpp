#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  m *= 60;
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    char ch;
    int start_hr, start_min, end_hr, end_min;
    cin >> start_hr >> ch >> start_min >> end_hr >> ch >> end_min;
    if(start_min > 0) start_hr++;
    ans += ((end_hr - start_hr) * 60);
    if(start_min > 0) {
      ans += (60 - start_min);
    }
    ans += end_min;
  }

  if(ans >= m) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}