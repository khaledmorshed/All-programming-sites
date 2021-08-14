#include<bits/stdc++.h>
#define LIM 1004
#define pii pair<int,int>
//typedef pair<int, int>> pii
using namespace std;

int dr[] = {-1, +1, 0, 0};
int dc[] = {0, 0, -1, +1};

int row, col;
char grid[LIM][LIM];
int vis[LIM][LIM];

bool valid(int r, int c)
{

    return r>=0 && r<row && c>=0 && c<col;
}

int bfs(int sr, int sc)
{

    queue<pii> q; //queue<pair<int, int>> q
    q.push({sr, sc}); //q.push(pii(sr, sc));

    vis[sr][sc] = 1;
    int ans = 1;

    while(!q.empty())
    {
        pii U = q.front();
        q.pop();
        int ur = U.first;
        int uc = U.second;


        for(int i=0; i<4; i++)
        {
            int vr = ur + dr[i];
            int vc = uc + dc[i];

            if(valid(vr, vc) && grid[vr][vc] != '#' && !vis[vr][vc])
            {
                vis[vr][vc] = 1;
                ans++;
                q.push({vr, vc});
            }
        }

    }

    return ans;
}


int main()
{
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        cin>>col>>row;
        for(int i=0; i<row; i++) scanf("%s", grid[i]);

        int pr, pc;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j] == '@')
                {

                    pr = i;
                    pc = j;
                }
            }
        }

        memset(vis, 0, sizeof vis);
        printf("Case %d: %d\n", t, bfs(pr,pc));
    }
}

