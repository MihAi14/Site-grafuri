
#include <fstream>
using namespace std;
ifstream fin("graf.in");
ofstream fout("graf.out");

int A[21][21],n,m,X[21],P[21],x,y,l;

void afisare()
{
    for(int i=1;i<=l+1;i++)
        fout<<X[i]<<" ";
    fout<<endl;
}

void back(int k)
{
    for(int i=1;i<=n;i++)
        if(!P[i])
        {
            X[k]=i;
            P[i]=1;
            if(A[X[k-1]][X[k]]==1)
                if(k==l+1)
                { if(X[k]==y)
                    afisare();
                }
                else back(k+1);
            P[i]=0;
        }
}

int main()
{
    fin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        fin>>a>>b;
        A[a][b]=A[b][a]=1;
    }
    fin>>x>>y>>l;
    X[1]=x;
    P[x]=1;
    back(2);
    return 0;
}
