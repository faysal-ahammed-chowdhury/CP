#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, inf = 2e9;
int a[N];

bool is_palindrome(int n) {
  int l = 1, r = n;
  while (l < r) {
    if (a[l] != a[r]) return false;
    l++, r--;
  }
  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (is_palindrome(n)) {
    cout << -1 << '\n';
    return 0;
  }

  vector<int> v;
  int l = 1, r = n;
  while (l < r) {
    int x = abs(a[l] - a[r]);
    v.push_back(x);
    l++, r--;
  }
  int x = 0;
  for (auto i : v) {
    x = __gcd(x, i);
  }
  for (int i = 1; i <= n; i++) {
    a[i] %= x;
  }

  if (is_palindrome(n)) {
    cout << x << '\n';
  }
  else {
    cout << 1 << '\n';
  }

  return 0;
}