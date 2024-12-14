#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;

const int N = 505;
int n, m, x, p, q;
ll a[N][N];
priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
bool vis[N][N];

int dx[] = { +0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = { -1, +1, +0, +0, +1, +1, -1, -1};

bool valid(int i, int j) {
  return i >= 1 and i <= n and j >= 1 and j <= m;
}

void add(int i, int j) {
  vis[i][j] = true;
  for (int k = 0; k < 4; k++) {
    int ii = i + dx[k], jj = j + dy[k];
    if (valid(ii, jj) and !vis[ii][jj]) {
      vis[ii][jj] = true;
      pq.push({a[ii][jj], ii, jj});
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> x;
  cin >> p >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  add(p, q);
  ll ans = a[p][q];
  while (!pq.empty()) {
    ll val = pq.top()[0];
    int i = pq.top()[1];
    int j = pq.top()[2];
    pq.pop();
    if ((i128)val * x < ans) {
      ans += val;
      add(i, j);
    }
    else break;
  }
  cout << ans << '\n';

  return 0;
}