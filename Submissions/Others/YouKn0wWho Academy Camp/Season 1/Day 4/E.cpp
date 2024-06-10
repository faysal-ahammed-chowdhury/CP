#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

void solve() {
  int m; cin >> m;
  if(m == 1) {
    cout << 2 << '\n';
    cout << 1 << ' ' << 1 << '\n';
    return;
  }
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  long long now = 1 + 2;
  while(now <= m) {
    v.push_back(now);
    now += v[v.size() - 2];
  }
  cout << v.size() + 1 << '\n';
  for(auto i: v) {
    cout << i << ' ';
  }
  cout << v[v.size() - 2] << '\n';
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