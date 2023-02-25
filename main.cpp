#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <fstream>

using namespace std;
//TODO
/*
fix input
Any variable
*/

int func(int n, int m, bool a[5][5], int b[128][128], int bn, const int N, const int M, int ch){
	if(ch>2 && a[n][m]==1){//checks for end of cycle
		cout<<"Test "<<n<<" and "<<m<<" is successful"<<endl;
		return 1;
	} 
	
	for(int i=n+1;i<M;i++){ //
		cout<<"x";
		if(a[n][i]==1){
			cout<<"\nTest "<<n<<" and "<<i<<" is wip - "<<ch<<endl;
			b[n][bn]+=i; bn++;
			func(n,i,a,N,M,++ch);
		}
	}
	cout<<"Test "<<n<<" and "<<m<<" is UNsuccessful"<<endl;
	return 0;
}//outputs: 1-end of chain 0-no more

int main(void)
{
    
    //ifstream inp("input.txt");
    
	const int N=5, M=5;
    bool a[N][M] = {0};
	int sum[N] = {0};
	int b[128][128] = {0};
	int ch,n,m,bn=0;
    
	//manual input
    a[0][1]=1;	//top-down pyramid
	a[0][3]=1;
	a[0][4]=1;
	a[1][0]=1;
    a[1][2]=1;
    a[1][4]=1;
	a[2][1]=1;
	a[2][3]=1;
	a[2][4]=0;
    a[3][0]=1;
    a[3][2]=1;
    a[3][4]=0;
    a[4][0]=1;
    a[4][1]=1;
    a[4][2]=0;
    a[4][3]=0;
    
    //finds with most connections
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			sum[i]+=a[i][j];
		}
    }
    
    for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<"  "<<sum[i]<<endl;
    }
	
	
	for(int i=0;i<N;i++){
		cout<<func(i,i+1,a,b,bn,N,M,0)<<" idk "<<i<<" LETS GO"<<endl;
	}
    
    
    
    
    return 0;
}


