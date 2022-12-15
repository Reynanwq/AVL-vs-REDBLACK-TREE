#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>



/*-------------- FUNCOES REFERENTES A RED-BLACK TREE -----------------*/
//COR DO NÓ
enum nodeColor {
  RED,
  BLACK
};


struct rbNode {
  int data, color;
  struct rbNode *link[2];
};

struct rbNode *root = NULL; 

// Create a red-black tree
struct rbNode *createNode(int data) {
  struct rbNode *newnode = (struct rbNode *)malloc(sizeof(struct rbNode));
  newnode->data = data;
  newnode->color = RED; //já entra como vermelho
  newnode->link[0] = newnode->link[1] = NULL;
  return newnode;
}


int REDBLACKBfatorDeBalanceamento(struct rbNode *node){
    if(node){
        int left = REDBLACKalturaDaArv(node->link[1]);
        int right = REDBLACKalturaDaArv(node->link[0]);
        int fatbal = (left - right);
      //printf("\n\n\tFB ATUAL :%d\n", fatbal); 
      return fatbal;
      }else{
        return 0;
      }
}


int aux77 = 0, n111=1, n11=1, n22=1;
float NB2;
int REDBLACKpreOrdem(struct rbNode *raiz){
  if(raiz == NULL){
    return 0;
  }else{
    //printf("\n\n\t %d° Nó FATOTBALANCEAMENTO: %d", n,fatorDeBalanceamentoo(raiz));
     n111++;
    aux77 = aux77 + REDBLACKfatorDeBalanceamento(raiz);
    //printf("\n\t %d° Nó SOMA: %d\n", n1, aux7);
    int qtdNO = REDBLACKQuantoNo(raiz);
    REDBLACKpreOrdem(raiz->link[1]);
    REDBLACKpreOrdem(raiz->link[0]);
    //printf("\n\t\tQANTIDADE DE NO: %d\n", qtdNO);
    //printf("\n\t %d° Nó SOMA FINAL: %d\n", n11, aux77);
    aux77 = (aux77 * -1);
    //printf("\n\tRED-BLACK -> %d° Nó SOMA FINAL NEG: %d\n", n11, aux77);
    //printf("\t %d° NIVEL DE BALANCEAMENTO NB: %.2f\n", n2, NB);
    float NB = ((float)aux77/qtdNO);
   // printf("\t %d° NIVEL DE BALANCEAMENTO NB: %.2f\n", n22, NB);
    n11++;
    NB2 = fmax(NB, - NB);
    //printf("\n\n\t RED-BLACK -> %d° NIVEL DE BALANCEAMENTO: %.2f", n22, NB2);
    n22++;
  }  
}

//FUNÇÃO ALTURA DE UMA ÁRVORE
int REDBLACKalturaDaArv(struct rbNode *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int left = REDBLACKalturaDaArv(raiz->link[1]);
        int right = REDBLACKalturaDaArv(raiz->link[0]);
        if(left>right){
            return left + 1;
          }else{
            return right +1;
          }
    }
}

//FUNÇÃO QUNATIDADE DE NÓS NA ARVORE
int REDBLACKQuantoNo(struct rbNode *raiz){
    if(raiz == NULL)
        return 0;
    else
        return 1 + REDBLACKQuantoNo(raiz->link[0]) + REDBLACKQuantoNo(raiz->link[1]);
}


//FUNÇÃO QUE CALCULA E RETORNA O FATOR DE BALANCCEAMENTO DE UM NÓ
//ALTURA DA SUBÁRVORE A ESQUERDA MENOS A AALTURA DA SUBÁRVORE A DIREITA
int REDBLACKfatorDeBalanceamento(struct rbNode *node){
    if(node)
        return (REDBLACKalturaDaArv(node->link[1]) - REDBLACKalturaDaArv(node->link[0]));
    else
        return 0;
}

