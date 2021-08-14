#include<bits/stdc++.h>
#define LIM 1003
#define pii pair<int, int>
//incomplete program
using namespace std;
char grid[LIM][LIM];
int vis[LIM][LIM], dis[LIM][LIM], star_Array[LIM], dis2[LIM][LIM], vis2[LIM][LIM];
map<int, int> mp;

int row, column, block_i, block_j, des_r, des_c, cnt_bfs2 = 0, temp = 10000009, min_value;
int cnt = 0, t = 1;
int dr[] = {-1,  1,  0,  0};
int dc[] = { 0,  0, -1,  1};

bool valide(int r, int c)
{
    return r>=0 && r<row && c>=0 && c<column;
}

pii bfs2(int sr, int sc){
    queue<pii>q;
    q.push(pii(sr, sc));
    vis2[sr][sc] = 1;
    dis2[sr][sc] = 0;
    cnt_bfs2 = 1;
    while(!q.empty()){
        pii U = q.front();
        q.pop();
        int ur = U.first;
        int uc = U.second;
        //cout<<endl<<"urbs2 = "<<ur<<" uc = "<<uc<<endl;
        for(int i=0; i<4; i++){
            int vr = ur + dr[i];
            int vc = uc + dc[i];
            //if(valide(vr,vc) && )
            if(valide(vr, vc) && grid[vr][vc] =='*' && !vis2[vr][vc]){
                //cout<<"vrbs2* = "<<vr<<" vcbs2* = "<<vc<<endl;
                return pii(vr,vc);
            }
            else if(valide(vr, vc) && grid[vr][vc] !='#' && !vis2[vr][vc]){
                vis2[vr][vc] = 1;
                //cout<<"vrbs2 = "<<vr<<" vcbs2 = "<<vc<<endl;
                dis2[vr][vc] = dis2[ur][uc]+1;
                q.push(pii(vr,vc));
            }
        }
    }
    return pii(sr, sc);
}

int func(int sr, int sc){

    int upr = sr-1, upc = sc+0;
    int dowr = sr+1, dowc = sc + 0;
    int ler = sr + 0, lec = sc-1;
    int rir = sr + 0, ric = sc + 1;
    if(grid[upr][upc]=='*' || grid[dowr][dowc]=='*' || grid[ler][lec]=='*' || grid[rir][ric]=='*'){
        return 3;
    }
    return -2;
}


