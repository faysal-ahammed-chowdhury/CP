#include <bits/stdc++.h>
using namespace std;
#define int long long

int inf = 1e18;
map<int, vector<int>> mp;
int ans;
set<int> se;

void f(int x) {
  if (se.find(x) != se.end()) return;
  se.insert(x);
  for (auto i : mp[x]) {
    if (x + i - 1 != x) f(x + i - 1); 
    ans = max(ans, x + i - 1);
  }
}

void solve() {
  int n; cin >> n;
  mp.clear();
  se.clear();
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int x = a[i] - (n - i + 1);
    mp[x].push_back(i);
  }
  ans  = 0;
  f(0);
  cout << n + ans << '\n';
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