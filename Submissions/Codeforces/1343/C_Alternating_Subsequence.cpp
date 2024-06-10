#include <bits/stdc++.h>
using namespace std;

// @author: Faaysal

#define ll long long
const int INF = 2e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }
    int mx_pos = -INF, mx_neg = -INF;
    ll sum = 0;
    int last = a[0];
    if (last > 0) mx_pos = last;
    else mx_neg = last;
    for (auto i : a) {
      if (last > 0 && i > 0) {
        mx_pos = max(mx_pos, i);
      }
      else if (last < 0 && i < 0) {
        mx_neg = max(mx_neg, i);
      }
      else if (last > 0 && i < 0) {
        sum += mx_pos;
        mx_pos = -INF;
        mx_neg = max(mx_neg, i);
      }
      else if (last < 0 && i > 0) {
        sum += mx_neg;
        mx_neg = -INF;
        mx_pos = max(mx_pos, i);
      }
      last = i;
    }
    if (mx_pos != -INF) sum += mx_pos;
    if (mx_neg != -INF) sum += mx_neg;
    cout << sum << '\n';
  }

  return 0;
}