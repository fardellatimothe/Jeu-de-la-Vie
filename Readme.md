## Spécifications fonctionnelles

1. L’utilisateur lance le programme et fournit le chemin du fichier contenant l’état initial des cellules en paramètre.

2. Le programme consomme le fichier avec le format précédemment décrit et génère l’ensemble des objets du programme (grille, cellules).

3. A chaque itération les cellules changent d’état selon les règles énoncées plus haut.

4. L’exécution se termine lorsque l’automate n’évolue plus ou après un nombre d’itération fixé arbitrairement.

---

### Deux modes de fonctionnement seront implémentés :

- Le premier, en mode console, fournira les états des n premières itérations de votre jeu de la vie. A chaque itération le programme écrit l’état des cellules dans un fichier selon le format décrit précedemment. Ces résultats sont stockés dans des dossiers nommés <nom_du_fichier_dentree>_out et utilisés pour correction.

- Le second, en mode graphique, affiche la grille et l’état des cellules sur une interface graphique. Pour aboutir, vous disposez d’un exemple de code capable d’afficher une fenêtre graphique et une grille de cellules. Celui-ci devra être adapté en une version orientée objet. La simulation démarre au lancement du programme. La durée entre deux itérations est contrôlable.

### Extensions : 

- Gestion d’une grille torique. Les cellules placées aux extrémités de la grille sont adjacentes 

- Introduction de cellules obstacle. L’état des cellules obstacles n’évolue pas au cours de l’exécution. Ces dernières possèdent un état vivant ou mort. Modifiez votre code, sans altérer le fonctionnement de base.

- Placement de constructions pré-programmées sur la grille. Utiliser les touches du clavier pour intégrer de nouveaux motifs sur la grille lors de l’exécution.
Paralléliser la génération des cellules. Modifiez votre algorithme pour paralléliser le traitement requis pour mettre à jour l’état des cellules sur la grille.