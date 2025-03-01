#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 9;
set<int> se;

void prec() {
  for (int i = 1; i < N; i++) {
    ll here = (1ll * i * (i + 1)) / 2;
    ll sq = sqrtl(here);
    while (1ll * sq * sq < here) sq++;
    while (1ll * sq * sq > here) sq--;
    if (1ll * sq * sq == here) {
      se.insert(i);
    }
  }
}

void chk(ll sum) {
  ll sq = sqrtl(sum);
  while (1ll * sq * sq < sum) sq++;
  while (1ll * sq * sq > sum) sq--;
  assert(1ll * sq * sq != sum);
}

void solve() {
  int n; cin >> n;
  ll sum = (1ll * n * (n + 1)) / 2;
  ll sq = sqrtl(sum);
  while (1ll * sq * sq < sum) sq++;
  while (1ll * sq * sq > sum) sq--;
  if (1ll * sq * sq == sum) {
    cout << "-1\n";
    return;
  }

  bool ok = false;
  sum = 0;
  for (int i = 1; i <= n; i++) {
    if (ok) {
      cout << i - 1 << ' ';
      ok = false;
      sum += i - 1;
      chk(sum);
      continue;
    }
    if (se.find(i) != se.end()) {
      cout << i + 1 << ' ';
      ok = true;
      sum += i + 1;
      chk(sum);
    }
    else {
      cout << i << ' ';
      sum += i;
      chk(sum);
    }
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}