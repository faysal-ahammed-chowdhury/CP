#include <bits/stdc++.h>
using namespace std;

int a[6];
vector<pair<int, string>> v;

void f(int i, string &s, int sum) {
  if (i > 5) {
    if (sum > 0) v.push_back({-sum, s});
    return;
  }
  f(i + 1, s, sum);
  s += char('A' + (i - 1));
  f(i + 1, s, sum + a[i]);
  s.pop_back();
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 1; i <= 5; i++) {
    cin >> a[i];
  }

  string s = "";
  f(1, s, 0);

  sort(v.begin(), v.end());
  for (auto [_, s] : v) {
    cout << s << '\n';
  }

  return 0;
}