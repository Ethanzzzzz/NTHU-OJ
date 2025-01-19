#include<iostream>
#include<vector>
#include<map>
using namespace std;

int N, M, sz, i, j, s, f;
long long int c[1000010], x;
vector<long long int> v[1000010]; //kids' candy sets
map<long long int, long long int> m, temp;  // m key: candy type, m value: candy index
long long int nxt[1000010]={0}; //nxt[index] ->next same type candy's index
long long int ans[1000010]={0};

int main(void)
{
    cin>>N>>M;
    for(i=1; i<=N; i++)
    {
        cin>>sz;
        for(j=1; j<=sz; j++)
        {
            cin>>x;
            v[i].push_back(x);
        }
    }
    for(i=1; i<=M; i++)
    {
        cin>>c[i];
        if(m.find(c[i])!=m.end())
        {
            nxt[m[c[i]]]=i;
        }
        m[c[i]]=i;
    }
    for(i=M; i>=1; i--)
    {
        m[c[i]]=i;
    }
    for(i=1; i<=N; i++)
    {
        vector<long long int> buffer;
        f=1;
        s=v[i].size();
        for(j=0; j<s; j++)
        {
            if(m[v[i][j]]==0)
            {
                f=0;
                break;
            }
            ans[m[v[i][j]]]=i;
            buffer.push_back(m[v[i][j]]);
            m[v[i][j]]=nxt[m[v[i][j]]];
        }
        if(f==0)
        {
            s=buffer.size();
            for(j=0; j<s; j++)
            {
                ans[buffer[j]]=0;
            }
            break;
        }
    }
    for(i=1; i<=M; i++)
        cout<<ans[i]<<'\n';

    return 0;
}
