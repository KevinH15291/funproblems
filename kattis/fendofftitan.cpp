#include <bits/stdc++.h>

#ifndef cpheader
#define F0R(i,a,b) for (int i = a; i < b; ++i)
#define f0r(i,b) F0R(i,0,b)
#define F0Rd(i,a,b) for (int i = a; i >= b; --i)
typedef long long ll;
typedef std::vector<int> vi;
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

  int n, m, x, y;
  cin >> n >> m >> x >> y;


  unordered_map<int, vector<tuple<int, int, int>>> adj;
  auto cmp = []{tuple<int, int, int> l, tuple<int, int, int> r} { 
    return (l[0] != r[0] ? (l[0] < r[0]) : (l[1] != r[1] ? (l[1] < r[1]) : (l[2] > r[2]? false : true)));
    };
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> que;
  
  int a, b, c, d;
  f0r(i, m) {
    cin >> a >> b >> c >> d;
    adj[a].push_back({c, d, b});
    adj[b].push_back({c, d, a});
  }


  vector<tuple<int, int, int>> distance(n, {INT_MAX, INT_MAX, INT_MAX});
  vector<bool> visited(n, false);

  while(!que.empty) {
    int a = que.top()[2]; que.pop;

    if (visited[a]) continue;
    vistied[a] = true;

    for(auto u : adj[a]) {
      int l = u[2], r = [];
    }
  }

  return 0;
}
