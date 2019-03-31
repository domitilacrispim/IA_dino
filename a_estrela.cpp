#include<bits/stdc++.h>

int grafo[100][100], flag,  tam=0, ini, fim, c1, c2,  ares;
char tabela[100][100], cidade1[100], cidade2[100];
int vert, vis[100], prof, peso[100], cam[100];

int estrela ( int grafo[100][100], int ini, int fim){
	int fila[100], tama=1, flag=0, atual=ini, min=110000, aux;
	fila[0]=ini;
	vis[ini]=1;
	//("PASS"); 
	while(tama>0){
		min=110000;
		//printf("atual -> %s\n", tabela[atual]);
		for(int i=0; i<tam; i++){
			flag=0;
			if(grafo[atual][i]!=-1){
				if(peso[i]==0) { peso[i]=grafo[atual][i]; cam[i]=atual; }
				else if (peso[i]>peso[atual]+grafo[atual][i]) {	peso[i]=peso[atual]+grafo[atual][i];  cam[i]=atual; }
				if(vis[i]==0){
					//printf("%s!", tabela[i]);				
					for( int j=0; j<tama; j++){
						if(i==fila[j]){
							flag=1;			
						}
					}
					if(flag==0){
						fila[tama]=i;
						tama++;
					//	printf("%d ", fila[tama-1]);
							
					}
				}
				flag=0;
			}	
		}
		for(int i=1; i<tama; i++){
			if(min>peso[fila[i]]){
				min=peso[fila[i]];
				flag=fila[i];
				aux=i;
				//printf("MINo");
			}
		}
		tama--;
		fila[0]=flag;
		fila[aux]=fila[tama];
		vis[atual]=1;
		atual=flag;
		if(atual==fim) break;
		
	}
	return peso[c2];
}





int main (){
	int pesu;
	memset(grafo, -1, sizeof(grafo));
	printf("Digite o numero de vertices!\n");
	scanf("%d", &vert);
	printf("Digite o numero de arestas!\n");
	scanf("%d", &ares);
	printf("Digite as arestas!\n");
	for(int i=0; i<ares; i++){
		flag=0;
		getchar();
		scanf("%s %s %d", cidade1, cidade2,  &pesu);
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
		grafo[c1][c2]=pesu;
		grafo[c2][c1]=pesu;
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
 	printf("%d \n", estrela(grafo,c1,c2));
	int auxo=c2;
	while(auxo!=ini){
		printf("%s<-", tabela[auxo]);
		auxo=cam[auxo];
	}
	printf("%s\n", tabela[ini]);

}
