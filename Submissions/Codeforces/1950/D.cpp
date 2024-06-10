#include <bits/stdc++.h>
using namespace std;

vector<int> nums;

void fun(int pos, int x) {
  if (pos == 6) {
    if (x != 0 and x != 1) {
      nums.push_back(x);
    }
    return;
  }
  x = x * 10;
  fun(pos + 1, x);
  x++;
  fun(pos + 1, x);
}

void solve() {
  string s; cin >> s;
  bool ok = true;
  for (auto c : s) {
    ok &= c == '0' or c == '1';
  }
  if (ok) {
    cout << "Yes\n";
    return;
  }

  int n = stoi(s);
  for (auto x : nums) {
    while (n % x == 0) {
      n /= x;
    }
  }

  cout << (n == 1 ? "Yes\n" : "No\n");
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  fun(1, 0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}