//FUNÇÃO BALANCEAR
/*
int auxx = 0, numm = 0, QQQQ = 0, rodadaa = 1;
int REDBLACKbalancear(struct rbNode *raiz){
  int fb = REDBLACKfatorDeBalanceamento(raiz);
  QQQQ = REDBLACKQuantoNo(raiz);
  //printf("\n\tQuantidade De NÓ: %d", QQQ);
    if(fb > 1 && REDBLACKfatorDeBalanceamento(raiz->link[1]) >= 0)   {  //Rotação à direita
        //raiz = rotacaoDireita(raiz);
      //  contador();
        //printf("\nrotacao realizada Direita");
        auxx++;
        //printf("\nQuantidade de rotacoes: %d", aux);
       //printf("\n\tQuantidade de Nos da Arvore: %d\n", QQQ);
        float MR = (auxx/(float)QQQQ);
        //printf("\tMedio de Rotações: %.2f\n\n", MR); 
 }   else if(fb < -1 && REDBLACKfatorDeBalanceamento(raiz->link[0]) <= 0){ //Rotação à esquerda
        //raiz = rotacaoEsquerda(raiz);
       // contador();
          //printf("\n\trotacao realizada Esquerda");
          auxx++;
       // printf("\n\tQuantidade de rotacoes: %d", aux);
        // printf("\n\tQuantidade de Nos da Arvore: %d\n", QQQ);
        float MR = (auxx/(float)QQQQ);
        //printf("\tMedio de Rotações: %.2f\n\n", MR);
    }else if(fb > 1 && REDBLACKfatorDeBalanceamento(raiz->link[1]) < 0){ //Rotação esquerda direita
       // raiz = rotacaoEsquerdaDireita(raiz);
        // contador();
          // printf("\n\trotacao realizada EsquerdaDireita");
           auxx = auxx + 2;
        //printf("\n\tQuantidade de rotacoes: %d", aux);
         //printf("\n\tQuantidade de Nos da Arvore: %d\n", QQQ);
        float MR = (auxx/(float)QQQQ);
        //printf("\tMedio de Rotações: %.2f\n\n", MR);
    }else if(fb < -1 && REDBLACKfatorDeBalanceamento(raiz->link[0]) > 0){ //Rotação direita esquerda
        //raiz = rotacaoDireitaEsquerda(raiz);
       // contador();
        //printf("\n\trotacao realizada DireitaEsquerda");
          auxx = auxx + 2;
        //printf("\nQuantidade de rotacoes: %d", aux);
         //printf("\n\tQuantidade de Nos da Arvore: %d\n", QQQ);
        float MR = (auxx/(float)QQQQ);
        //printf("\tMedio de Rotações: %.2f\n\n", MR);
  }
     float mediaRotacao = (auxx/(float)QQQQ);
      printf("\n\t\n \t-> MÉDIA DE ROTAÇÕES: %.2f\n", mediaRotacao);
    return raiz;
}*/


int auxI = 0;
// Inserir em um Nó na VERMELHA E PRETA
void insertion(int data) {      //10 -> 20
  struct rbNode *stack[98];
  struct rbNode *ptr;
  struct rbNode *newnode;
  struct rbNode *xPtr;
  struct rbNode *yPtr;
  int dir[98];
  int ht = 0;
  int index;
  ptr = root;
  //se a raiz nao existir, então criar uma raiz
  if (root == NULL) {
    root = createNode(data);
    return;
  }

  stack[ht] = root;
  dir[ht++] = 0;
  while (ptr != NULL) { //20
    if (ptr->data == data) { //Se o valor que eu immplementar for igual
      printf("Duplicates Not Allowed!!\n");
      return;
    }
    index = (data - ptr->data) > 0 ? 1 : 0;
    stack[ht] = ptr;
    ptr = ptr->link[index];
    dir[ht++] = index;
  }
  stack[ht - 1]->link[index] = newnode = createNode(data);
  while ((ht >= 3) && (stack[ht - 1]->color == RED)) {
    if (dir[ht - 2] == 0) {
      auxI++;
      yPtr = stack[ht - 2]->link[1];
      if (yPtr != NULL && yPtr->color == RED) {
        stack[ht - 2]->color = RED;
        stack[ht - 1]->color = yPtr->color = BLACK;
        ht = ht - 2;
      } else {
        if (dir[ht - 1] == 0) {
          auxI++;
          yPtr = stack[ht - 1];
        } else {
          xPtr = stack[ht - 1];
          yPtr = xPtr->link[1];
          xPtr->link[1] = yPtr->link[0];
          yPtr->link[0] = xPtr;
          stack[ht - 2]->link[0] = yPtr;
        }
        xPtr = stack[ht - 2];
        xPtr->color = RED;
        yPtr->color = BLACK;
        xPtr->link[0] = yPtr->link[1];
        yPtr->link[1] = xPtr;
        if (xPtr == root) {
          root = yPtr;
        } else {
          stack[ht - 3]->link[dir[ht - 3]] = yPtr;
        }
        break;
      }
    } else {
      yPtr = stack[ht - 2]->link[0];
      if ((yPtr != NULL) && (yPtr->color == RED)) {
        stack[ht - 2]->color = RED;
        stack[ht - 1]->color = yPtr->color = BLACK;
        ht = ht - 2;
      } else {
        if (dir[ht - 1] == 1) {
          auxI++;
          yPtr = stack[ht - 1];
        } else {
          auxI++;
          xPtr = stack[ht - 1];
          yPtr = xPtr->link[0];
          xPtr->link[0] = yPtr->link[1];
          yPtr->link[1] = xPtr;
          stack[ht - 2]->link[1] = yPtr;
        }
        xPtr = stack[ht - 2];
        yPtr->color = BLACK;
        xPtr->color = RED;
        xPtr->link[1] = yPtr->link[0];
        yPtr->link[0] = xPtr;
        if (xPtr == root) {
          root = yPtr;
        } else {
          stack[ht - 3]->link[dir[ht - 3]] = yPtr;
        }
        break;
      }
    }
  }
  root->color = BLACK;
  RBrot(auxI, root);
}


