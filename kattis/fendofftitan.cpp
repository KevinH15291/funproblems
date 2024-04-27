#include <bits/stdc++.h>

#ifndef cpheader
#define F0R(i,a,b) for (ll i = a; i < b; ++i)
#define f0r(i,b) F0R(i,0,b)
#define F0Rd(i,a,b) for (ll i = a; i >= b; --i)
typedef long long ll;
typedef std::vector<ll> vi;
template <class T, class U>
constexpr bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}
template <typename T, typename U>
constexpr long long powi(T a, U b) {
  long long x = 1;
  f0r(i, b) x*=a;
  return x;
}
#define cpheader
#endif


using namespace std;

bool compare(tuple<ll, ll, ll> l, tuple<ll, ll, ll> r, ll w, ll s) {
  if ((get<0>(l)+(s == 2)) < get<0>(r)) {
    return true;
  } 
  if((get<1>(l)+(s == 1))  < get<1>(r)) {
    return true;
  }
  if(get<2>(l)+w <= get<2>(r)) {
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m, x, y;
  cin >> n >> m >> x >> y;


  unordered_map<ll, vector<tuple<ll, ll, ll>> > adj;
  auto cmp = [](tuple<ll, ll, ll, ll> l, tuple<ll, ll, ll, ll> r) { 
    return (get<0>(l) != get<0>(r) ? (get<0>(l) > get<0>(r)) : (get<1>(l) != get<1>(r) ? (get<1>(l) > get<1>(r)) : (get<2>(l) < get<2>(r) ? false : true)));
    };
  priority_queue<tuple<ll, ll, ll, ll>, vector<tuple<ll, ll, ll, ll>>, decltype(cmp)> que(cmp);
  
  ll a, b, w, d;
  f0r(i, m) {
    cin >> a >> b >> w >> d;
    adj[a].push_back({w, d, b});
    adj[b].push_back({w, d, a});
  }


  vector<tuple<ll, ll, ll>> distance(n+1, {LLONG_MAX, LLONG_MAX, LLONG_MAX});
  vector<bool> visited(n+1, false);
  que.push({0, 0, 0, x});
  distance[x] = {0, 0, 0};

  while(!que.empty()) {
    ll l = get<3>(que.top()); que.pop();
    // cout << l << endl;
    if (visited[l]) continue;
    visited[l] = true;

    for(auto u : adj[l]) {
      ll w = get<0>(u), s = get<1>(u), r = get<2>(u);
      if (compare(distance[l], distance[r], w, s)) {
      get<0>(distance[r]) = get<0>(distance[l]) + (s == 2);
      get<1>(distance[r]) = get<1>(distance[l]) + (s == 1);
      get<2>(distance[r]) = get<2>(distance[l]) + w;
      que.push({get<0>(distance[r]), get<1>(distance[r]), get<2>(distance[r]), r});
          // cout << "r: " << r << " t: " << get<0>(distance[r]) << " s: " << get<1>(distance[r]) << " w: " << get<2>(distance[r]) << endl;
      }
    }
  }

  // for (ll i = 0; i <= n; ++i) {
  //   cout << "i: " << i << " t: " << get<0>(distance[i]) << " s: " << get<1>(distance[i]) << " w: " << get<2>(distance[i]) << endl;
  // }
  if(get<0>(distance[y]) != LLONG_MAX && get<1>(distance[y]) != LLONG_MAX && get<2>(distance[y]) != LLONG_MAX) {
    cout << get<2>(distance[y]) << " " << get<1>(distance[y]) << " " << get<0>(distance[y]);
  } else {
    cout << "IMPOSSIBLE";
  }
  return 0;
}



