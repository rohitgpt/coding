#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#define N 100010
#define p(aaa) cout<<"debug "<<aaa<<endl;
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,d,t,an,x,y;
int ff[N],head[N],a[N*2],next[N*2],g[N],fa[N],dep[N];
inline void add(int x,int y) {
    a[++t]=y,next[t]=head[x],head[x]=t;
    a[++t]=x,next[t]=head[y],head[y]=t;
}
inline void bfs() {
    int l,v;
    //initialize g[1]=1;
    l=1;
    *g=1;
    g[1]=1;
    for (;l<=*g;l++)
        for (v=head[g[l]];v;v=next[v]){
            p(v);
            if (a[v]!=fa[g[l]]) {
                g[++*g]=a[v]; fa[a[v]]=g[l];
            }
        }
    memset(dep,130,sizeof(dep));
    for (l--;l;l--) {
        k=g[l];
        if (ff[k]) dep[k]=0;
        for (v=head[k];v;v=next[v])
        if (a[v]!=fa[k]) dep[k]=max(dep[k],dep[a[v]]+1);
    }
}
void dfs(int x,int y) {
    if (max(dep[x],y)<=d) an++;
    int v,ma,maa;
    ma=maa=-N; if (ff[x]) y=max(y,0);
    for (v=head[x];v;v=next[v])
    if (a[v]!=fa[x]) {
        if (dep[a[v]]>ma) maa=ma,ma=dep[a[v]];
        else maa=max(maa,dep[a[v]]);
    }
    for (v=head[x];v;v=next[v])
    if (a[v]!=fa[x]) {
        int A=dep[a[v]]==ma?maa:ma;
        dfs(a[v],max(y,A+1)+1);
    }
}
int main() {
    scanf("%d%d%d",&n,&m,&d);
    For(i,1,m) scanf("%d",&k),ff[k]=1;
    For(i,1,n-1) {
        scanf("%d%d",&x,&y); add(x,y);
    }
    For(i,1,2*(n-1)) {
        cout<<i<<" "<<a[i]<<" "<<next[i]<<endl;
        // <<head[y]<<" "<<a[t-1]<<" "<<next[t-1]<<endl;
    }
    bfs();
    dfs(1,-N);
    printf("%d\n",an);
    return 0;
}