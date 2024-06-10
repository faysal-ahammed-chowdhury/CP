#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int n; cin >> n;
  pair<int, int> a[n];
  for(int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    a[i].first = x;
    a[i].second = y;
  }

  int mx = -1;
  int ans = -1;
  for(int i = 0; i < n; i++) {
    if(a[i].first <= 10) {
      if(a[i].second > mx) {
        mx = a[i].second;
        ans = i + 1;
      }
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