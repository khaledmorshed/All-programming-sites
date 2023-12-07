#include<bits/stdc++.h>
#define pii pair<int, int>
#define clear(a) memset(a, 0, sizeof(a))

using namespace std;

bool vis[10][10];
int dis[10][10];

//int dr_a[] = {-2, -2, -1, -1,  1,  1,  2,  2};
//int dc_a[] = {-1,  1, -2,  2, -2,  2, -1,  1};

int dr_a[]={1, -1, 1, -1, 2, 2, -2, -2};
int dc_a[]={2, 2, -2, -2, 1, -1, 1, -1};

string s1, s2;

void bfs(int sr, int sc, int dr, int dc){

    queue<pii> q;

    clear(vis);//memset(vis, false, sizeof vis);
    q.push(pii(sr, sc));
    vis[sr][sc] = true;
    dis[sr][sc] = 0;
    memset(dis, 0, sizeof dis);

    while(!q.empty()){

        pii top = q.front();
        q.pop();

        if(top.first == dr && top.second == dc){
            cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<dis[dr][dc]<<" knight moves."<<endl;
        }
        for(int i=0; i<8; i++){
            int fr = top.first + dr_a[i];
            int fc = top.second + dc_a[i];

            if((fr > 0 && fr <= 8) && (fc > 0 && fc <= 8) && !vis[fr][fc]){
                vis[fr][fc] = true;
                dis[fr][fc] = dis[top.first][top.second] + 1;
                q.push(pii(fr, fc));
            }
        }
    }
}

int main(){

    while(cin>>s1>>s2){

        int sr = s1[0] - 96;
        int sc = s1[1] - '0';
        int dr = s2[0] - 96;
        int dc = s2[1] - '0';
        cout<<sr<<" "<<sc<<endl;
        bfs(sr, sc, dr, dc);
    }
        return 0;
}
