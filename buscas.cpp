#include<bits/stdc++.h>

char tabela[100][100], cidade1[100], cidade2[100];
int vert, vis[100], prof;
int busca_profundidade (int grafo[100][100], int ini, int fim){
	printf(" %s ",tabela[ini]);
	vis[ini]=1;
	if(ini==fim){
		printf("\n");
		return 0;
	}
    int cam=1000000, aux;
	for(int i=0; i<vert; i++){
		if(grafo[ini][i]>0 && vis[i]==0){
			aux=grafo[ini][i]+busca_profundidade(grafo, i, fim);
		}
		if(aux<cam) cam=aux;
	}
	return cam;
}
int busca_prof (int grafo[100][100], int ini, int fim){
	printf(" %s ",tabela[ini]); if(prof<0) return -1;
	vis[ini]=1;
	if(ini==fim){
        printf("\n");
		return 0;
	}
    int cam=1000000, aux;
	for(int i=0; i<vert; i++){
		if(grafo[ini][i]>0 && vis[i]==0){
                prof--;
			aux=grafo[ini][i]+busca_prof(grafo, i, fim);
            prof++;
		}
		if(aux<cam) cam=aux;
	}
	return cam;
}
int busca_sup (int grafo[100][100], int ini, int fim){
    vis[ini]=1;
   //printf("MAS! %s", tabela[ini]);
	if(ini==fim){
		printf(" %s ", tabela[fim]);
		return 0;
	}
    int cam=1000000, flag=0, zap, aux, mini=39292;
	for(int i=0; i<vert; i++){
            for(int j=0; j<vert; j++){
                if(vis[j]==0 && grafo[ini][j]>0){
                    aux=j;
                    flag=1;
                }
            }
            if(flag==1){
                    zap=busca_sup(grafo, aux, fim)+grafo[ini][aux]; //printf("!!%s!!",tabela[aux]);
                    if(zap<cam){
                        cam=zap;
                    }
            }
            flag=0;
           // printf("onde da erro!?");
	}
	printf( " %s ", tabela[ini]);
	return cam;
}

int busca_uni (int grafo[100][100], int ini, int fim){
    vis[ini]=1;
   //printf("MAS! %s", tabela[ini]);
	if(ini==fim){
		printf(" %s ", tabela[fim]);
		return 0;
	}
    int cam=1000000, flag=0, zap, aux, mini=39292;
	for(int i=0; i<vert; i++){
             mini=39292;
            for(int j=0; j<vert; j++){
                if(vis[j]==0 && grafo[ini][j]>0 && grafo[ini][j]<mini  ){
                    mini=grafo[ini][j];
                    aux=j;
                    flag=1;
                }
            }
            if(flag==1){
                    zap=busca_uni(grafo, aux, fim)+grafo[ini][aux]; //printf("!!%s!!",tabela[aux]);
                    if(zap<cam){
                        cam=zap;
                    }
            }
            flag=0;
           // printf("onde da erro!?");
	}
	printf( " %s ", tabela[ini]);
	return cam;
}
int main (){
	int grafo[100][100], flag, peso, tam=0, ini, fim, c1, c2,  ares;
	memset(grafo, -1, sizeof(grafo));
	printf("Digite o numero de vertices!\n");
	scanf("%d", &vert);
	printf("Digite o numero de arestas!\n");
	scanf("%d", &ares);
	printf("Digite as arestas!\n");
	for(int i=0; i<ares; i++){
		flag=0;
		getchar();
		scanf("%s %s %d", cidade1, cidade2,  &peso);
		for(int j=0; j<tam; j++){
			if(strcmp(tabela[j], cidade1)==0){
				flag++;
				c1=j;
				break;
			}
		}
		if(flag!=1){
			strcpy(tabela[tam], cidade1); c1=tam; tam++;
		}
		flag=0;
		for(int j=0; j<tam; j++){
			if(strcmp(tabela[j], cidade2)==0){
				flag++;
				c2=j;
				break;
			}
		}
		if(flag!=1){
			strcpy(tabela[tam], cidade2); c2=tam; tam++;
		}
		grafo[c1][c2]=peso;
		grafo[c2][c1]=peso;
	}
	printf("Digite inicio e fim:\n");
	scanf("%s %s", cidade1, cidade2);
	for(int j=0; j<tam; j++){
			if(strcmp(tabela[j], cidade1)==0){
				flag++;
				c1=j;
				break;
			}
	}
	for(int j=0; j<tam; j++){
			if(strcmp(tabela[j], cidade2)==0){
				flag++;
				c2=j;
				break;
			}
	}

	flag=0;
	printf("%d\n", busca_profundidade(grafo, c1,c2));
	memset(vis, 0, sizeof(vis));
	printf("\n%d \n", busca_uni(grafo, c1,c2));
    memset(vis, 0, sizeof(vis));
	printf("\n%d \n", busca_sup(grafo, c1,c2));
	printf("Digite a profundidade: " );
	scanf("%d", &prof);
	memset(vis, 0, sizeof(vis));
	printf("%d\n", busca_prof(grafo, c1,c2));

}
