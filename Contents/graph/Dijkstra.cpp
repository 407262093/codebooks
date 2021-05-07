const long long int INF = 1e18;
const int MAXN = 1000000;
struct Edge {
  int to;
  long long int cost;
  Edge(int v, long long int c) : to(v), cost(c) {}
  bool operator < (const Edge &other) const {
    return cost > other.cost;
  }
};

int n;
long long int dis[MAXN];
vector<Edge> G[MAXN];

void init() {
  for (int i = 0; i < n; i++) {
    G[i].clear();
    dis[i] = INF;
  }
}
void Dijkstra(int st, int ed = -1) {
  priority_queue<Edge> pq;
  pq.emplace(st, 0);
  dis[st] = 0;
  while (!pq.empty()) {
    auto now = pq.top();
    pq.pop();
    if (now.to == ed) {
      return;
    }
    if (now.cost > dis[now.to]) {
      continue;
    }
    for (auto &e : G[now.to]) {
      if (dis[e.to] > now.cost + e.cost) {
        dis[e.to] = now.cost + e.cost;
        pq.emplace(e.to, dis[e.to]);
      }
    }
  }
}