int RBrot(int auxI, struct rbNode *raiz){
  int QQ = REDBLACKQuantoNo(raiz);
  float MediaRb = auxI/(float)QQ;
  printf("\n\n\tRED-BLACK -> MEDIA DE ROTAÇÕES: %.2f\n\n", MediaRb);
  printf("\n\nRED-BLACK -> QTD ROTACAO DA REDBLACK: %d\n\n", auxI);
 // printf("\n\nQTD DE NO DA REDBLACK: %d\n\n", QQ);
}

// Print the inorder traversal of the tree
void inorderTraversal(struct rbNode *node, int level) {
  int i;
  if (node) {
    inorderTraversal(node->link[1], level +1);
    printf("\n\n");
    for(i = 0; i < level; i++){
      printf("\t");
    }
    printf("%d", node->data);
    inorderTraversal(node->link[0], level + 1);
  }
}
/*
void imprimir(No *raiz, int nivel){
    int i;
    if(raiz){
        imprimir(raiz->direito, nivel + 1);
        printf("\n\n");

        for(i = 0; i < nivel; i++)
            printf("\t");

        printf("%d", raiz->valor);
        imprimir(raiz->esquerdo, nivel + 1);
    }
}
*/


/*--------FUNCOES REFERENTES A AVL-------------*/



//ESTRUTURA DO NÓ
//REGISTRA A ALTURA DO NÓ
typedef struct no{
    int valor;
    struct no *esquerdo, *direito;
    int altura;
    int balanceamento; 
}No;

//FUNÇÃO CRIA UM NOVO NÓ
No* novoNo(int x){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = x;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;
    }
    else
        printf("\nERRO ao alocar nó em novoNo!\n");
    return novo;
}

//FUNÇÃO QUE INDICA QUAL SUBÁRVORE É MAIOR
int maior(int a, int b){
    return (a > b)? a: b;
}

//FUNÇÃO QUE RETORNA A ALTURA DE UM NÓ
int alturaDoNo(No *no){
    if(no == NULL)
        return -1;
    else
        return no->altura;

}
//FUNÇÃO ALTURA DE UMA ÁRVORE
int alturaDaArv(No *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int left = alturaDaArv(raiz->esquerdo);
        int right = alturaDaArv(raiz->direito);
        if(left>right){
            return left + 1;
          }else{
            return right +1;
          }
    }
}

//FUNÇÃO QUNATIDADE DE NÓS NA ARVORE
int QuantoNo(No *raiz){
    if(raiz == NULL)
        return 0;
    else
        return 1 + QuantoNo(raiz->esquerdo) + QuantoNo(raiz->direito);
}

