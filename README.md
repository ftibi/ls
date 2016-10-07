# ls

a faire
- Attention : les messages d'erreur devraient sortir sur la sortie erreur standard (stderr)
(ok pour ouverture d'un fichier raté)
- refaire le main de facon plus elegante
- utilisation de strerror et perror pour les autres erreurs ? (meme si elles narrivent pas ?)
- FIX LE TRI PAR LE TEMPS ??!!??!!??!!
( The return value is also stored in tloc, provided that tloc is non-null.)
C'est pour ca que ca bug !
- ls sur un fichier affiche le nom du fichier, il va peut etre falloir refaire une LC ? misere

notes
- ls s'arrete a la premiere option invalide (ok)
- le total est le nombre de blocs
- la deuxiement colonne est le nombre de liens
- mon option z formate la taille du fichier comme om-zsh

bugs connus
- inconsistance du total si on fait ls -l . dir1 mais c coherent avec la commande de omzsh (l . dir1)
- tri par le temps buggé
- boucle infinie si opt -tlr

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
