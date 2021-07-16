
// Qualquer célula viva com menos de dois vizinhos vivos morre de solidão.
// Qualquer célula viva com mais de três vizinhos vivos morre de superpopulação.
// Qualquer célula morta com exatamente três vizinhos vivos se torna uma célula viva.
// Qualquer célula viva com dois ou três vizinhos vivos continua no mesmo estado para a próxima geração.

#include <iostream>
#include <string>
#include <time.h>
#include <unistd.h>

typedef int** Matriz;

int Tamanho_X=105;
int Tamanho_Y=585;

void printar(Matriz lista);
Matriz gera_novoFrame(Matriz mundo_velho);
int verifica_exterminio(Matriz mundo);
int somando_grid(int x, int y, Matriz mundo);
void deleta(Matriz mundo);
void gerar_pupulaca(Matriz mundo);


int main() {
  int i, j;

  srand(time(NULL));

  //criar mundo
  Matriz mundo=(Matriz)malloc(Tamanho_X*sizeof(int*));
  for (i = 0; i < Tamanho_X; i++)
    mundo[i]=(int*)malloc(Tamanho_Y*sizeof(int));

  gerar_pupulaca(mundo);

  do{
    printar(mundo);
    mundo=gera_novoFrame(mundo);
    usleep(100000);
  }while(verifica_exterminio(mundo));

  printar(mundo);
}

void printar(Matriz Ma){
  int i, j;
  std::string world;

  for (i = 0; i < Tamanho_X; i++){
    for (j = 0; j < Tamanho_Y; j++){
      if(Ma[i][j]==1)
        world+="O";
      else
        world+=" ";
      }
      world+="\n";
  }

  system("clear");
  std::cout<<world;
}

Matriz gera_novoFrame(Matriz mundo_velho){
  int i, j, soma;

  Matriz mundo_novo=(Matriz)malloc(Tamanho_X*sizeof(int*));
  for (i = 0; i < Tamanho_X; i++)
    mundo_novo[i]=(int*)malloc(Tamanho_Y*sizeof(int));

  for (i = 0; i < Tamanho_X; i++)
    for (j = 0; j < Tamanho_Y; j++){
        soma=somando_grid(i, j, mundo_velho);
        //Seleção
        if(mundo_velho[i][j]==1 && soma<2)
          mundo_novo[i][j]=0;
        else if(mundo_velho[i][j]==1 && soma>3)
          mundo_novo[i][j]=0;
        else if(mundo_velho[i][j]==1 && soma>=2 && soma<=3)
          mundo_novo[i][j]=1;
        else if(mundo_velho[i][j]==0 && soma==3)
          mundo_novo[i][j]=1;
        else
          mundo_novo[i][j]=0;
  }
  deleta(mundo_velho);
  return(mundo_novo);
}

int somando_grid(int x, int y, Matriz mundo){
  int i, j, linha, coluna, soma=0;
  for(i=-1; i<2; i++)
    for(j=-1; j<2; j++){
      linha=(x + i + Tamanho_X) % Tamanho_X;
      coluna=(y + j + Tamanho_Y) % Tamanho_Y;
      soma+=mundo[linha][coluna];
  }
  soma-=mundo[x][y];
  return(soma);
}

int verifica_exterminio(Matriz mundo){
  int i, j;
  for (i = 0; i < Tamanho_X; i++)
    for (j = 0; j < Tamanho_Y; j++)
      if(mundo[i][j]==1)
        return(1);
  return(0);
}

void deleta(Matriz mundo){
  int i, j;
  for (i = 0; i < Tamanho_X; i++)
      free(mundo[i]);
  free(mundo);
}

void gerar_pupulaca(Matriz mundo){
  int i, j;
  for (i = 0; i < Tamanho_X; i++)
    for (j = 0; j < Tamanho_Y; j++)
      if(rand()%2==0)
          mundo[i][j]=rand()%3%2;
}
