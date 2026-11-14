#include<iostream>
#include<list>
#include<queue>
using namespace std;
class graph
{
private:
int v;
list<int>*l;
public:
graph(int v)
{
    this->v=v;
    l=new list<int>[v];
}
void addedge(int u ,int v)
{
l[u].push_back(v);
 l[v].push_back(u);
}
void dfshelper(int sr,vector<bool>&vis)
{
cout<<sr<<" ";
 vis[sr]=true;

for(int v:l[sr])
{
    if(!vis[v])
    {
        
    dfshelper(v,vis);
    }
}
}
void dfs()
{
    vector <bool>vis(v,false);
    int u=0;
    dfshelper(u,vis);
    cout<<endl;
}
};
int main()
{
graph g(5);
g.addedge(0,1);     
g.addedge(1,3);  
g.addedge(1,2);   
g.addedge(2,4);
g.dfs();
return 0;

}