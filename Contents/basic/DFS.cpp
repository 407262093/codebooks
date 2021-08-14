struct Edge {
    int bi,color;//a連接到的bi,通道顏色
    bool operator < (const Edge &other) const{
        return color < other.color;
    }
};
vector<Edge>G[maxn];

void DFS(int me,int mydad,int distance){
    if(dist[me] < distance) return;
    dist[me] = distance;
    for(int i = 0;i<G[me].size();i++){
        int v = G[me][i].bi;
        DFS(v,me,distance+1);
    }
}