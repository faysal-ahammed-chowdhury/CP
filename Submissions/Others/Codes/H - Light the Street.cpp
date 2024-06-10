#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n, k, d;
double len_for_one_light;

bool ok(double brightness) {
  double r = sqrt((double)d / brightness);
  if(k > 2) {
    double remaining = n - (r * 2);
    double distance = (remaining / (k - 1)) / 2;
    double remaining_brightness = (d / (distance * distance)) * 2;
    if(brightness <= remaining_brightness) return true;
    return false;
  }
  double remaining = len_for_one_light - r;
  double remaining_brightness = (d / (remaining * remaining)) * 2;
  if(brightness <= remaining_brightness) return true;
  return false;
}

void solve() {
  cin >> n >> k >> d;
  len_for_one_light = (double)n / double(k);
  if(k == 1) {
    double r = (double)n / 2.0;
    double ans = ((double)d / (r * r));
    cout << fixed << setprecision(6) << ans << '\n';
    return;
  }
  double l = 0, r = 2e18, ans = -1;
  int it = 100;
  while(it--) {
    double mid = l + (r - l) / 2;
    if(ok(mid)) {
      ans = mid;
      l = mid;
    }
    else {
      r = mid;
    }
  }
  cout << fixed << setprecision(6) << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}