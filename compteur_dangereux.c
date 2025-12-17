#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define INCREMENT 11111111
#define THREAD_COUNT 99

static long long compteur_global = 0;  // Variable partagée MODIFIABLE et MODIFIÉ

void* incrementeur_thread(void* arg) {
    for (int i = 0; i < INCREMENT; i++) {
        // TODO: Expliquer pourquoi, dans le détail, cette ligne qui pose problème
        // Elle va poser probleme car il y a un probleme de race condition avec l'idée de LOAD ADD et STORE 
        // Dans la plupart des cas, ca ne va pas poser probleme, mais il  y aura forcément un cas ou on va lancer le code, et les 2 variables vont être crées   
        //en même temps et le processeur ne saura pas quoi faire ( BUG DE CONCCURRENCE ET NON DETERMINISME )
        compteur_global++;  // RACE CONDITION ICI !
    }
    return NULL;
}

int main(void) {
    printf("=== Compteur Dangereux ===\n");
        long long expected = INCREMENT*THREAD_COUNT;

    pthread_t threads[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++)
        pthread_create(&threads[i], NULL, incrementeur_thread, NULL);

    for (int i = 0; i < THREAD_COUNT; i++)
        pthread_join(threads[i], NULL);

    printf("Valeur attendue : %ld\n", expected);
    printf("Résultat final : %ld\n", compteur_global);
    printf("Différence : %ld\n", expected - compteur_global);

    return 0;
}

