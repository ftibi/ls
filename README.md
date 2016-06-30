# ls

a faire
- refaire ft_error de printf dans libft (ou ls_error)
- fonction qui lit un repertoire et mets tous les fichiers + info dans
	une liste chainee
- fonction d'aff de cette liste chainee. 1er parcours de la liste + affichage du
	contenu. Puis si -R parcours a nouveau en s'appelant recursivement sur les
	elements qui ont pour type repertoire (pas sur les symlinks).
- utilisation de strerror et perror dans un fichier test
- fonction qui prend un t_list et un file uid, et qui remplit le t_list

notes
- ls s'arrete a la premiere option invalide
- ft_rights ne renvoie pas le bon type de fichier pour symlink? utiliser lstat au lieu de stat
- ls sur un fichier affiche le fichier

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
