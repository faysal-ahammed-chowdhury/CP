#include <bits/stdc++.h>
using namespace std;

#define int long long

void fix(int &rating1, int &rating2, int extra) {
  if (rating1 > rating2) swap(rating1, rating2);
  int need = rating2 - rating1;
  if (need >= extra) {
    rating1 += extra;
  }
  else if (need < extra) {
    rating1 = rating2;
    extra -= need;
    int half = extra / 2;
    rating1 += half;
    rating2 += (extra - half);
  }
}

void fix2(int &rating1, int &rating2, int extra) {
  if (rating1 > rating2) swap(rating1, rating2);
  int need = rating2 - rating1;
  if (need >= extra) {
    rating2 -= extra;
  }
  else if (need < extra) {
    rating2 = rating1;
    extra -= need;
    int half = (extra + 1) / 2;
    rating1 -= half;
    rating2 -= (extra - half);
  }
}

void solve() {
  int n; cin >> n;
  int a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  int rating1 = 0, rating2 = 0, neg = 0, pos = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0 and b[i] == 1) rating2++;
    else if (b[i] == 0 and a[i] == 1) rating1++;
    else if (a[i] == 1 and b[i] == -1) rating1++;
    else if (b[i] == 1 and a[i] == -1) rating2++;
    else if (a[i] == 1 and b[i] == 1) pos++;
    else if (a[i] == -1 and b[i] == -1) neg++;
  }

  if (pos) fix(rating1, rating2, pos);
  if (neg) fix2(rating1, rating2, neg);
  cout << min(rating1, rating2) << '\n';
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