//FUNÇÃO QUE CALCULA E RETORNA O FATOR DE BALANCCEAMENTO DE UM NÓ
//ALTURA DA SUBÁRVORE A ESQUERDA MENOS A AALTURA DA SUBÁRVORE A DIREITA
int fatorDeBalanceamento(No *no){
    if(no)
        return (alturaDoNo(no->esquerdo) - alturaDoNo(no->direito));
    else
        return 0;
}


int aux5 = 0;
int fatorDeBalanceamentoo(No *no){
    if(no){
        int left = alturaDaArv(no->esquerdo);
        int right = alturaDaArv(no->direito);
        int fatbal = (left - right);
      return fatbal;
      }else{
        return 0;
      }
}

int aux7 = 0, n = 1, n1=1, n2=1;
float NB2;
int preOrdem(No *raiz){
  if(raiz == NULL){
    return 0;
  }else{
    //printf("\n\n\t %d° Nó FATOTBALANCEAMENTO: %d", n,fatorDeBalanceamentoo(raiz));
     n++;
    aux7 = aux7 + fatorDeBalanceamentoo(raiz);
    //printf("\n\t %d° Nó SOMA: %d\n", n1, aux7);
    int qtdNO = QuantoNo(raiz);
    preOrdem(raiz->esquerdo);
    preOrdem(raiz->direito);
    //printf("\n\t\tQANTIDADE DE NO: %d\n", qtdNO);
   //printf("\n\t AVL -> %d° Nó SOMA FINAL: %d\n", n1, aux7);
    //printf("\t %d° NIVEL DE BALANCEAMENTO NB: %.2f\n", n2, NB);
    float NB = ((float)aux7/qtdNO);
    //printf("\t %d° NIVEL DE BALANCEAMENTO NB: %.2f\n", n2, NB);
    n1++;
    NB2 = fmax(NB, - NB);
    //printf("\n\n\t AVL -> %d° NIVEL DE BALANCEAMENTO: %.2f", n2, NB2);
    n2++;
  }  
}


//FUNÇÃO CASO 1 ROTAÇÃO A DIREITA
//QUANDO A ÁRVORE ESTÁ DESBALANCEADA
//SINAL FATOR DE BALANCEAMENTO É POSITIVO (DESBALANCEADA A ESQUERDA)
No* rotacaoDireita(No *r){
    No *y, *f;

    y = r->esquerdo; // y aponta para a subárvore esquerda da raiz r
    f = y->direito;  // f aponta para o filho direito de y

    y->direito = r;   // o filho direito de y passa a ser a raiz r
    r->esquerdo = f;  // o filho esquerdo de r passa a ser f   
  
    // recalcula a altura dos nós que foram movimentados
    r->altura = maior(alturaDoNo(r->esquerdo), alturaDoNo(r->direito)) + 1;
    y->altura = maior(alturaDoNo(y->esquerdo), alturaDoNo(y->direito)) + 1;
    return y;
 
    }

//FUNÇÃO CASO 2 ROTAÇÃO A ESQUERDA
//QUANDO A ÁRVORE ESTÁ DESBALANCEADA
//SINAL FATOR DE BALANCEAMENTO É NEGATIVO (DESBALANCEADA A DIREITA)
No* rotacaoEsquerda(No *r){
    No *y, *f;

    y = r->direito; // y aponta para a subárvore direita da raiz r
    f = y->esquerdo; // f aponta para o filho esquerdo de y

    y->esquerdo = r; // o filho esquerdo de y passa a ser a raiz r
    r->direito = f; // o filho direito de r passa a ser f

    // recalcula a altura dos nós que foram movimentados
    r->altura = maior(alturaDoNo(r->esquerdo), alturaDoNo(r->direito)) + 1;
    y->altura = maior(alturaDoNo(y->esquerdo), alturaDoNo(y->direito)) + 1;
    return y;
   }

//FUNÇÃO CASO 3 DUPLA ROTAÇÃO - ROTAÇÃO ESQUERDA DIREITA
//QUANDO A ÁRVORE ESTA DESBALANCEADA
//SINAL FATOR DE BALANCEAMENTO É POSITIVO (DESBALANCEADA A ESQUERDA)
//PORÉM SUA SUBÁVORE ESTÁ DESALINHADA PARA DIREITA
No* rotacaoEsquerdaDireita(No *r){
    r->esquerdo = rotacaoEsquerda(r->esquerdo); //aplica a função rotação a esquerda na subárvore esquerda de r
    return rotacaoDireita(r);                  //aplica a função rotação a direita na árvore resultante

}

