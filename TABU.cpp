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
	for(i = linha+1, j = coluna+1; i < N && j >= 0; i++, j--){
		if(rainha[i][j] == 1 ) 	conflito++;
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

int verificQueen(vector< vector<int> > rainha, int N){
    //PRE: ARRAY DE RAINHAS
    //POS: QUANTIDADE DE RAINHAS EM CONFLITO
    vector<int> QueenList;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
                if(rainha[j][i]==1){
                    QueenList.push_back(j);
                 //   printf("%d", j);
                }
        }
    }
    int aux = 0;
    int cont;


    for(int i = 0; i < N - 1; i++){
        cont = 1;
        for(int j =  i + 1; j < N; j++){
            if(QueenList[i] == QueenList[j] || QueenList[j] == QueenList[i] + cont || QueenList[j] ==  QueenList[i] - cont)
                aux++;
            cont++;
        }
    }
    return aux;
}
int back(vector<vector<int> > & rainha, int N, int coluna, vector<vector<int> > & posi ){
	int conf2=212, x, y, conf=0;
	int posx1=0, posy1=0, posx2=0, posy2=0, i=0;
	while(1){
          //  printf("la");
        i++;
        conf2=212;
		conf=0;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				posi[i][j]=safe(rainha, N, i, j);
				if(posi[i][j]<conf2 && i!=posx1 && i!=posx2 && j!=posy1 && posy2!=j){
					conf2=posi[i][j];
					x=i; y=j;

				}
				if(rainha[i][j]==1 && posi[i][j]!=2)  conf++;
			}
		}
	/*	puts("");
		for(int i=0; i<N; i++){
				for(int j=0; j<N; j++){
                        printf("%d ", rainha[i][j]);
                }
                puts("");
        }
        for(int i=0; i<N; i++){
				for(int j=0; j<N; j++){
                        printf("%d ", posi[i][j]);
                }
                puts("");
        }
        printf("%d %d\n", x, y);
        getchar();

*/
		if( verificQueen(rainha,N)==0) {
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
		if(i%2==0){
            posx1=x;
            posy1=y;
		}
        else {
            posx2=x;
            posy2=y;

        }
	}
}

int main(int argc, char *argv[]){
	vector<vector<int> > rainha;
	vector<vector<int> > posi;
	int vet[100];
	int num ;
	printf("Digite o numero de damas");
	scanf("%d", &num);
	for(int j=0; j<num; j++){
        scanf("%d", &vet[j]);
	}
	int i=0;
	while(i<num){
		vector<int> linhaha(num);
		rainha.push_back(linhaha);
		posi.push_back(linhaha);
		rainha[i][vet[i]]=1;
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
