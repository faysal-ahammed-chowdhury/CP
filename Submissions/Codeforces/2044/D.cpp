#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  set<int> se1, se2;
  vector<int> uniq;
  for (int i = 1; i <= n; i++) {
    se2.insert(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    se2.erase(a[i]);
    if (se1.find(a[i]) == se1.end()) uniq.push_back(a[i]);
    se1.insert(a[i]);
  }

  int need = n - uniq.size();
  for (auto x : uniq) {
    cout << x << ' ';
  }
  while (need > 0) {
    cout << *se2.begin() << ' ';
    se2.erase(se2.begin());
    need--;
  }
  cout << '\n';
  assert(need == 0);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}