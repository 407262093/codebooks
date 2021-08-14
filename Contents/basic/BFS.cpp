bool visit[maxn];//訪問過的
void BFS(int point){
    queue<int>q;
    q.push(point);
    while(!q.empty()){
        int u = q.front();
        if(visit[u]) continue;//訪問過就下一個
        visit[u] = true;
        for(int i = 0;i<edge[u][i];i++){//連出去的線丟到queue
            q.push(edge[u][i]);
        }
    }
}