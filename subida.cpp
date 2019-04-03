#include<bits/stdc++.h>

using namespace std;


int safe(vector<vector<int> > & rainha, int N, int linha, int coluna){
	int i, j,  conflito=0;
	for(i = linha, j = coluna; i < N && j < N; i++, j++){
		if(rainha[i][j] == 1) 	conflito++;

	}
	for(i = 0; i < N; i++){
		if(rainha[linha][i] == 1) conflito++;
	}
	for(i = linha, j = coluna; i < N && j >= 0; i++, j--){
		if(rainha[i][j] == 1) 	conflito++;
	}
	for(i = 0; i < N; i++)	{
		if(rainha[i][coluna] == 1) conflito++;
	}
	for(i = linha, j = coluna; i >= 0 && j >= 0; i--, j--){
		if(rainha[i][j] == 1) 	conflito++;
	}
	for(i = linha, j = coluna; i >= 0 && j < N; i--, j++){
		if(rainha[i][j] == 1) 	conflito++;
	}

	return conflito;
}
int back(vector<vector<int> > & rainha, int N, int coluna, vector<vector<int> > & posi ){
	int conf2=212, x, y, conf=0;
	while(1){
		conf=0;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				posi[i][j]=safe(rainha, N, i, j);
				if(posi[i][j]<conf2){
					conf2=posi[i][j];
					x=i; y=j;

				}
				if(rainha[i][j]==1 && posi[i][j]!=0)  conf++;
			}
		}

		if(conf==0) {
			for(int i=0; i<N; i++){
				for(int j=0; j<N; j++){
					printf(" %d ", rainha[i][j]);
				}
						puts("");
			}

			return 1;
		}
		for(int i=0; i<N; i++){
			rainha[i][y]=0;
		}
		rainha[x][y]=1;
	}
}

int main(int argc, char *argv[]){
	vector<vector<int> > rainha;
	vector<vector<int> > posi;
	int num ;
	printf("Digite o numero de damas");
	scanf("%d", &num);
	int i=0;
	while(i<num){
		vector<int> linhaha(num);
		rainha.push_back(linhaha);
		posi.push_back(linhaha);
		rainha[i][i]=1;
		i++;
	}

	back(rainha, num, 0, posi);

	return 0;
}
//4
//1
//2
//1
//2
