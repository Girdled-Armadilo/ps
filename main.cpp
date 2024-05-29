#include <iostream>
#include <vector>
#include <queue> 
#include <string.h> 
using namespace std;
int N, M, K; 
int visit[101][101]; 
int map[101][101]; 
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
typedef pair<int, int> ii; 
vector<ii> v; 
int res = 0; 
void bfs(int f, int s){
    queue<ii> q; 
    int cnt = 1; 
    q.push({f, s}); 
    visit[f][s] = 1;
    while(!q.empty()){
        int y = q.front().first;  
        int x = q.front().second; 
        cout << q.size() << "\n"; 
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i]; 
            int ny = y + dy[i];
            if(ny <= 0 || nx <= 0 || ny >= N || nx >= M){
                continue; 
            }
            if(visit[ny][nx]){
                continue; 
            }
            if(!map[ny][nx]){
                continue; 
            }
            else{
                q.push({ny, nx});
                visit[ny][nx] = 1;
                cnt = +1; 
            }
        }
    }
    if(cnt > res){
        res = cnt; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            map[i][j] = 0;
        }
    }
    for(int i = 0; i < K; i++){
        int a, b; cin >> a >> b;
        map[a][b] = 1; 
        v.push_back({a, b}); 
    }
    for(int i = 0; i < K; i++){;
        if(!visit[v[i].first][v[i].second]){
            bfs(v[i].first, v[i].second);
        } 
    }
    cout << res; 
    return 0;
}