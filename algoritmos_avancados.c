#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da árvore (cômodo)
typedef struct Node {
    char roomName[50];
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó
Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->roomName, name);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para construir a árvore da mansão com alguns cômodos
Node* buildMap() {
    Node* hall = createNode("Hall de entrada");
    Node* salaEsq = createNode("Sala à esquerda");
    Node* salaDir = createNode("Sala à direita");
    Node* escritorio = createNode("Escritório");
    Node* cozinha = createNode("Cozinha");
    Node* biblioteca = createNode("Biblioteca");
    
    // Montagem da árvore
    hall->left = salaEsq;
    hall->right = salaDir;
    salaEsq->left = escritorio;
    salaEsq->right = cozinha;
    salaDir->left = NULL;
    salaDir->right = biblioteca;

    return hall;
}

// Função para explorar o mapa, permitindo escolher caminho
void exploreMap(Node* current) {
    char choice;
    while (current != NULL) {
        printf("\nVocê está em: %s\n", current->roomName);
        if (current->left == NULL && current->right == NULL) {
            printf("Este cômodo não tem mais caminhos. Fim da exploração.\n");
            break;
        }
        
        printf("Escolha o caminho (e para esquerda, d para direita): ");
        scanf(" %c", &choice);
        
        if (choice == 'e' && current->left != NULL) {
            current = current->left;
        } else if (choice == 'd' && current->right != NULL) {
            current = current->right;
        } else {
            printf("Caminho inválido. Tente novamente.\n");
        }
    }
}

int main() {
    Node* mansionMap = buildMap();
    exploreMap(mansionMap);
    // Para simplificação, liberação da memória está omitida
    
    return 0;
}



