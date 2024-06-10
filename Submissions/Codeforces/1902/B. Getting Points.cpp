#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n, p, l, t; cin >> n >> p >> l >> t;
  int total_week = ((n - 1) / 7) + 1;
  int biweekly = (t * 2) + l;
  int weekly = t + l;
  int biweek = total_week / 2;
  int week = total_week % 2;
  int biweek_need = (p + biweekly - 1) / biweekly;
  int mn1 = min(biweek_need, biweek);
  int score1 = mn1 * biweekly;
  p -= score1;
  p = max(0ll, p);
  int week_need = (p + weekly - 1) / weekly;
  int mn2 = min(week_need, week);
  int score2 = mn2 * weekly;
  p -= score2;
  p = max(0ll, p);
  int need = (p + l - 1) / l;
  cout << n - mn1 - mn2 - need << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}