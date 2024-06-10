#include <bits/stdc++.h>
using namespace std;

bool ok(int n) {
  stringstream ss;
  ss << n;
  string s; ss >> s;
  int mul = 1, sum = 0;
  for (auto c : s) {
    int x = c - '0';
    mul *= x;
    sum += x;
  }
  return mul + sum == n;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int ans = 0;
  for (int i = 1; i <= min(n, 100); i++) {
    if (ok(i)) ans++;
  }
  cout << ans << '\n';

  return 0;
}