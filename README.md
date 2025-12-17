Questions d’analyse (5 pts)

Après implémentation, répondez à ces questions :

    Performance : Quelle version est la plus rapide ? Pourquoi ?
            La version la plus rapide est la version parallele
    Mesurez : Différentes valeurs pour MULTIPLICATEUR, jusqu’a à 10000000 et observez la différence
        La version séquentiel est de plus en plus lente alors que la version parallele est "de plus en plus rapide "
        pour 10, en équentiel on obtient 300 ms 
        pour 10, en parallele on obtien 32
        pour 600000, en séquentiel on obtient environ 800 secondes alors que pour l'autre on obtient environ 60 ms
    Résultats : Les résultats sont-ils identiques entre les versions ? Pourquoi n’y a-t-il pas de race condition ?
        Non ca n'est pas identique, la version parallele est beaucoup plus rapide'
    Vous pouvez écrire les résultats dans un fichiers au format csv (simple)
    Scalabilité : Testez avec différents nombres de threads.
        Pas fait
    Combien de coeur a votre machine virtuel ? vous pouvez regarder dans /proc/cpuinfo
        Ma machine virtuel possède 4 coeurs 
    Que se passe-t-il si vous créez 100 threads pour 10 valeurs ?
        Pas fait, mais ca risque de poser d'immense problemes car nos machines sont pas assez puissantes 
    Proposé un graphique telque visible ci-dessous (bonus)



Race conditions (1h ~ 10 pts)

Observation typique : Vous devriez voir des résultats variables, souvent inférieurs à 9999999. Plus il y a de threads, plus les “pertes” sont fréquentes. Que ce passe t’il ?

Expérimentations suggérées :

    Changez le nombre de threads (1, 2, 5, 10, 20, 40, 60, 100)
    - Impact sur la fréquence des race conditions ?
        Je pense que si on joue sur le nombre de threads, les races conditions devraient augmenter
    - Avec 1 thread, devrait toujours être correct
        En effet ca sera tjrs correct
    Changez le nombre d’incréments par thread
        Même logique plus nombre d'incréments plus les races conditions devraient augmenter 
    - Plus d’opérations = plus de problèmes ?
        Oui, avec la même logique 
    Compilez avec optimisations : gcc -O2 -pthread test_compteur.c
    - Constatez vous des différences, si oui les quelles ?






