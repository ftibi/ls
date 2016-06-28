# ls

a faire
- refaire ft_error de printf dans libft
- fonction qui lit un repertoire et mets tous les fichiers + info dans
	une liste chainee
- fonction d'aff de cette liste chainee. 1er parcours de la liste + affichage du
	contenu. Puis si -R parcours a nouveau en s'appelant recursivement sur les
	elements qui ont pour type repertoire (pas sur les symlinks).

notes
- ls s'arrete a la premiere option invalide
- ft_rights ne renvoie pas le bon type de fichier pour symlink? utiliser lstat au lieu de stat
- ls sur un fichier affiche le fichier

liste des fonctions autorisees
- write
- opendir
- readdir
- closedir
- stat
- lstat
- getpwuid
- getgrgid
- listxattr
- getxattr
- time
- ctime
- readlink
- malloc
- free
- perror
- strerror
- exit
