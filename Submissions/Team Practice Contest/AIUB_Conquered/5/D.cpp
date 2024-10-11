#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, d, mess[N], clean[N];
bool vis[N];

int f(int l, int r) {
  priority_queue<int> pq;
  int carry = 0, ans = 0;
  for (int i = r; i >= l; i--) {
    pq.push(clean[i]);
    int x = min(mess[i], carry);
    mess[i] -= x;
    carry -= x;
    while (!pq.empty() and mess[i] > 0) {
      ans++;
      int top = pq.top(); pq.pop();
      x = min(mess[i], top);
      mess[i] -= x;
      top -= x;
      if (mess[i] == 0) {
        carry += top;
      }
    }
    if (mess[i] > 0) return -1;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> mess[i] >> clean[i];
  }
  for (int i = 1; i <= d; i++) {
    int x; cin >> x;
    vis[x] = 1;
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int l = i, r = -1;
    for (int j = i; j <= n; j++) {
      if (vis[j]) {
        r = j;
        break;
      }
    }
    if (r != -1) {
      int x = f(l, r);
      ans += x;
      if (x == -1) {
        cout << -1 << '\n';
        return 0;
      }
      i = r;
    }
  }
  cout << ans << '\n';

  return 0;
}