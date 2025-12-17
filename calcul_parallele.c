#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>


#define TAILLE_DONNEES 10
#define MULTIPLICATEUR 1000

static const int DONNEES[TAILLE_DONNEES] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

typedef struct {
    int valeur;
    int multiplicateur;
    int index;
    int64_t somme_total;
} args_t;

void* calcul_thread(void* arg) {
        // cette fonction est appelé via pthread_create
        // vous savez ce que représente @arg
        // vous notifié au compilateur "cette" address dois être considéré comme args_t
    args_t* args = (args_t*)arg;
        // vous pouvez accéder (read/write) a toutes les variables via `args->`
    return NULL;
}

int main(void) {
    printf("=== Calcul Parallèle ===\n");

    struct timespec debut, fin;
    clock_gettime(CLOCK_MONOTONIC, &debut);

    int64_t somme_total = 0;

    // TODO: Créer un tableau de pthread_t
    pthread_t threads[TAILLE_DONNEES];
    // TODO: Créer un tableau de structures d'arguments
    args_t args[TAILLE_DONNEES];
    // TODO: Créer et démarrer tous les threads
    or(int i = 0; i < TAILLE_DONNES; i++)
    {
        pthread_create(thread[i],NULL); 
    }
        // TODO : Créer tous les threads
    // TODO: Attendre tous les threads
    for(int i = 0; i < TAILLE_DONNES; i++)
    {
        pthread_join(threads[i], NULL); 
    }
    // TODO: Agréger les résultats
    args_t* += somme_total;

    clock_gettime(CLOCK_MONOTONIC, &fin);
    long duree = (fin.tv_sec - debut.tv_sec) * 1000 + (fin.tv_nsec - debut.tv_nsec) / 1000000;

    printf("Résultat total : %ld\n", somme_total);
    printf("Durée : %ld ms\n", duree);

    return 0;
}

