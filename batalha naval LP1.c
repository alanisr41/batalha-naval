#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#define C 16

int main () {

struct barcos {
int lin, col, pont, pos, tam;
};

setlocale(LC_ALL, "Portuguese");

struct barcos sub, fra, cru, poa, des;
sub.pont = 50;
des.pont = 40;
des.tam  = 2;
fra.pont = 30;
fra.tam  = 3;
cru.pont = 20;
cru.tam  = 4;
poa.pont = 10;
poa.tam  = 5;
char m[C][C]={"\0"}, a[C][C]={"\0"}, d[3]={"DD"}, f[4]={"FFF"}, c[5]={"CCCC"}, p[6]={"PPPPP"};
int i, j, k, linhatiro, colunatiro, contpont=0;
srand(time(NULL));

for(j=0; j<C-1; j++){ //ler as matrizes
    for(i=0; i<C-1; i++){

        m[j][i]='a';
        a[j][i]='a';

    }
}

////////////////////////////////////////           EMBARCAÇÕES             ////////////////////////////////////////////////////////

//submarino
//printf("numeros aleatorios para linha e coluna respectivamente: \n");

sub.lin=rand()%15;
sub.col=rand()%15;

    m[sub.lin][sub.col]='S';


///////////////////////////////////////destroyer

j=0;

//printf("[0]- horizontal, [1]- vertical \n");
des.pos=rand()%2;

switch ( des.pos ){
    case 0 :

    do{ des.col=rand()%15;
        des.lin=rand()%15;}
        while((des.lin+2>=C) && (des.col!='a') && (des.lin!='a') && (des.lin+1!='a'));

      for(i=des.lin; i<des.lin+2; i++){
          m[i][des.col]=d[j];
          j++;
    }
    break;


    case 1 :

    des.lin=rand()%15;
    do{
        des.col=rand()%15;
    }while((des.col+2>=C) && (des.lin!='a') && (des.col!='a') && (des.col+1!='a'));


      for(i=des.col; i<des.col+2; i++){
          m[des.lin][i]=d[j];
          j++;

    }
    break;
  }


///////////////////////////////////////fragata

j=0;

//printf("[0]- horizontal, [1]- vertical \n");

fra.pos=rand()%2;

switch ( fra.pos ){
    case 0 :

    do{
        fra.col=rand()%15;
        fra.lin=rand()%15;

    }while((fra.lin+3>=C) && (fra.col!='a') && (fra.lin!='a') && (fra.lin+1!='a') && (fra.lin+2!='a'));

      for(i=fra.lin; i<fra.lin+3; i++){
          m[i][fra.col]=f[j];
          j++;
    }
    break;
    case 1 :

    do{
        fra.lin=rand()%15;
        fra.col=rand()%15;

    }while((fra.col+3>=C) && (fra.lin!='a') && (fra.col!='a') && (fra.col+1!='a') && (fra.col+2!='a'));


      for(i=fra.col; i<fra.col+3; i++){
          m[fra.lin][i]=f[j];
          j++;
    }
    break;
}

///////////////////////////////////////cruzador

j=0;

//printf("[0]- horizontal, [1]- vertical \n");
cru.pos=rand()%2;

switch ( cru.pos ){
    case 0 :
    do{
        cru.col=rand()%15;
        cru.lin=rand()%15;

    }while((cru.lin+4>=C) && (cru.col!='a') && (cru.lin!='a') && (cru.lin+1!='a') && (cru.lin+2!='a') && (cru.lin+3!='a'));


      for(i=cru.lin; i<cru.lin+4; i++){
          m[i][cru.col]=c[j];
          j++;
    }
    break;
    case 1 :

    do{
        cru.lin=rand()%15;
        cru.col=rand()%15;

    }while((cru.col+4>=C) && (cru.lin!='a') && (cru.col!='a') && (cru.col+1!='a') && (cru.col+2!='a') && (cru.col+3!='a'));


      for(i=cru.col; i<cru.col+4; i++){
          m[cru.lin][i]=c[j];
          j++;
    }
    break;
}

//////////////////////////////////////porta-aviões
j=0;

//printf("[0]- horizontal, [1]- vertical \n");
poa.pos=rand()%2;

switch ( poa.pos ){
    case 0 :

    do{
        poa.col=rand()%15;
        poa.lin=rand()%15;

    }while((poa.lin+5>=C) && (poa.col!='a') && (poa.lin!='a') && (poa.lin+1!='a') && (poa.lin+2!='a') && (poa.lin+3!='a') && (poa.lin+4!='a'));


      for(i=poa.lin; i<poa.lin+5; i++){
          m[i][poa.col]=p[j];
          j++;
    }
    break;
    case 1 :

    do{
        poa.lin=rand()%15;
        poa.col=rand()%15;

    }while((poa.col+5>=C) && (poa.lin!='a') && (poa.col!='a') && (poa.col+1!='a') && (poa.col+2!='a') && (poa.col+3!='a') && (poa.col+4!='a'));

      for(i=poa.col; i<poa.col+5; i++){
          m[poa.lin][i]=p[j];
          j++;
    }
    break;
}

/*for(j=0; j<C-1; j++){ //imprimir a matriz
    for(i=0; i<C-1; i++){
        printf("%c ", m[j][i]);
    }
    printf("\n");
}
*/

////////////////////////////////////////                TIROS               ////////////////////////////////////////////////////////

for(k=0; k<20; k++){

printf("digite as coordenadas da bomba: \n");
printf("linha:");
scanf("%d", &linhatiro);
printf("coluna:");
scanf("%d", &colunatiro);

if(linhatiro < 15 && linhatiro >=0 && colunatiro < 15 && colunatiro >=0 && m[linhatiro][colunatiro] != 'a'){
    a[linhatiro][colunatiro] ='X';
    printf("Acertou!!\n");

		switch(m[linhatiro][colunatiro]){

			case 'S':
				  contpont+=60;
				  printf("você afundou um submarino!!\n");
				  break;

			case 'D':
				  contpont+=10;
				  des.tam--;
				  printf("você acertou um destroyer!\n");
				  if(des.tam==0) {
				  printf("vc afundou o um destroyer!!\n");
				  contpont+=40;
				  }
				  break;

			case 'F':
				  contpont+=10;
				  fra.tam--;
				  printf("vc acertou um fragata!\n");
				  if(fra.tam==0) {
				  printf("vc afundou o um fragata!!\n");
				  contpont+=30;
				  }
				  break;

			case 'C':
				  contpont+=10;
				  cru.tam--;
				  printf("vc acertou um cruzador!\n");
				  if(cru.tam==0) {
				  printf("vc afundou o um cruzador!!\n");
				  contpont+=20;
				  }
                  break;

			case 'P':

				  contpont+=10;
				  poa.tam--;
				  printf("vc acertou um porta-aviões!\n");
				  if(poa.tam==0) {
				  printf("vc afundou o um porta-aviões!!\n");
				  contpont+=10;
				  }
		}
}

else {
a[linhatiro][colunatiro] ='O';
printf("você errou!\n");
}

for(j=0; j<C-1; j++){ //imprimir a matriz
    for(i=0; i<C-1; i++){

        printf("%c ", a[j][i]);

    }
    printf("\n");
}

printf("pontos: %d\n", contpont);
}

return(0);
}
