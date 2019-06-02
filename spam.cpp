#include<bits/stdc++.h>

typedef struct classi{
	char palavra[100];
	double ocor;
	double PSpam;
}classi;




int main (){
	int qtd, op, ini=0, tam=0, flag=0, i, sp;
	char pala[10000];
	double ps, pn;
	classi tab[10000];
	// treinamento
	scanf("%d", &qtd);
	while(qtd--){
		//printf("2!");
		scanf("%d", &sp);
		getchar();
		while(scanf("%s", pala)){
			if(pala[0]=='*') break; //printf("%s", pala);
			
			flag=0;
			for( i=0; i<tam; i++){
				if(strcmp(pala, tab[i].palavra)==0) {
					flag=1; break;			
				}
			}
			if(flag==0){
				strcpy(tab[tam].palavra, pala);
				tab[tam].ocor++;
				tab[tam].PSpam+=sp;					
				tam++;// printf("%s", tab[tam-1].palavra);
			}
			else {
				tab[i].ocor++;
				tab[i].PSpam+=sp;					
				
			}
		}
		
		
	}
	while(1){

		printf("Digite 1 para classificar 1 email ou 2 para sair\n");
		scanf("%d", &op); if(op==2) return 0;
		getchar(); ps=0; pn=0;
		while(1){
			scanf("%s", pala);
			if(pala[0]=='*') break;
			for( i=0; i<tam; i++){
					if(strcmp(pala, tab[i].palavra)==0) {
						pn+=tab[i].ocor-tab[i].PSpam;
						ps+=tab[i].PSpam; //printf("%s", tab[i].palavra);
						break;			
					}
			}
		}
		if(pn<ps) printf("ISSO EH SPAM\n");
		else printf("Email normal\n");
	}
}

// caso de teste 
/*
10
1 compre isso agora promocao *
0 reuniao amanha *
1 voce ganhou um carro 0km *
0 segue anexo o trabalho *
1 quer ganhar 1 milhao de reais ? *
1 que comida de festa junina voce e ? *
0 oi quer comer comida hoje *
0 seu pedido saiu para entrega *
0 seu pagamento esta pendente *
1 a caixa liberou 1000 reais para voce *
1
voce ganhou 200 reais *  
1
nao esquece a reuniao amanha *
2
*/
