#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
int main()
{

    string A;
    string B;
    cin>>A>>B;
    vector<int> a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    for(int ind=0; ind<B.size(); ind++)
    {

        if(B[ind] == 'a') a.push_back(ind);
        else if(B[ind] == 'b') b.push_back(ind);
        else if(B[ind] == 'c') c.push_back(ind);
        else if(B[ind] == 'd') d.push_back(ind);
        else if(B[ind] == 'e') e.push_back(ind);
        else if(B[ind] == 'f') f.push_back(ind);
        else if(B[ind] == 'g') g.push_back(ind);
        else if(B[ind] == 'h') h.push_back(ind);
        else if(B[ind] == 'i') i.push_back(ind);
        else if(B[ind] == 'j') j.push_back(ind);
        else if(B[ind] == 'k') k.push_back(ind);
        else if(B[ind] == 'l') l.push_back(ind);
        else if(B[ind] == 'm') m.push_back(ind);
        else if(B[ind] == 'n') n.push_back(ind);
        else if(B[ind] == 'o') o.push_back(ind);
        else if(B[ind] == 'p') p.push_back(ind);
        else if(B[ind] == 'q') q.push_back(ind);
        else if(B[ind] == 'r') r.push_back(ind);
        else if(B[ind] == 's') s.push_back(ind);
        else if(B[ind] == 't') t.push_back(ind);
        else if(B[ind] == 'u') u.push_back(ind);
        else if(B[ind] == 'v') v.push_back(ind);
        else if(B[ind] == 'w') w.push_back(ind);
        else if(B[ind] == 'x') v.push_back(ind);
        else if(B[ind] == 'y') y.push_back(ind);
        else if(B[ind] == 'z') z.push_back(ind);

    }
    int jj = 0;
    int ii = 0;
    while(ii < A.size())
    {


        if(A[ii] == 'a')
        {
            if(a.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = a[jj];
            auto index = lower_bound(a.begin(), a.end(), low);
            cout<<*index<<endl;
            if(*index == a.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = a[*index++];
                ii++;
            }

        }

        if(A[ii] == 'b')
        {
            if(b.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = b[jj];
            auto index = lower_bound(b.begin(), b.end(), low);
             cout<<*index<<endl;
            if(*index == b.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = b[*index++];
                ii++;
            }
        }
        if(A[ii] == 'c')
        {
            if(c.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = c[jj];
            auto index = lower_bound(c.begin(), c.end(), low);
            cout<<*index<<endl;
            if(*index == c.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = c[*index++];
                ii++;
            }
        }
        if(A[ii] == 'd')
        {
            if(d.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = d[jj];
            auto index = lower_bound(d.begin(), d.end(), low);
            cout<<*index<<endl;
            if(*index == d.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = d[*index++];
                ii++;
            }
        }
        if(A[ii] == 'e')
        {
            if(e.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = e[jj];
            auto index = lower_bound(e.begin(), e.end(), low);
             cout<<*index<<endl;
            if(*index == e.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = e[*index++];
                ii++;
            }
        }
        if(A[ii] == 'f')
        {
            if(f.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = f[jj];
            auto index = lower_bound(f.begin(), f.end(), low);
             cout<<*index<<endl;
            if(*index == f.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = f[*index++];
                ii++;
            }
        }
        if(A[ii] == 'g')
        {
            if(g.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = g[jj];
            auto index = lower_bound(g.begin(), g.end(), low);
            cout<<*index<<endl;
            if(*index == g.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = g[*index++];
                ii++;
            }
        }
        if(A[ii] == 'h')
        {
            if(h.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = h[jj];
            auto index = lower_bound(h.begin(), h.end(), low);
            cout<<*index<<endl;
            if(*index == h.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = h[*index++];
                ii++;
            }
        }
        if(A[ii] == 'i')
        {
            if(i.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = i[jj];
            auto index = lower_bound(i.begin(), i.end(), low);
            cout<<*index<<endl;
            if(*index == i.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = i[*index++];
                ii++;
            }
        }
        if(A[ii] == 'j')
        {
            if(j.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = j[jj];
            auto index = lower_bound(j.begin(), j.end(), low);
            cout<<*index<<endl;
            if(*index == j.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = j[*index++];
                ii++;
            }
        }
        if(A[ii] == 'k')
        {
            if(k.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = k[jj];
            auto index = lower_bound(k.begin(), k.end(), low);
            cout<<*index<<endl;
            if(*index == k.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = k[*index++];
                ii++;
            }
        }
        if(A[ii] == 'l')
        {
            if(l.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = l[jj];
            auto index = lower_bound(l.begin(), l.end(), low);
            cout<<*index<<endl;
            if(*index == l.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = l[*index++];
                ii++;
            }
        }
        if(A[ii] == 'm')
        {
            if(m.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = m[jj];
            auto index = lower_bound(m.begin(), m.end(), low);
            cout<<*index<<endl;
            if(*index == m.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = m[*index++];
                ii++;
            }
        }
        if(A[ii] == 'n')
        {
            if(n.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = n[jj];
            auto index = lower_bound(n.begin(), n.end(), low);
            cout<<*index<<endl;
            if(*index == n.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = n[*index++];
                ii++;
            }
        }
        if(A[ii] == 'o')
        {
            if(o.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = o[jj];
            auto index = lower_bound(o.begin(), o.end(), low);
            cout<<*index<<endl;
            if(*index == o.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = o[*index++];
                ii++;
            }
        }
        if(A[ii] == 'p')
        {
            if(p.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = p[jj];
            auto index = lower_bound(p.begin(), p.end(), low);
            cout<<*index<<endl;
            if(*index == p.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = p[*index++];
                ii++;
            }
        }
        if(A[ii] == 'q')
        {
            if(q.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = q[jj];
            auto index = lower_bound(q.begin(), q.end(), low);
            cout<<*index<<endl;
            if(*index == q.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = q[*index++];
                ii++;
            }
        }
        if(A[ii] == 'r')
        {
            if(r.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = r[jj];
            auto index = lower_bound(r.begin(), r.end(), low);
            cout<<*index<<endl;
            if(*index == r.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = r[*index++];
                ii++;
            }
        }
        if(A[ii] == 's')
        {
            if(s.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = s[jj];
            auto index = lower_bound(s.begin(), s.end(), low);
            cout<<*index<<endl;
            if(*index == s.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = s[*index++];
                ii++;
            }
        }
        if(A[ii] == 't')
        {
            if(t.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = t[jj];
            auto index = lower_bound(t.begin(), t.end(), low);
            cout<<*index<<endl;
            if(*index == t.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = t[*index++];
                ii++;
            }
        }
        if(A[ii] == 'u')
        {
            if(u.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = u[jj];
            auto index = lower_bound(u.begin(), u.end(), low);
            cout<<*index<<endl;
            if(*index == u.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = u[*index++];
                ii++;
            }
        }
        if(A[ii] == 'v')
        {
            if(v.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = v[jj];
            auto index = lower_bound(v.begin(), v.end(), low);
            cout<<*index<<endl;
            if(*index == v.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = v[*index++];
                ii++;
            }
        }
        if(A[ii] == 'w')
        {
            if(w.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = w[jj];
            auto index = lower_bound(w.begin(), w.end(), low);
            cout<<*index<<endl;
            if(*index == w.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = w[*index++];
                ii++;
            }
        }
        if(A[ii] == 'x')
        {
            if(x.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = x[jj];
            auto index = lower_bound(x.begin(), x.end(), low);
            cout<<*index<<endl;
            if(*index == x.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = x[*index++];
                ii++;
            }
        }
        if(A[ii] == 'y')
        {

            if(y.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = y[jj];
            auto index = lower_bound(y.begin(), y.end(), low);
            cout<<*index<<endl;
            if(*index == y.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = y[*index++];
                ii++;
            }
        }
        if(A[ii] == 'z')
        {
            if(z.empty())
            {
                cout<<"No subsequence"<<endl;
                break;
            }
            int low = z[jj];
            auto index = lower_bound(z.begin(), z.end(), low);
            cout<<*index<<endl;
            if(*index == z.size())
            {
                cnt++;
                jj = 0;
            }
            else{
                jj = z[*index++];
                ii++;
            }
        }

        if(ii == A.size())
        {
            cout<<"Added "<<cnt<<" times"<<endl;
            break;
        }
    }

}
