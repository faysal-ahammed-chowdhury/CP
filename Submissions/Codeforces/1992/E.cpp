#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, x;
string s;

bool check(int a, int b, int len) {
  string s1 = "";
  for (int i = 0, j = 0; i < len; i++, j++) {
    if (j == x) j = 0;
    s1 += s[j];
  }
  int num1 = atoi(s1.c_str());
  int num2 = n * a - b;
  return num1 == num2;
}

void solve() {
  cin >> s;
  n = atoi(s.c_str());
  x = s.size();
  vector<pair<int, int>> v;
  for (int len = 1; len <= 7; len++) {
    for (int a = 1; a <= 10000; a++) {
      int tot = a * x;
      int b = tot - len;
      if (b >= 1 and b <= min(10000, a * n)) {
        if (check(a, b, len)) {
          v.push_back(make_pair(a, b));
        }
      }
    }
  }
  cout << v.size() << '\n';
  for (auto [x, y] : v) cout << x << ' ' << y << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}