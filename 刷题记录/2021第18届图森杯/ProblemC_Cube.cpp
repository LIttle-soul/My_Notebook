//Hello. I'm Peter.
#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<cctype>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double ld;
#define peter cout<<"i am peter"<<endl
#define input freopen("data.txt","r",stdin)
#define INT (0x3f3f3f3f)*2
#define LL (0x3f3f3f3f3f3f3f3f)*2
#define gsize(a) (int)a.size()
#define len(a) (int)strlen(a)
#define slen(s) (int)s.length()
#define pb(a) push_back(a)
#define clr(a) memset(a,0,sizeof(a))
#define clr_minus1(a) memset(a,-1,sizeof(a))
#define clr_INT(a) memset(a,INT,sizeof(a))
#define clr_true(a) memset(a,true,sizeof(a))
#define clr_false(a) memset(a,false,sizeof(a))
#define clr_queue(q) while(!q.empty()) q.pop()
#define clr_stack(s) while(!s.empty()) s.pop()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dep(i, a, b) for (int i = a; i > b; i--)
#define repin(i, a, b) for (int i = a; i <= b; i++)
#define depin(i, a, b) for (int i = a; i >= b; i--)
#define pi 3.1415926535898
#define eps 1e-6
#define MOD 1000000007
#define MAXN
#define N 10
#define M 200
struct Point
{
    ll x[N],y[N],z[N];
    int len;
}poi[M];
void add(int id,ll x,ll y,ll z)
{
    int len=poi[id].len;
    bool ok=true;
    repin(i,1,len)
    {
        if(x==poi[id].x[i] && y==poi[id].y[i] && z==poi[id].z[i])
        {
            ok=false;
            break;
        }
    }
    if(ok)
    {
        poi[id].len++;
        int t=poi[id].len;
        poi[id].x[t]=x;
        poi[id].y[t]=y;
        poi[id].z[t]=z;
    }
}
struct Points
{
    ll x,y,z;
}p[M];
ll dis[M];
int num;
ll Getdistance(ll xx1,ll yy1,ll zz1,ll xx2,ll yy2,ll zz2)
{
    ll t1=xx1-xx2;
    ll t2=yy1-yy2;
    ll t3=zz1-zz2;
    return t1*t1+t2*t2+t3*t3;
}
bool cube()
{
    bool alldifferent=true;
    repin(i,1,8)
    {
        if(!alldifferent) break;
        repin(j,1,8)
        {
            if(i==j) continue;
            if(p[i].x==p[j].x && p[i].y==p[j].y && p[i].z==p[j].z)
            {
                alldifferent=false;
                break;
            }
        }
    }
    if(!alldifferent) return false;
    ll first;
    repin(i,1,8)
    {
        num=0;
        repin(j,1,8)
        {
            if(i==j) continue;
            num++;
            dis[num]=Getdistance(p[i].x,p[i].y,p[i].z,p[j].x,p[j].y,p[j].z);
        }
        sort(dis+1,dis+1+7);
        first=dis[1];
        repin(i,1,7)
        {
            if(i<=3)
            {
                if(dis[i]!=first) return false;
            }
            else if(i>=4 && i<=6)
            {
                if(dis[i]!=2*first) return false;
            }
            else if(i==7)
            {
                if(dis[i]!=3*first) return false;
            }
        }
    }
    return true;
}
void dfs(int last,int sum)
{
    if(sum==8)
    {
        if(cube())
        {
            printf("YES\n");
            repin(i,1,8)
            {
                printf("%lld %lld %lld\n",p[i].x,p[i].y,p[i].z);
            }
            exit(0);
        }
        return;
    }
    int now=last+1;
    int len=poi[now].len;
    repin(i,1,len)
    {
        p[now].x=poi[now].x[i];
        p[now].y=poi[now].y[i];
        p[now].z=poi[now].z[i];
        dfs(now,sum+1);
    }
}
int main()
{
//    input;
    ll x,y,z;
    repin(i,1,8)
    {
        cin>>x>>y>>z;
        poi[i].len=0;
        //6种情况
        add(i,x,y,z);
        add(i,x,z,y);
        add(i,y,x,z);
        add(i,y,z,x);
        add(i,z,x,y);
        add(i,z,y,x);
    }
    dfs(0,0);
    printf("NO\n");
}