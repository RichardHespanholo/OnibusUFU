#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*ok*/ // FAZER UM MENU DE OPÇÕES
// COM RETIRADA E INSERÇÃO , PERGUNTANDO O NUMERO DA FILEIRA , DEPENDENDO DO NUMERO, INSERIR NO MEIO
// RETIRDA, RETIRA DE ONDE QUISER, RETIRA A FILA INTERA
// FAZER UM ESTRUTURA QUE APONTE PARA CIMA, PARA BAIXO E PARA OS LADOS, E DUAS OUTRAS DA ESQUERDA E DA DIREITA QUE APONTAM ENTRE SI
// PENSAR EM COMO FAREI O MECANISMO DE BUSCA DESSE PROGRAMA
// PRIMEIRO TRABALHAR COM A CAIXA QUE APONTA PARA CIMA E PARA BAIXO.
// ------------------------------------------------------------------------------------------------------------------------------------
// PRIORIDADE DE FUNÇÔES
/*ok*/ // 1 - Menu
/*ok*/ // 2 - Struct
// 3 - Inserir
// 4 - BUSCA
// 5 - Vender a cadeira
// 6 - Cancelar a compra
// 7 - Mostrar
// 8 - Remover
// Deixar especificado o que cada função vai fazer e conter

// Structs
struct corredor {
	int numero; // numero da fileira
	struct corredor *ant; // trás
	struct corredor *prox; // frete
	struct corredor *dir; // cima
	struct corredor *esq; // baixo
};
struct cadeira {
	int posicao; // 1 corredor - 2 janela
	int lc; // lado corredor
	bool status;  // ocupada ou não
	struct cadeira *prox; // frente
	struct cadeira *ant; // tras
};

// Funçoes
int insere(int num); // Insere a fileira juntamente com as cadeiras
int remove(); // Remove a fileira inteira
void busca_cadeira(); // Verifica se a cadeira está vaga
void busca_fileira(); // Verifica se a fileira escolhida para remoção existe
void mostra(); // Mostra os lugares ocupados e desocupados

struct corredor *inicio; // Tornando o inicio global

//Main
void main() {
    inicio=NULL;
    int op, cont=0;
	while (1){
        printf(" ONIBUS  ----- By: Richard  e Cecilia.\n\n"); // Quer dar um nome melhorzinho?
        printf(" 1 - Inserir fileira\n 2 - Remover fileira\n 3 - Comprar cadeira\n 4 - Cancelar compra\n 5 - Mostrar cadeiras ocupadas e desocupadas\n 6 -  Sair do programa\n\n");
        printf(" Digite uma opcao: ");
        scanf("%d", &op);
		switch (op){
        case 1: // Inserir fileira
            cont++;
            insere(cont);
            break;
        case 2: // Remover fileira
            break;
        case 3: // Comprar cadeira
            break;
        case 4: // Cancelar compra
            break;
        case 5:// Mostrar cadeiras ocupadas e desocupadas
            break;
        case 6: // Sair do programa
            printf("\n\n                          .................... Finalizando ! .................... ");
            getch();
            return 0;
		}
	}
	return 0;
}

int insere(int num){
    struct corredor *p;
    struct corredor *corre;
    //cadei= (struct cadeira *) malloc(sizeof(struct cadeira)); //
    corre = (struct corredor *) malloc(sizeof(struct corredor));
    if (!corre){
       return 0; // nao tem memoria
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
            while (p->prox!=NULL){
                p=p->prox; // percorre até chegar no final da lista
            }
            corre->prox=p; // o anterior do corredor aponta pra onde p aponta
            p->prox=corre; // quando chega o corredor é adicionado
        }
   }

}

