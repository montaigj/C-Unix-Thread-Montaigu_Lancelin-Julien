#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static int compteur_global = 0;

void reset_compteur(void) {
    compteur_global = 0;
}

int get_compteur(void) {
    return compteur_global;
}

void* incrementeur_thread(void* arg) {
    for (int i = 0; i < INCREMENT; i++) {
       
        pthread_mutex_lock(&mutex);
        compteur_global++;  
        pthread_mutex_unlock(&mutex);
        
    }
    return NULL;
}


int executer_test(int nb_threads, int nb_increments) {
    reset_compteur();

    pthread_t* threads = malloc(nb_threads * sizeof(pthread_t));
        // Instancier un tableau de structure pour les arguments.

    // Création des threads
    for (int i = 0; i < nb_threads; i++) 
        pthread_create(&threads[i], NULL, incrementeur_thread, NULL);

    for (int i = 0; i < nb_threads; i++)
        pthread_join(threads[i], NULL);

    int resultat = get_compteur();

    // Qu'est ce qui a été oublié ici ?

    return resultat;
}
