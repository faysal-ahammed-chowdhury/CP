#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
using ll = long long;

struct cmp {
  bool operator()(pair<pair<ll, ll>, ll> p1, pair<pair<ll, ll>, ll> p2) const {
    ll score1 = p1.first.first;
    ll penalty1 = p1.first.second;
    ll score2 = p2.first.first;
    ll penalty2 = p2.first.second;
    ll idx1 = p1.second;
    ll idx2 = p2.second;
    if(score1 < score2) return true;
    if(score2 < score1) return false;
    if(score1 == score2) {
      if(penalty1 > penalty2) return true;
      if(penalty1 == penalty2) {
        if(idx1 > idx2) return true;
        return false;
      }
    }
    return false;
  }
};

void solve() {
  int n, m, h; cin >> n >> m >> h;
  priority_queue<pair<pair<ll, ll>, ll>, vector<pair<pair<ll, ll>, ll>>, cmp> pq;
  for(int i = 0; i < n; i++) {
    int a[m];
    for(int j = 0; j < m; j++) {
      cin >> a[j];
    }
    sort(a, a + m);
    ll prefix[m];
    prefix[0] = a[0];
    for(int j = 1; j < m; j++) {
      prefix[j] = prefix[j - 1] + a[j];
    }
    ll j = 0, score = 0, penalty = 0, time = 0;
    while(j < m) {
      if(time + a[j] <= h) {
        penalty += prefix[j];
        time += a[j];
        score++;
        j++;
      }
      else break;
    }
    // cout << score << ' ' << penalty << ' ' << i << '\n';
    pq.push({{score, penalty}, i});
  }

  int sl = 1;
  int now = pq.top().second;
  while(now != 0) {
    pq.pop();
    now = pq.top().second;
    sl++;
  }
  cout << sl << '\n';
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