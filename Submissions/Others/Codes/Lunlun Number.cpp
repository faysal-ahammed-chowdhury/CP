#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> v;

void f(int sum, int last) {
  if (sum > 10000000000) return;
  v.push_back(sum);
  if (last - 1 >= 0) f(sum * 10 + (last - 1), last - 1);
  f(sum * 10 + (last), last);
  if (last + 1 <= 9) f(sum * 10 + (last + 1), last + 1);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 1; i <= 9; i++) {
    f(i, i);
  }

  sort(v.begin(), v.end());
  // cout << v.size() << '\n';
  // for (auto x : v) cout << x << '\n';
  int k; cin >> k;
  cout << v[k - 1] << '\n';

  return 0;
}