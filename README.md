# Philosophers

Nom du programme
philo
Fichiers de rendu Makefile, *.h, *.c, dans un dossier philo/
Makefile NAME, all, clean, fclean, re
Arguments number_of_philosophers time_to_die time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]
Fonctions externes autorisées
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
Libft autorisée Non
Description Philosophers avec des threads et des mutex
Les règles spécifiques à la partie obligatoire sont :
• Chaque philosophe doit être représenté par un thread.
• Une fourchette est placée entre chaque paire de philosophes. Cela signifie que, s’il
y a plusieurs philosophes, chaque philosophe a une fourchette à sa gauche et une à
sa droite. S’il n’y a qu’un seul philosophe, il n’y aura donc qu’une seule fourchette
sur la table.
• Afin d’empêcher les philosophes de dupliquer les fourchettes, vous devez protéger
leur état en mémoire avec un mutex pour chacune d’entre elle.
