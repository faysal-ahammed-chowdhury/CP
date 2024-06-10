#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int M, D; cin >> M >> D;
  int y, m, d; cin >> y >> m >> d;
  int day = d + 1;
  if (d + 1 > D) {
    day = 1;
    m++;
  }
  if (m > M) {
    m = 1;
    y++;
  }
  cout << y << ' ' << m << ' ' << day << '\n';

  return 0;
}