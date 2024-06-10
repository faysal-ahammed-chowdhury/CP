#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m, x, a[N];
char b[N];
bool vis[N][N];

void fun(int i, int x, set<int> &se) {
  if (i == m + 1) {
    se.insert((x + 1));
    return;
  }
  if (vis[i][x]) {
    return;
  }
  vis[i][x] = true;
  int go1 = (x + a[i]) % n;
  int go2 = (((x - a[i]) % n) + n) % n;
  if (b[i] == '0') {
    fun(i + 1, go1, se);
  }
  else if (b[i] == '1') {
    fun(i + 1, go2, se);
  }
  else {
    fun(i + 1, go1, se);
    fun(i + 1, go2, se);
  }
}

void solve() {
  cin >> n >> m >> x;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
  }

  set<int> se;
  x = (x - 1);
  fun(1, x, se);
  cout << se.size() << '\n';
  for (auto val : se) {
    cout << val << ' ';
  }
  cout << '\n';

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= 1000; j++) {
      vis[i][j] = false;
    }
  }
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