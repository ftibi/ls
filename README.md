# ls

a faire
- Attention : la premiere lettre de la date doit etre en minuscule et non pas majuscule
-  en prio : faire le main plutot que de devoir utiliser test.c
- utilisation de strerror et perror dans un fichier test
- fonction pour trier les t_list
- fonction pour trier les listes en fonction des options daffichage
- afficher la cible des symlinks
- fix le tri par temps !?!?!?!?!

notes
- Le test.c fonctionne avec 3 args pour le mmt
- ls s'arrete a la premiere option invalide
- ft_rights ne renvoie pas le bon type de fichier pour symlink? utiliser lstat au lieu de stat
- ls sur un fichier affiche le fichier
- le total est le nombre de blocs
- la deuxiement colonne est le nombre de liens
- mon option z formate la taille du fichier comme om-zsh

bugs connus
- inconsistance du total si on fait ls -l . dir1

liste des fonctions autorisees
- write
- opendir
- readdir
- closedir
- stat -- info sur un fichier
- lstat -- si symlink renvoie les info du link plutot que celles du fichier link
- getpwuid -- user info
- getgrgid  -- grp info
- listxattr -- attr etendus
- getxattr -- attr etendus
- time
- ctime -- renvoie un chaine de char avec la date etc
- readlink
- malloc
- free
- perror
- strerror
- exit
