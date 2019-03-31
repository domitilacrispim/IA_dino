#include <bits/stdc++.h>

using namespace std;

int safe(vector<vector<int> > & rainha, int N, int linha, int coluna){
	int i, j;
	for(i = linha, j = coluna; i < N && j < N; i++, j++){
		if(rainha[i][j] == 1) 	return 1;
	}
	for(i = 0; i < N; i++){
		if(rainha[linha][i] == 1) return 2;
	}
	for(i = linha, j = coluna; i < N && j >= 0; i++, j--){
		if(rainha[i][j] == 1) 	return 3;
	}
	for(i = 0; i < N; i++)	{
		if(rainha[i][coluna] == 1) return 4;
	}
	for(i = linha, j = coluna; i >= 0 && j >= 0; i--, j--){
		if(rainha[i][j] == 1) 	return 5;
	}
	for(i = linha, j = coluna; i >= 0 && j < N; i--, j++){
		if(rainha[i][j] == 1) 	return 6;
	}
	
	return 0;
}


void back(vector<vector<int> > & rainha, int N, int coluna){
	if(coluna == N){
		printf("__________________________________________\n");
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(rainha[i][j] == 1) printf("1 ");
				else printf( "0 ");
			}
			puts("");
		}
		return;
	}

	for(int i = 0; i < N; i++){
		if(safe(rainha, N, i, coluna)==0){
			rainha[i][coluna] = 1;
			back(rainha, N, coluna + 1);
			rainha[i][coluna] = 0;
		}
	}
}

int main(int argc, char *argv[]){
	
	vector<vector<int> > rainha;
	int num ;
	printf("Digite o numero de damas");
	scanf("%d", &num);
	int i=0;
	while(i<num){
		vector<int> linhaha(num);
		rainha.push_back(linhaha);
		i++;
	}

	back(rainha, num, 0);

	return 0;
}