int bfs(int sr, int sc){
    int l = 2, o = 0;
    queue<pii>q;
    q.push(pii(sr, sc));
    vis[sr][sc] = 1;
    dis[sr][sc] = 0;
    cnt_bfs2 = 0;
    temp = 10000009;

    int upr = sr-1, upc = sc+0;
    int dowr = sr+1, dowc = sc + 0;
    int ler = sr + 0, lec = sc-1;
    int rir = sr + 0, ric = sc + 1;
    if(grid[upr][upc]=='*' || grid[dowr][dowc]=='*' || grid[ler][lec]=='*' || grid[rir][ric]=='*'){
        //return pii(-2,-2);
        int result2 = func(des_r, des_c);
        //cout<<"reslt2 = "<<result2<<endl;
        if(result2 == 3) return 3;
    }
    while(!q.empty()){
        pii U = q.front();
        q.pop();
        int ur = U.first;
        int uc = U.second;
        //cout<<endl<<"ur = "<<ur<<" uc = "<<uc<<endl;
        for(int i=0; i<4; i++){
            int vr = ur + dr[i];
            int vc = uc + dc[i];
            //cout<<"vr1 = "<<vr<<" vc1 = "<<vc<<endl;
            if(valide(vr, vc) && vis[vr][vc] && grid[vr][vc] !='#'){

                int check_min = dis[vr][vc];
                dis[vr][vc] = dis[ur][uc] + 1;
                dis[vr][vc] = min(check_min, dis[vr][vc]);

            }
            if(valide(vr, vc) && grid[vr][vc] =='D'){
                 dis[vr][vc] = dis[ur][uc]+1;
                 //cout<<" output = "<<dis[vr][vc]+1<<endl;
                 //cout<<"vrD = "<<vr<<" vcD = "<<vc<<endl;
                 //cout<<"temp1 = "<<temp<<endl;
                 min_value = min(dis[vr][vc], temp);
                 temp = min_value;
                 //cout<<"temp2 = "<<temp<<endl;
            }
            else if(valide(vr, vc) && grid[vr][vc] =='*' && !vis[vr][vc]){
                if(cnt_bfs2 == 1) continue;
                vis[vr][vc] = 1;
                dis[vr][vc] = dis[ur][uc] + 1;
                q.push(pii(vr,vc));
                //cout<<"vr*1 = "<<vr<<" vc*1 = "<<vc<<endl;
                //cout<<"dis = "<<dis[vr][vc]<<endl;
                //cout<<"sat i = "<<star_Array[o++]<<" star j = "<<star_Array[o++]<<endl;
                pii D_star = bfs2(des_r, des_c);
                if(D_star.first == vr && D_star.second == vc){
                    dis[vr][vc] = dis[vr][vc] + 2;
                    continue;
                }
                vr = D_star.first;
                vc = D_star.second;
                //cout<<"vr* = "<<vr<<" vc* = "<<vc<<endl;
                dis[vr][vc] = dis[ur][uc] + 1 + 1;
                //cout<<"dis = "<<dis[vr][vc]<<endl;
                q.push(pii(vr,vc));
            }
            else if(valide(vr, vc) && grid[vr][vc] !='#' && !vis[vr][vc]){
                vis[vr][vc] = 1;
                dis[vr][vc] = dis[ur][uc]+1;
                //cout<<"dis = "<<dis[vr][vc]<<endl;
                //cout<<"vr.. = "<<vr<<" vc.. = "<<vc<<endl;
                q.push(pii(vr,vc));
            }
        }
    }
    if(temp == 10000009) return -1;

    return min_value;
}



int main(){
    int T, o = 0;
    cin>>T;
    while(T--){
        //mp.clear();
        int k = 0;
        cnt = 0;
        memset(vis, 0, sizeof vis);
        memset(dis, 0, sizeof dis);
        memset(grid, 0, sizeof grid);
        memset(star_Array, 0, sizeof star_Array);

        memset(vis2, 0, sizeof vis2);
        memset(dis2, 0, sizeof dis2);
        //memset(star_Array, 0, sizeof star_Array);

        cin>>row>>column;
        for(int i=0; i<row; i++) scanf("%s", grid[i]);
        //for(int i=0; i<row; i++) printf("\n%s\n", grid[i]);
        int pr, pc;
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                if(grid[i][j] == 'P'){
                    //cout<<"i = "<<i<<" j = "<<j<<endl;
                    pr = i;
                    pc = j;
                    //cout<<"pr = "<<i<<" pc = "<<j<<endl;
                }
                if(grid[i][j] == '*'){
                   // mp[i] = j;
                    star_Array[k++] = i;
                    star_Array[k++] = j;
                    block_i = i;
                    block_j = j;
                    //cout<<"sat i = "<<star_Array[o++]<<" star j = "<<star_Array[o++]<<endl;
                    ++cnt;
                }
                if(grid[i][j] == 'D'){
                    des_r = i;
                    des_c = j;
                }
            }
        }
        //cout<<"cnt = "<<cnt<<endl;
        //cout<<"pr = "<<pr<<" pc = "<<pc<<endl;
        if(cnt == 1) grid[block_i][block_j] = '#';
        //if()
        //cout<<"grid = "<<grid[block_i][block_j]<<endl;
        //bfs2(des_r, des_c);
        int result = bfs(pr,pc);
        if(result == -1) printf("Case %d: impossible\n", t++);
        else
        printf("Case %d: %d\n", t++, result);
    }
}
