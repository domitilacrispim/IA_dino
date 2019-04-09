#include<bits/stdc++.h>
#define TAMPOP 5
#define N 8


typedef struct ind {
	int pos[8];
	int nota;
} ind;

ind pop[5], filho, filha;
int flag=0, pai, mae;

int avalia_individuo(ind a){
    //PRE: ARRAY DE RAINHAS
    //POS: QUANTIDADE DE RAINHAS EM CONFLITO
    int QueenList[N];
    for(int i=0; i<N; i++){
         QueenList[i]=a.pos[i];
    }
    int aux = 0;
    int cont;
    for(int i = 0; i < N - 1; i++){
        cont = 1;
        for(int j =  i + 1; j < N; j++){
            if(QueenList[i] == QueenList[j])
                aux++;
            if(QueenList[j] == QueenList[i] + cont) aux++;
            if( QueenList[j] ==  QueenList[i] - cont) aux++;
            cont++;
        }
    }
    return aux;
}


int torneio (){
    int i1=rand()%5, i2=rand()%5;
    if(pop[i1].nota<pop[i2].nota){
        return i1;
    }
    return i2;
}

int main (){
    int mut;
	srand(time(NULL));
    // gerando a população
    for(int j=0; j<8; j++){
            pop[0].pos[j]=rand()%8;
    }
      pop[0].nota=avalia_individuo(pop[0]);
     if(pop[0].nota==0) return 0;
    for(int i=1; i<TAMPOP; i++){
        for(int j=0; j<8; j++){
            pop[i].pos[j]=rand() % 8;
        }
        pop[i].nota=avalia_individuo(pop[i]);
  //      printf("%d\n", pop[i].nota);
        if(pop[i].nota==0) flag=1;
    }
    while(flag!=1){
        // selecionando pais
        mae=torneio();
        pai=torneio();
        while(pai==mae){
            pai=torneio();
        }
        // fazendo o crusamento
        for(int i=0; i<4; i++){
            filha.pos[i]=pop[mae].pos[i];
            filho.pos[i]=pop[pai].pos[i];
        }
        for(int i=4; i<8; i++){
            filho.pos[i]=pop[mae].pos[i];
            filha.pos[i]=pop[pai].pos[i];
        }
        // mutacação
        mut=rand()%10;
        if(mut==1){
             mut=rand()%8;
            filha.pos[mut]=rand()%8;
        }
        mut=rand()%10;
        if(mut==1){
            mut=rand()%8;
            filho.pos[mut]=rand()%8;
        }
        // avaliação
        filha.nota=avalia_individuo(filha);
      //  printf("%d\n", filha.nota);
        filho.nota=avalia_individuo(filho);
      //  printf("%d\n", filho.nota); //getchar();
        if(filha.nota == 0 ) {
            flag=1;
            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                    if(filha.pos[i]==j) printf(" 1 ");
                    else printf(" 0 ");
                }
                puts("");
            }

        }
        if(filho.nota == 0 ) {
            flag=1;
            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                    if(filho.pos[i]==j) printf(" 1 ");
                    else printf(" 0 ");
                }
                puts("");
            }

        }
        //  reinserção
        for(int i=0; i<TAMPOP; i++){
            if(pop[i].nota>filha.nota){
               pop[i].nota=filha.nota;
               for(int j=0; j<N; j++) pop[i].pos[j]=filha.pos[j];
                break;
            }
        }
        for(int i=TAMPOP-1; i>=0; i--){
            if(pop[i].nota>filho.nota){
                pop[i].nota=filho.nota;
                for(int j=0; j<N; j++) pop[i].pos[j]=filho.pos[j];
                break;
            }
        }

    }

}
