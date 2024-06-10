#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
long long ans[N];

bool is_palindrome(int x) {
  string s = to_string(x);
  int l = 0, r = s.size() - 1;
  while (l < r) {
    if (s[l] != s[r]) return false;
    l++, r--;
  }
  return true;
}

void solve() {
  int a, b; cin >> a >> b;
  cout << ans[b] - ans[a - 1] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 1; i < N; i++) {
    ans[i] += ans[i - 1];
    int x = i;
    if (is_palindrome(x)) {
      ans[i] += i;
    }
  }

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}