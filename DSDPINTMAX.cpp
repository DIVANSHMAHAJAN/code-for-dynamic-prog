
#include<bits/stdc++.h>
using namespace std;

#define INT_MAX 999999
int root;
int n;
int N = 4;
int a[100][100];
int VISITED_ALL ;
int path[100][100];
int dp[100][100];
int  tsp(int mask,int pos){
	if(mask==VISITED_ALL){
		return a[pos][0];
	}
	if(dp[mask][pos]!=-1){

	   return dp[mask][pos];
	}

	int ans = INT_MAX;
    int k;

	for(int city=0;city<n;city++){
		if((mask&(1<<city))==0){

            int z=tsp( mask|(1<<city), city);

		    int newAns = a[pos][city];
            if(z!=INT_MAX&&newAns!=INT_MAX)
            {
            newAns+=z;
            }
            else
            {
                newAns=INT_MAX;
            }
            //newAns+=z;
            if(ans>newAns)
			{
				ans=newAns;
				k=city;
			}
		}
	}
	path[mask][pos]=k;
	return dp[mask][pos] = ans;
}
void display_path(int source)
{
	int count=0,i=0;
	int brr[N];
	for(i=0;i<N;i++)
	{
		brr[i]=-1;
	}

	printf("\n shortest path\t\t: %d ->",source+1);
	while(count<N-1)
	{
		for(i=0;i<(1<<N);i++)
		{
			if(path[i][source]!=-1 && brr[path[i][source]]==-1)
			{
				brr[path[i][source]]++;
				source=path[i][source];
				printf(" %d -> ",source+1);
				count++;
				break;
			}
		}
	}
	printf("%d\n\n",root+1);

}
int main(){
    /* init the dp array */
   cout<<"Enter the no of cities"<<"\n";
    cin>>n;
   memset(a,-1,sizeof(a));

      VISITED_ALL=(1<<n)-1;
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {

            if(a[j][i]!=-1)
            {
                cout<<"DISTANCE ALREADY ENTERED B/W CITIES "<<i+1<<" AND "<<j+1<<"\n";
                a[i][j]=a[j][i];
            }
            else
            {
                cout<<"Enter Dist bw cities"<<" "<<i+1<<" and "<<j+1<<"\n";
                cin>>a[i][j];
            }
        }
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[i][j] = -1;
            			path[i][j]=-1;

        }
    }
    root = 0;
    int x=tsp(1,0);
    if(x!=INT_MAX)
    {
        cout<<"Travelling Saleman Distance is "<<x<<"\n";
    }
	else
    {

        cout<<"NO SUCH PATH EXISTS"<<"\n";
    }
    if(x!=INT_MAX)
    {
	display_path(root);
    }


}
