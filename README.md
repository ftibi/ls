# ls

a faire
- utilisation de strerror et perror dans un fichier test
- fonction pour trier les t_list
- fonction pour trier les listes en fonction des options daffichage

notes
- Commencer par l'option -R
- ls s'arrete a la premiere option invalide
- ft_rights ne renvoie pas le bon type de fichier pour symlink? utiliser lstat au lieu de stat
- ls sur un fichier affiche le fichier
- le total est le nombre de blocs
- la deuxiement colonne est le nombre de liens
- mon option z formate la taille du fichier comme om-zsh

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
