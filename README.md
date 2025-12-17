Questions d’analyse (5 pts)

Après implémentation, répondez à ces questions :

    Performance : Quelle version est la plus rapide ? Pourquoi ?
            La version la plus rapide est la version parallele
    Mesurez : Différentes valeurs pour MULTIPLICATEUR, jusqu’a à 10000000 et observez la différence
        La version séquentiel est de plus en plus lente alors que la version parallele est "de plus en plus rapide "
    Résultats : Les résultats sont-ils identiques entre les versions ? Pourquoi n’y a-t-il pas de race condition ?
        Non ca n'est pas identique, la version parallele est beaucoup plus rapide'
    Vous pouvez écrire les résultats dans un fichiers au format csv (simple)
    Scalabilité : Testez avec différents nombres de threads.
    Combien de coeur a votre machine virtuel ? vous pouvez regarder dans /proc/cpuinfo
        Ma machine virtuel possède 4 coeurs 
    Que se passe-t-il si vous créez 100 threads pour 10 valeurs ?

        Ca ne va stricitement rien faire à mon avis, il faut augmenter les valeurs pour que les threads prennent de leur intérêt 
    Proposé un graphique telque visible ci-dessous (bonus)

