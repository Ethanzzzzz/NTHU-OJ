#include<iostream>
#include<vector>
#include<map>
using namespace std;

int N, M, sz, i, s, f, k, s1, stop=0;
long long int j;
long long int c[1000010], x;
vector<long long int> v[1000010]; //kids' candy sets
long long int ans[1000010]={0};
long long int r[1000010]={0}; // record whether the candy is picked

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
    }
    for(i=1; i<=N; i++)
    {
        f=0;
        s=v[i].size();
        vector<long long int> buffer;
        for(k=0; k<s; k++)
        {
            for(j=1; j<=M; j++)
            {
                if(c[j]==v[i][k] && r[j]==0)
                {
                    buffer.push_back(j);
                    r[j]=1;
                    f++;
                    ans[j]=i;
                    break;
                }
            }
            if(f!=(k+1))
            {
                s1=buffer.size();
                for(j=0; j<s1; j++)
                {

                    ans[buffer[j]]=0;
                }
                stop=1;
                break;
            }
        }
        if(stop==1)
        {
            break;
        }
    }

    for(i=1; i<=M; i++)
        cout<<ans[i]<<'\n';

    return 0;
}

