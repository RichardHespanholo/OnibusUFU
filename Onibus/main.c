#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structs
struct corredor {
	int numero; // numero da fileira
	struct corredor *ant; // tr�s
	struct corredor *prox; // frete
	struct corredor *dir; // cima
	struct corredor *esq; // baixo
};
struct cadeira {
	int posicao; // 1 corredor - 2 janela
	int lc; // lado corredor
	bool status;  // ocupada ou n�o
	struct cadeira *prox; // frente
	struct cadeira *ant; // tras
};

// Fun�oes
void inserir(int num); // Insere a fileira juntamente com as cadeiras
void remover(int num); // Remove a fileira inteira
void busca_cadeira(); // Verifica se a cadeira est� vaga
void busca_fileira(); // Verifica se a fileira escolhida para remo��o existe
void mostrar(); // Mostra os lugares ocupados e desocupados

struct corredor *inicio; // Tornando o inicio global

//Main
void main() {
    inicio=NULL;
    int op, numFileira, remove;
	while (1){
        system("cls");
        printf("                    ONIBUS  ----- By: Richard  e Cecilia.\n\n"); // Quer dar um nome melhorzinho?
        printf(" 1 - Inserir fileira\n 2 - Remover fileira\n 3 - Comprar cadeira\n 4 - Cancelar compra\n 5 - Mostrar cadeiras ocupadas e desocupadas\n 6 - Sair do programa\n\n");
        printf(" Digite uma opcao: ");
        scanf("%d", &op);
		switch (op){
        case 1: // Inserir fileira
            system("cls");
            printf("              ----------------- INSERIR FILEIRA ----------------- \n\n");
            printf(" Qual o numero da fileira que deseja inserir? ");
            scanf("%d", &numFileira);
            inserir(numFileira);
            getch();
            break;
        case 2: // Remover fileira
            system("cls");
            printf("              ----------------- REMOVER FILEIRA ----------------- \n\n");
        	printf(" Qual fileira deseja remover? ");
        	scanf("%d", &numFileira);
        	remover(numFileira);
        	getch();
            break;
        case 3: // Comprar cadeira
            break;
        case 4: // Cancelar compra
            break;
        case 5:// Mostrar cadeiras ocupadas e desocupadas
            system("cls");
            printf("        ---------- CADEIRAS OCUPADAS E DESOCUPADAS POR CORREDOR ---------- \n\n");
            mostrar();
            getch();
            break;
        case 6: // Sair do programa
            system("cls");
            printf("\n\n             .................... Finalizando ! .................... \n\n");
            getch();
            return ;
		}
	}
	return 0;
}

void inserir(int num){
    struct corredor *p;
    struct corredor *corre;
    //cadei= (struct cadeira *) malloc(sizeof(struct cadeira));
    corre = (struct corredor *) malloc(sizeof(struct corredor)); // aloca memoria dentro da funcao mesmo
    if (!corre){
       return ; // nao tem memoria
    }
    else {
        corre->ant=NULL;
        corre->prox=NULL;
        corre->numero=num;
        if (inicio==NULL){ // lista vazia
            inicio=corre;  // inicio aponta para corredor
        }
        else {
            p=inicio;
            while (p->prox!=NULL && !(p->numero > corre->numero)){ // percorre a lista de forma que veja onde deve ser colocado a fileira
                p=p->prox;
            }
            if (p->numero > corre->numero){ // insere antes a fileira
                corre->prox=p;
                corre->ant=p->ant->prox; // o anterior do novo corredor recebe o proximo anteiror do apontamento de p (desenha que voc� entende)
                p->ant->prox=corre; // o proximo anteiror do apontamento de p recebe o corredor
            }
            else if (p->prox==NULL){ // cheguei ao final da lista
                 corre->ant=p; // o proximo do corredor aponta pra onde p aponta
                 p->prox=corre;   // corredor � adicionado no final da lista
            }
        }
   }
    printf("\n Fileira inserida com sucesso! ");
}

void remover(int num){
    /* Pensar se � necess�rio liberar tamb�m o espa�o de memoria das cadeiras separadamente*/
    struct corredor *p;
    p=inicio;
    while (p->numero !=num){
        p=p->prox;
    }
    printf("\n Fileira removida: %d" , p->numero); // mostrando qual fileira foi removida
    if (p==inicio) // removendo do inicio
        inicio=p->prox;
    else
        p->ant=p->prox; // removendo do meio ou qualquer lugar
    free(p); // liberando a fileira inteira
}

void mostrar(){
    struct corredor *p;
    p=inicio;
    if (p==NULL){
        printf("                          !! Onibus em construcao!! ");
    }
    else {
        while (p){
            printf(" Corredor : %d\n", p->numero);
            p=p->prox;
        }
    }
}
