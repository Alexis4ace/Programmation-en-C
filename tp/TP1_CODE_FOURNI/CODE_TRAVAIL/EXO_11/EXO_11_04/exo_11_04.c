#include <stdio.h>
#include <stdlib.h>

#define TAILLE1 10

struct Exo
{
    float f;
    float tab1[TAILLE1];
    int taille2;
    float *tab2;
};

// fonction init


struct Exo Init_struct(int n ,float fl,struct Exo player){
    player.f = fl;
    player.taille2 = n;
    player.tab2 = malloc(sizeof(float)*n);
    for(int i ; i<n ; i++){
    	*(player.tab2+i)= 1.0;
    }
    for(int k ; k<10 ; k++){
    	player.tab1[k]= 2.0;
    }
    return player;
    
}
// fonction creer
struct Exo Creer(int n){
    struct Exo *new = malloc(sizeof(struct Exo)*n);
    for(int i; i<n; i++){
    	*(new+i)=Init_struct(i,3.5,*new);
    }
    return *new;
}
// fonction libere


int main()
{
    struct Exo hugo;
    hugo = Creer(3);
    for(int i;i<3;i++){
    	printf("f:%f ,t0 : %f ,t2: %d , T0 : %f \n",hugo.f,*(hugo.tab1),hugo.taille2,*(hugo.tab2));
    }
    // appeler creer et libere
    return EXIT_SUCCESS;
}
