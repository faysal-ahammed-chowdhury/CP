#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  int x, y; cin >> x >> y;
  set<pair<int, int>> se;
  while(k--) {
    int xi, yi; cin >> xi >> yi;
    se.insert({xi, yi});
  }

  for(auto i: se) {
    int diff = abs(i.first - x) + abs(i.second - y);
    if(diff % 2 == 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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