#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    string s = to_string(i);
    int sum = 0;
    for (auto c : s) {
      sum += c - '0';
    }
    if (sum == k) ans++;
  }

  cout << ans << '\n';

  return 0;
}