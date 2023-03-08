#include <stdio.h>
#include <stdlib.h>
// inclure les .h nécessaires
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include <wait.h>
#include <string.h>
void recepteur(int fds[2])
{
    printf("Je suis le récepteur %d\n", getpid());
    
    
    // fermeture de l'extrémité inutile
    close(fds[1]);
    //todo (ne pas oublier les assert)
    int size;
    int fd;
    char *c = NULL;
    // on reçoit d'abord la taille de la chaine
    assert(fd != -1);
    fd = read(fds[0],&size,sizeof(int));
    assert(fd == sizeof(int));
    // on alloue la place nécessaire
    c = malloc( size * sizeof(char));
    // on reçoit en une fois la chaîne
    fd = read(fds[0], c, size*sizeof(char));
    assert(fd == (int) (size*sizeof(char)) );
    printf("Récepteur : lecture de %d caractère(s) : \"%s\"\n", size, c);
    free(c);
    
    close(fds[0]);
    // on applique le protocole suivant :

    
    
    //todo (attention aux fuites mémoire)
    
    // fermeture de l'extrémité restante
    //todo
    
    // pour ne pas retourner dans le main
    exit(EXIT_FAILURE);
}

void envoyeur(int fds[2], const char * s)
{
    printf("    Je suis l'envoyeur %d\n", getpid());
    
    // fermeture de l'extrémité inutile
    //todo
    close(fds[0] );
    // protocole : cf. fonction précédente
    int size = strlen(s)+1;
    int fd ;
    
    fd = write(fds[1],&size,sizeof(int));
    assert( fd == sizeof(int));
    fd = write(fds[1],s,sizeof(char)*size);
    assert(fd == (int) (size*sizeof(char)) );
    //todo
    
    // fermeture de l'extrémité restante
    //todo
    close(fds[1]);
    // pour ne pas retourner dans le main
    exit(EXIT_FAILURE);
}


int main()
{
    // on déclare la chaîne en dur pour se concentrer sur la communication
    const char * const s = "Bonjour monde !";

    // création du tube
    int fds[2];
    assert(pipe(fds) == 0);
    //todo

    // on commence par le récepteur mais c'est arbitraire
    
    // donc fork et dans le fils on appelle recepteur
    int res = fork();
    int res2 =123;
   

   
    
    // puis l'envoyeur
    if(res ==0)
    	recepteur(fds);
    if(res != 0)   
 	res2 = fork();
    if(res2 == 0)
    	envoyeur(fds,s);
    // donc fork et dans le fils on appelle envoyeur
    //todo
        
    // le père n'utilise pas le tube
    //todo
    close(fds[1]);
    close(fds[0]);
    //todo
    printf("Le père se met en attente de la fin des fils\n");
    wait(NULL);
    wait(NULL);
    //todo

    printf("fin processus père %d\n", getpid());
    
    return EXIT_SUCCESS;
}
