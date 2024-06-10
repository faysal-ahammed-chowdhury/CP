#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  set<int> se;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    se.insert(x);
  }
  cout << se.size() << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}