//FUNÇÃO CASO 4 DUPLA ROTAÇÃO - ROTAÇÃO DIREITA ESQUERDA
//QUANDO A ÁRVORE ESTA DESBALANCEADA
//SINAL FATOR DE BALANCEAMENTO É NEGATIVO (DESBALANCEADA A DIREITA)
//PORÉM SUA SUBÁVORE ESTÁ DESALINHADA PARA ESQUERDA
No* rotacaoDireitaEsquerda(No *r){
    r->direito = rotacaoDireita(r->direito); //aplica a função rotação a direita na subárvore direita de r
    return rotacaoEsquerda(r);              //aplica a função rotação a esquerda na árvore resultante
    
}


//FUNÇÃO BALANCEAR
int aux = 0, num = 0, QQQ = 0, rodada = 1;
No* balancear(No *raiz){
  int fb = fatorDeBalanceamento(raiz);
  QQQ = QuantoNo(raiz);
  //printf("\n\tQuantidade De NÓ: %d", QQQ);
    if(fb > 1 && fatorDeBalanceamento(raiz->esquerdo) >= 0)   {  //Rotação à direita
        raiz = rotacaoDireita(raiz);
       
        //printf("\nrotacao realizada Direita");
        aux++;
        //printf("\nQuantidade de rotacoes: %d", aux);
       //printf("\n\tQuantidade de Nos da Arvore: %d\n", QQQ);
        float MR = (aux/(float)QQQ);
        //printf("\tMedio de Rotações: %.2f\n\n", MR); 
 }   else if(fb < -1 && fatorDeBalanceamento(raiz->direito) <= 0){ //Rotação à esquerda
        raiz = rotacaoEsquerda(raiz);
       
          //printf("\n\trotacao realizada Esquerda");
          aux++;
       // printf("\n\tQuantidade de rotacoes: %d", aux);
        // printf("\n\tQuantidade de Nos da Arvore: %d\n", QQQ);
        float MR = (aux/(float)QQQ);
        //printf("\tMedio de Rotações: %.2f\n\n", MR);
    }else if(fb > 1 && fatorDeBalanceamento(raiz->esquerdo) < 0){ //Rotação esquerda direita
        raiz = rotacaoEsquerdaDireita(raiz);
         
          // printf("\n\trotacao realizada EsquerdaDireita");
           aux = aux + 2;
        //printf("\n\tQuantidade de rotacoes: %d", aux);
         //printf("\n\tQuantidade de Nos da Arvore: %d\n", QQQ);
        float MR = (aux/(float)QQQ);
        //printf("\tMedio de Rotações: %.2f\n\n", MR);
    }else if(fb < -1 && fatorDeBalanceamento(raiz->direito) > 0){ //Rotação direita esquerda
        raiz = rotacaoDireitaEsquerda(raiz);
      
        //printf("\n\trotacao realizada DireitaEsquerda");
          aux = aux + 2;
        //printf("\nQuantidade de rotacoes: %d", aux);
         //printf("\n\tQuantidade de Nos da Arvore: %d\n", QQQ);
        float MR = (aux/(float)QQQ);
        //printf("\tMedio de Rotações: %.2f\n\n", MR);
  }
     float mediaRotacao = (aux/(float)QQQ);
      printf("\n\tAVL -> QTD DE ROtaCAO %d\n", aux);
      printf("\n\tAVL -> QTD NO %d\n", QQQ);
      printf("\n\t\n \tAVL -> MÉDIA DE ROTAÇÕES: %.2f\n", mediaRotacao);
    return raiz;
}

