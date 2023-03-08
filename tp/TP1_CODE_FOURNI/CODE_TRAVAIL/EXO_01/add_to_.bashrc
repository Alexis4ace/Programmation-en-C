# Voici le code que vous pouvez ajouter à la fin du fichier $HOME/.bashrc
#    option -g pour les informations de debugage
alias mygcc='gcc -g -Wall -Wextra -pedantic -std=c99'

# utilisation pour compiler le fichier toto.c :
# $ mygcc toto.c -o toto

# lorsqu'on modifie le .bashrc il faut faire une des trois actions suivantes :
# - relancer un nouveau terminal
# - $ source ~/.bashrc
# - $ . ~/.bashrc






# Rien à voir avec le module mais quelques autres alias
# qui peuvent être utiles
# RTFM pour le rôle des options

alias cp='cp -i'
alias mv='mv -i'

alias ls='ls --time-style=long-iso -CF --color'
alias l='ls -l'
function ll ()
{
    pwd
    ls -laG "$@" | more
}






# et un peu plus ésotérique

# pour un dump d'une fichier
alias myod='od -Ad -w10 -t u1z'
#alias myod='od -Ad -w10 -t x1z'
# note : "hexdump -C" donne un résultat similaire

# pour un log condensé de git
alias gitlog="git log --oneline --decorate --branches --graph"






# et pour les curieux : empiler les répertoires visités par cd

# la commande "cd" va dabs le répertoire visé et l'ajoute à la pile
function cd ()
{
    pushd "$*" > /dev/null
    echo `pwd`
}

" la command "bd" (pour back directory) revient au dernier répertoire empilé
alias bd='popd > /dev/null; echo `pwd`'
