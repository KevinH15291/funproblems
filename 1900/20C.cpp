#include <bits/stdc++.h>

#ifndef cpheader
#define F0R(i,a,b) for (int i = a; i < b; ++i)
#define f0r(i,b) F0R(i,0,b)
#define F0Rd(i,a,b) for (int i = a; i >= b; --i)
typedef long long ll;
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  ll s, e, w;
  unordered_map<ll, vector<pair<ll, ll>>> edges;
  for (int i = 0; i < m; ++i) {
    cin >> s >> e >> w;
    edges[s].push_back({w, e}); edges[e].push_back({w, s});
  }
  
  priority_queue<pair<ll, ll>> que;
  vector<bool> vis(n+1, false);
  vector<ll> dist(n+1, 9223372036854775807);
  vector<ll> prev(n+1, -1);
  que.push({0, 1});
  dist[1] = 0;

  while(!que.empty()) {
    ll a = que.top().second; 
    que.pop();
    if (vis[a]) continue;
    vis[a] = true;
    for(auto u : edges[a]) {
      ll w = u.first, b = u.second;
      if (dist[a]+w < dist[b]) {
        dist[b] = dist[a] + w;
        prev[b] = a;
        que.push({-dist[b], b});
      }
    }
  }
  

  if (dist[n] == 9223372036854775807) {
    cout << -1;
    return 0;
  }
  int i = n, j = 0;

  vi path(n+1);
  while(i != -1) {
    path[j] = i;
    i = prev[i];
    j++;
  }

  F0Rd(k, j-1, 0) {
    cout << path[k] << " "; 
  }


  return 0;
}
