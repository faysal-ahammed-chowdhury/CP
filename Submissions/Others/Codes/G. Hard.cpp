#include <bits/stdc++.h>
using namespace std;

const int N = 60009, INF = 1e9 + 9;
int n, position[N], velocity[N];

bool ok(double time) {
  double max_left = -INF, min_right = INF;
  for(int i = 1; i <= n; i++) {
    double left = position[i] - (time * velocity[i]);
    double right = position[i] + (time * velocity[i]);
    max_left = max(max_left, left);
    min_right = min(min_right, right);
  }
  return max_left <= min_right;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> position[i];
  }
  for(int i = 1; i <= n; i++) {
    cin >> velocity[i];
  }

  double l = 0, r = INF, ans = -1;
  int it = 100;
  while(it--) {
    double mid = (l + r) / 2;
    if(ok(mid)) {
      ans = mid;
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }

  cout << fixed << setprecision(10) << ans << '\n';

  return 0;
}