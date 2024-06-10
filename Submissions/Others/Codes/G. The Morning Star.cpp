#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  long long ans = 0;
  map<int, int> rows, cols, mp1, mp2;
  for(int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    ans += rows[x], ans += cols[y];
    ans += mp1[y - x], ans += mp2[x + y];
    mp1[y - x]++, mp2[x + y]++;
    rows[x]++, cols[y]++;
  }
  cout << ans * 2 << '\n';
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