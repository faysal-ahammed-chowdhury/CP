#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k, s, up;

void f(int i, multiset<int> &ms) {
  if (i > n) {
    set<int> se;
    for (auto x : ms) {
      se.insert(x);
    }
    if (se.size() >= k) up++;
    return;
  }
  for (int j = 1; j <= s; j++) {
    ms.insert(j);
    f(i + 1, ms);
    ms.erase(ms.find(j));
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s >> k;
  multiset<int> ms;
  f(1, ms);
  int down = pow(s, n);
  double ans = double(up)/down;
  cout << fixed << setprecision(10);
  // cout << up << ' ' << down << ' ';
  cout << ans << '\n';

  return 0;
}