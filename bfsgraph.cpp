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

void bft()
{
queue<int>q;
vector<bool>vis(v,false);
q.push(0);
vis[0]=true;

while(q.size()>0)
{
int u=q.front();
cout<<u<<" ";
q.pop();
for(int nbr:l[u])
{
    if(!vis[nbr])
    {
        q.push(nbr);
        vis[nbr]=true;
    }
}
}
}

};
int main()
{
graph g(5);
g.addedge(0,1);     
g.addedge(1,3);  
g.addedge(1,2);  
g.addedge(2,3);  
g.addedge(2,4);
g.bft();
return 0;

}