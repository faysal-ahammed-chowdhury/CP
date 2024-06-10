#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a, b;
  map<int, int> mp1, mp2;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    a.push_back(x);
    mp1[x]++;
  }
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    b.push_back(x);
    mp2[x]++;
  }

  vector<int> dupli1, dupli2;
  for (auto [x, y] : mp1) {
    if (y == 2) {
      dupli1.push_back(x);
    }
  }
  for (auto [x, y] : mp2) {
    if (y == 2) {
      dupli2.push_back(x);
    }
  }

  set<int> se;
  for (int i = 1; i <= n; i++) {
    se.insert(i);
  }
  map<int, int> ans1, ans2;
  for (int i = 1; i <= k; i++) {
    if (!dupli1.empty()) {
      ans1[dupli1.back()]++;
      ans1[dupli1.back()]++;
      ans2[dupli2.back()]++;
      ans2[dupli2.back()]++;
      se.erase(dupli1.back());
      se.erase(dupli2.back());
      dupli1.pop_back();
      dupli2.pop_back();
    }
    else {
      ans1[*se.begin()]++;
      ans2[*se.begin()]++;
      se.erase(se.begin());
      ans1[*se.begin()]++;
      ans2[*se.begin()]++;
      se.erase(se.begin());
    }
  }

  for (int i = 0; i < n; i++) {
    if (ans1[a[i]] > 0) {
      cout << a[i] << ' ';
      ans1[a[i]]--;
    }
  }
  cout << '\n';
  for (int i = 0; i < n; i++) {
    if (ans2[b[i]] > 0) {
      cout << b[i] << ' ';
      ans2[b[i]]--;
    }
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}