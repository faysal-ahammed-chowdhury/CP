#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, s; cin >> n >> s;
  int cnt0 = 0, cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    cnt0 += x == 0;
    cnt1 += x == 1;
    cnt2 += x == 2;
  }

  vector<int> v;
  if (cnt2 > cnt1) {
    v.push_back(2);
    cnt2--;
  }
  if (cnt2 >= cnt1) {
    while (cnt1 > 0) {
      v.push_back(1);
      v.push_back(2);
      cnt1--;
      cnt2--;
    }
    while (cnt2 > 0) {
      v.push_back(2);
      cnt2--;
    }
  }
  else {
    while (cnt1 > 0) {
      v.push_back(1);
      cnt1--;
    }
    while (cnt2 > 0) {
      v.push_back(2);
      cnt2--;
    }
  }

  while (cnt0 > 0) {
    v.push_back(0);
    cnt0--;
  }

  int sum = 0;
  for (auto x : v) {
    sum += x;
  }

  int need = s - sum;
  if (need == 0) {
    cout << -1 << '\n';
    return;
  }
  if (need < 0) {
    for (auto x : v) {
      cout << x << ' ';
    }
    cout << '\n';
    return;
  }

  if (need % 2 == 0) {
    cout << -1 << '\n';
    return;
  }

  need -= 3;
  if (need >= 0 and need % 2 == 0) {
    cout << -1 << '\n';
    return;
  }

  for (auto x : v) {
    cout << x << ' ';
  }
  cout << '\n';
  // cout << sum << '\n';
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