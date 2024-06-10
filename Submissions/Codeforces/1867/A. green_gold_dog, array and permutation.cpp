#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

int gen(int x, int n) {
  return n - x + 1;
}

void solve() {
  int n; cin >> n;
  pair<int, int> a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  pair<int, int> b[n];
  for(int i = 0; i < n; i++) {
    b[i] = a[i];
  }
  sort(b, b + n);
  map<pair<int, int>, int> mp;
  for(int i = 0; i < n; i++) {
    mp[b[i]] = i + 1;
  }
  for(int i = 0; i < n; i++) {
    cout << gen(mp[a[i]], n) << ' ';
  }
  cout << '\n';
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