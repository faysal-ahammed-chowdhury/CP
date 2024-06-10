#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

void solve() {
  int n, m; cin >> n >> m;
  vector<int> v;
  for(int i = 0; i < m; i++) {
    v.push_back(i);
  }
  cout << (m == 1 ? 0 : n >= (m - 1) ? m : n + 1) << '\n';
  int start = 0, idx = n;
  for(int i = 0; i < n; i++) {
    if(start >= m - 1) {
      idx = i;
      break;    
    }
    for(int j = start; j < m; j++) {
      cout << v[j] << ' ';
    }
    for(int j = 0; j < start; j++) {
      cout << v[j] << ' ';
    }
    cout << '\n';
    start++;
  }
  for(int i = idx; i < n; i++) {
    for(auto j: v) {
      cout << j << ' ';
    }
    cout << '\n';
  }
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