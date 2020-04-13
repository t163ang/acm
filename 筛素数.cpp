const int MAXN = 1000005;

int pr[MAXN],pn;
bool isp[MAXN];

void init()
{
    for(int i=2;i<MAXN;i++)    
    {    
        if(!isp[i])pr[pn++]=i;
        for(int j=0;j<pn&&i*pr[j]<MAXN;j++)
        {
            isp[i*pr[j]]=1;
            if(i%pr[j]==0)break;
        }
    }
}