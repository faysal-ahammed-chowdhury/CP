#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  set<int> missing_numbers;
  for (int i = 0; i <= n; i++) {
    missing_numbers.insert(i);
  }
  int suffix_mex[n + 1]; // mex from a[i...n] stored at i
  for (int i = n; i >= 1; i--) { 
    missing_numbers.erase(a[i]);
    suffix_mex[i] = *missing_numbers.begin();
  }
  for (int i = 0; i <= n; i++) {
    missing_numbers.insert(i);
  }
  vector<int> ans;
  int idx = 1, i = 1;
  while (i <= n) {
    int mex = suffix_mex[idx];
    ans.push_back(mex);
    vector<int> v;
    do {
      missing_numbers.erase(a[i]);
      v.push_back(a[i]);
      i++;
    } while (i <= n and *missing_numbers.begin() != mex);
    idx = i;
    // cout << idx << '\n';
    for (auto x : v) missing_numbers.insert(x);
  }
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << ' '; cout << '\n';
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