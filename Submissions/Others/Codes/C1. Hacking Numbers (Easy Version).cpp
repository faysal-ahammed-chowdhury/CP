#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int query(string s, int x) {
  cout << s;
  if (s != "digit") cout << " " << x;
  cout << endl;
  int ans; cin >> ans;
  return ans;
}

void solve() {
  int n; cin >> n;
  query("digit", -1);
  query("digit", -1);
  query("add", -8);
  query("add", -4);
  query("add", -2);
  query("add", -1);
  query("add", n - 1);
  cout << "!" << endl;
  int x; cin >> x;
}

int32_t main() {

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}