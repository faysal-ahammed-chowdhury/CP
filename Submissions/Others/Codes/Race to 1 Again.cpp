#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int n;
double dp[N];
bool vis[N];
vector<int> divs[N];

void prec() {
  for (int x = 1; x <= 100000; x++) {
    for (int i = 1; i * i <= x; i++) {
      if (x % i == 0) {
        divs[x].push_back(i);
        if (i != (x / i)) {
          divs[x].push_back(x / i);
        }
      }
    }
    sort(divs[x].begin(), divs[x].end());
  }
}

double f(int x) {
  if (x == 1) return 0;
  if (vis[x]) return dp[x];
  vis[x] = true;
  double ans = divs[x].size();
  for (int i = 1; i < divs[x].size(); i++) {
    ans += f(x / divs[x][i]);
  }
  ans /= (divs[x].size() - 1);
  dp[x] = ans;
  return ans;
}

int cs;
void solve() {
  cin >> n;

  memset(vis, 0, sizeof vis);
  cout << fixed << setprecision(10);
  cout << "Case " << ++cs << ": " << f(n) << '\n';
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