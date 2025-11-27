#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int a[N];

struct node {
  int val;
  node *lc, *rc;
};
node *versions[N];
vector<node *> nodes;

node* build(int b, int e) {
  node *me = new node();
  nodes.push_back(me);
  if (b == e) {
    me->val = 0; // change here
    me->lc = NULL;
    me->rc = NULL;
    return me;
  }
  int mid = (b + e) >> 1;
  me->lc = build(b, mid);
  me->rc = build(mid + 1, e);
  me->val = me->lc->val + me->rc->val; // change here
  return me;
}

node *upd(node *me, int b, int e, int i, int x) {
  node *newme = new node();
  nodes.push_back(newme);
  if (b == e and b == i) {
    newme->val = me->val + x; // change here
    newme->lc = NULL;
    newme->rc = NULL;
    return newme;
  }
  int mid = (b + e) >> 1;
  if (i <= mid) {
    newme->lc = upd(me->lc, b, mid, i, x);
    newme->rc = me->rc;
  }
  else {
    newme->rc = upd(me->rc, mid + 1, e, i, x);
    newme->lc = me->lc;
  }
  newme->val = newme->lc->val + newme->rc->val; // change here
  return newme;
}

// returns kth element
int kth(node *me1, node *me2, int b, int e, int k) {
  if (b == e) {
    return b;
  }
  int cnt = me1->lc->val - me2->lc->val;
  int mid = (b + e) >> 1;
  if (cnt >= k) {
    return kth(me1->lc, me2->lc, b, mid, k);
  }
  return kth(me1->rc, me2->rc, mid + 1, e, k - cnt);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  versions[0] = build(1, v.size()); // change here
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    versions[i] = upd(versions[i - 1], 1, v.size(), a[i], +1);
  }

  while (m--) {
    int l, r, k; cin >> l >> r >> k;
    cout << v[kth(versions[r], versions[l - 1], 1, v.size(), k) - 1] << '\n';
  }

  // must clear memory
  for (node * me : nodes) {
    delete me;
  }
  nodes.clear();

  return 0;
}
// https://www.spoj.com/problems/MKTHNUM/