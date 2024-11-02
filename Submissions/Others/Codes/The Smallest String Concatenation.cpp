#include <bits/stdc++.h>
using namespace std;

bool cmp(string s, string t) {
  return s + t < t + s;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1, cmp);
  for (auto s : a) cout << s;

  return 0;
}