//FUNÇÃO INSERÇÃO DE UM NOVO NÓ NA ÁRVORE
int aux3 = 0, aux4 = 0, aux6 = 0;
No* inserir(No *raiz, int x){
    if(raiz == NULL) //árvore vazia
        return novoNo(x);
    else{ //inserção será à esquerda ou à direita
        if(x < raiz->valor){
            raiz->esquerdo = inserir(raiz->esquerdo, x);
          }else if(x > raiz->valor){
            raiz->direito = inserir(raiz->direito, x);
          }    
          else
            printf("\nInsercao nao realizada!\nO elemento %d a existe!\n", x);
    }
    
    //Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

    //verifica a necessidade de rebalancear a árvore
    raiz = balancear(raiz);
   /* raiz->balanceamento = fatorDeBalanceamentoo(raiz);
    aux3 = fatorDeBalanceamento(raiz);
    aux4 = aux4 + aux3;
    printf("\n\tSoma Dos Fatores: %d\n", aux4);*/
    return raiz;
}

//FUNÇÃO IMPRIMIR
void imprimir(No *raiz, int nivel){
    int i;
    if(raiz){
        imprimir(raiz->direito, nivel + 1);
        printf("\n\n");

        for(i = 0; i < nivel; i++)
            printf("\t");

        printf("%d", raiz->valor);
        imprimir(raiz->esquerdo, nivel + 1);
    }
}

//FUNÇÃO BUSCAR
No* buscar(No *raiz, int num){
    if(raiz){
        if(num == raiz->valor)
            return raiz;
        else if(num < raiz->valor)
            return buscar(raiz->esquerdo, num);
        else
            return buscar(raiz->direito, num);
    }
    return NULL;
}

No* prog_exp(No* raiz){
    imprimir(raiz, 1);
    //preOrdem(raiz);
    if((balancear(raiz)) != NULL){
      printf("\n\n\tMEDIA DE ROTAÇÕES FINAL: ");
      balancear(raiz);
      printf("\n\tAVL -> ALTURA DA ARVORE: %d\n", alturaDaArv(raiz)); 
    }
    REDBLACKprog_exp(raiz);
    printf("\n\n\tMEDIA DE ROTAÇÕES FINAL: ");
      insertion(raiz);
    
}

int REDBLACKprog_exp(struct rbNode *root){
  int fatb= 0;
    printf("\n\n------------- RED-BLACK TREE -------------\n\n");
    inorderTraversal(root, 1);
     printf("\n\n\tRED-BLACK -> Quantidade de Nos da Arvore: %d\n", REDBLACKQuantoNo(root));
    printf("\tRED-BLACK -> Altura da árvore: %d\n", REDBLACKalturaDaArv(root));
    int left = REDBLACKalturaDaArv(root->link[1]);
    int right = REDBLACKalturaDaArv(root->link[0]);
    if(left>right){
      fatb = left - right;
      printf("\tRED-BLACK -> Fator de Balanceamento da raiz: %d\n", fatb);
    }else{
      fatb = left - right;
      printf("\tRED-BLACK -> Fator de Balanceamento da raiz: %d\n", fatb);
      }
    REDBLACKpreOrdem(root);
    //printf("\n\n\tMEDIA DE ROTAÇÕES FINAL: ");
}

int dado, ins;
No* prog_print(char f[], No *raiz)
{
  printf("\n\n--------------------- AVL ------------------\n\n");
  int fatb = 0;
    FILE *file = fopen(f, "r");
  if(file){
    while(fscanf(file, "%d", &dado) != -1){
  //  printf("%d\n", dado);
    raiz = inserir(raiz, dado);
  insertion(dado);
   //raizRB = inserirRB(raizRB, dado);
    //imprimir(raizRB, 1);
    /*printf("\n\n\tQUANTIDADE DE NÓ DA ÁRVORE: %d", QuantoNo(raiz));*/
      
      //FATOR DE BALANCEAMENTO DA RAIZ: EXIBIR
   int left = alturaDaArv(raiz->esquerdo);
    int right = alturaDaArv(raiz->direito);
    if(left>right){
      fatb = left - right;
      printf("\tFATOR DE BALANCEAMENTO DA RAIZ: %d\n", fatb);
    }else{
      fatb = left - right;
      printf("\tFATOR DE BALANCEAMENTO DA RAIZ: %d\n", fatb);
    }     
  }
   //prog_exp(raiz);
    }else{
        printf("\nArquivo não pode ser aberto!\n");
        getchar();
        exit(0);
    }
  return raiz;
  }


int main(){
    No *raiz = NULL;
    char minhaEntrada[] = ("input6.txt");
    prog_print(minhaEntrada, raiz);
    return 0;
}