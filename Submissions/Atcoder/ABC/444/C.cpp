#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 3e5 + 9;
int n, a[N];
bool taken[N];

bool ok(int sum) {
  multiset<pair<int, int>> ms;
  for (int i = 1; i <= n; i++) {
    ms.insert({a[i], i});
  }
  memset(taken, false, sizeof taken);
  for (int i = n; i >= 1; i--) {
    if (taken[i]) continue;
    taken[i] = true;
    ms.erase(ms.find({a[i], i}));
    int need = sum - a[i];
    if (need < 0) return false;
    if (need == 0) continue;
    auto it = ms.lower_bound(make_pair(need, 0));
    if (it == ms.end()) return false;
    if ((*it).first != need) return false;
    taken[(*it).second] = true;
    ms.erase(it);
  }

  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  if (n == 1) {
    cout << a[1] << '\n';
    return 0;
  }

  vector<int> ans;
  if (ok(a[n])) ans.push_back(a[n]);
  if (ok(a[n] + a[1])) ans.push_back(a[n] + a[1]);

  for (auto x : ans ) {
    cout << x << ' ';
  }
  cout << '\n';

  return 0;
}