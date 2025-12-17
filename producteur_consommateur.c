#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define TAILLE_BUFFER 5

// Buffer circulaire
static int buffer[TAILLE_BUFFER];
static int index_prod = 0;
static int index_cons = 0;

// TODO: Initialisé les 3 sémaphores ci-dessous avec les bonnes valeurs initiales via sem_init
// Le deuxième paramètre `0` signifie "partagé entre threads du même processus" (vs `1` pour inter-processus).

static sem_t places_libres;
static sem_t elements_disponibles;  
static sem_t mutex_buffer; // Qulle est le soucis ici ?


void ajouter_buffer(int produit) {
    // Quelle soucis peut on imaginer ici ?
    buffer[index_prod] = produit;
    index_prod = ???;  // Circulaire : utilisez la congruence
}

int retirer_buffer(void) {
    // Quelle soucis peut on imaginer ici ?
    int produit = buffer[index_cons];
    index_cons = ???;  // Circulaire : utilisez la congruence
    return produit;
}


void* thread_producteur(void* arg) {
    int id = *(int*)arg;

    for (int i = 0; i < 10; i++) {
        int produit = id * 100 + i;  // Produit unique

        // TODO: 1. Attendre une place libre
        // TODO: 2. Ajouter l'élément au buffer

        ajouter_buffer(produit);

        printf("[Producteur %d] Ajouté : %d (index=%d)\n", 
               id, produit, (index_prod - 1 + TAILLE_BUFFER) % TAILLE_BUFFER);

        // TODO: 3. Signaler qu'un élément est disponible
        usleep(50);
    }

    printf("[Producteur %d] terminé (10 produits)\n", id);
    return NULL;
}


int main(void) {
    srand(time(NULL));

    // Initialisation des sémaphores

    printf("=== Producteur-Consommateur ===\n");
    printf("Taille buffer : %d\n\n", TAILLE_BUFFER);

    // Scénario : 2 producteurs × 10 = 20 produits
    //            3 consommateurs × 7 = 21 demandes
    // → 1 consommateur va bloquer indéfiniment !

    pthread_t producteurs[2];
    pthread_t consommateurs[3];
    int ids_prod[2] = {1, 2};
    int ids_cons[3] = {1, 2, 3};

    // Démarrage
    // Attendre 2 secondes
    sleep(2);
        // Annuler les threads bloqués (pthread_cancel)
    // Nettoyage

    return 0;
}





