#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
int pere(int tube,int sortir)
{
    printf("Je suis le père %d\n", getpid());

    int a, b,fd,somme;

    printf("entrez deux entiers : ");
    scanf("%d %d", &a, &b);
    
    // envoyer les deux entiers au fils (toujours avec les assert)
    fd = write(tube,&a,sizeof(int));
    
    fd = write(tube,&b,sizeof(int));
    //todo
    fd = wait(NULL);
    assert( fd != -1);
    fd = read(sortir,&somme,sizeof(int));
    printf("LA SOMME EST %d \n",somme);
    // récupérer le résultat envoyé par le fils et l'afficher
    //todo
    return 0;
}

int fils(int entree , int sortir)
{
    printf("    Je suis le fils %d\n", getpid());
    
    // récupérer les deux entiers envoyés par le père
    int entier,fd,somme=0;
    fd = read(entree,&entier,sizeof(int));
    assert( fd == sizeof(int) );
    somme+=entier;
    fd = read(entree,&entier,sizeof(int));
    assert( fd == sizeof(int) );
    somme+=entier;
    //todo
    fd = write(sortir,&somme,sizeof(int) );
    assert(fd == sizeof(int));
    //printf("--%d--",sortir[1]);
    //printf("La somme est %d \n",somme);
    // calculer la somme et l'envoyer au père
    //todo
    return 0;
}


int main()
{
    // créez les deux tubes :
    int entree[2]; // 0 lire // 1 ecrire
    int sortir[2];
    // - ne pas oublier les assert
    // - nommez correctement les variables pour que leurs rôles soient limpides (pas de fds1 et fds2 par exemple)
    //todo
    
    int test ;
    test = pipe(entree);
    assert(test == 0);
    test = pipe(sortir);
    assert( test == 0);
    

    // dupliquer le processus
    int res = fork();
    //todo

    if (res == 0 /* on est le fils */)
    {
        // fermer les extrémités des tubes inutiles
        close(sortir[0]);
        close(entree[1]);
        //todo
        
        // appeler la fonction "fils" uniquement avec les descriptors dont elle a besoin
        test = fils(entree[0],sortir[1]);
        assert(test == 0);
        // todo
        
        // fermer les extrémités restantes
        // todo
    }
    else
    {
        // fermer les extrémités des tubes inutiles
        //todo
        close(sortir[1]);
        close(entree[0]);
        // appeler la fonction "pere" uniquement avec les descriptors dont elle a besoin
        // todo
        test = pere(entree[1],sortir[0]);
        assert( test == 0);
        // fermer les extrémités restantes
        // todo
        
        // attendre la fin du fils
        //todo
    }
    
   
    printf("fin processus %d\n", getpid());
    
    return EXIT_SUCCESS;
}
