#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

bool is_palindrome(long long x) {
  stringstream ss;
  ss << x;
  string s; ss >> s;
  int n = s.size();
  int l = 0, r = n - 1;
  while (l < r) {
    if (s[l] != s[r]) return false;
    l++, r--;
  }
  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long n; cin >> n;
  long long ans = 1;
  for (int i = 1; i < N; i++) {
    long long x = 1ll * i * i * i;
    if (x > n) break;
    if (is_palindrome(x)) {
      ans = x;
    }
  }

  cout << ans << '\n';

  return 0;
}