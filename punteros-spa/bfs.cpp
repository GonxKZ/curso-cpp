#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(const vector<vector<int>>& g,int inicio){
    vector<bool> visit(g.size(),false);
    queue<int> q;
    visit[inicio]=true;
    q.push(inicio);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        cout<<v<<' ';
        for(int u:g[v]){
            if(!visit[u]){
                visit[u]=true;
                q.push(u);
            }
        }
    }
}

int main(){
    vector<vector<int>> g={{1,2},{2,3},{3},{}}; // grafo simple
    bfs(g,0);
    cout<<endl;
    return 0;
}
