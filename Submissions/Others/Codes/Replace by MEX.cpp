#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N], n;

int find_mex() {
  set<int> missing_numbers;
  for (int i = 0; i <= n; i++) {
    missing_numbers.insert(i);
  }
  for (int i = 0; i < n; i++) { 
    missing_numbers.erase(a[i]);
  }
  return *missing_numbers.begin();
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ans;
  while (!is_sorted(a, a + n)) {
    int mex = find_mex();
    if (mex == n) {
      for (int i = 0; i < n; i++) {
        if (i != a[i]) {
          a[i] = mex;
          ans.push_back(i);
          break;
        }
      }
    }
    else {
      a[mex] = mex;
      ans.push_back(mex);
    }
    // cout << mex << '\n';
    // cout << "NOW: ";
    // for (int i = 0; i < n; i++) {
    //   cout << a[i] << ' ';
    // }
    // cout << '\n';
  }
  cout << ans.size() << '\n';
  for (auto x : ans) {
    cout << ++x << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}