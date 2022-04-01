<img alt="coding" width="300" src="https://upload.wikimedia.org/wikipedia/fr/6/6a/Logo_T%C3%A9l%C3%A9com_Saint_%C3%89tienne.svg">

# Projet OpenCV : Astéroïdes

## Travail demandé:
Le travail demandé concerne la conception et le développement d’un jeu présentant **une scène 3D** dans laquelle on se déplace à partir de mouvements des mains.

<img alt="coding" width="400" src="https://github.com/SABIR-ILYASS/Asteroides/blob/main/sc%C3%A8ne3d.jpg">

## Contributeurs:
* SABIR Ilyass
* SAIF Salma

## Technologies choisies:
-  <a href="https://www.w3schools.com/cpp/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" alt="cplusplus" width="40" height="40"/> </a>

- <a href="https://www.qt.io/" target="_blank" rel="noreferrer"> <img src="https://upload.wikimedia.org/wikipedia/commons/0/0b/Qt_logo_2016.svg" alt="qt" width="40" height="40"/> </a> 

- <a href="https://www.opengl.org/" target="_blank" rel="noreferrer"> <img src="https://upload.wikimedia.org/wikipedia/commons/e/e9/Opengl-logo.svg" alt="openGL" width="40" height="40"/> </a>

- <a href="https://opencv.org/" target="_blank" rel="noreferrer"> <img src="https://www.vectorlogo.zone/logos/opencv/opencv-icon.svg" alt="opencv" width="40" height="40"/> </a>

## Cahier des charges de l’application:
### Description générale:
Le joueur doit piloter un vaisseau spatial en évitant des astéroïdes et rejoindre une station orbitale estampillée par le logo de TSE. Les déplacements sont en 3D et sont contrôlés par des mouvements des mains captés par la WebCam du PC. Les astéroïdes sont représentés par des sphères texturées fixes dans le repère de la scène. La station orbitale dont la position est fixe, est constituée d’un assemblage de formes géométriques (parallélépipèdes, cylindres et sphères) et comporte le logo de TSE. Le vaisseau spatial, représenté aussi à partir formes géométriques, est vu de l’arrière et peut se déplacer en 3D suivant 3 types de mouvements : rotation dans le plan horizontal, rotation dans le plan vertical et translation suivant la direction du vaisseau.

Les contraintes du jeu sont :
* La scène devra comporter un nombre fixe d’astéroïdes (typiquement 16) dont la position sera tirée aléatoirement dans le volume occupé par la scène en veillant à ce qu’il n’y ait pas de superposition entre eux. La taille des astéroïdes sera aussi tirée aléatoirement dans une gamme de diamètres fixée. On pourra changer le nombre d’astéroïdes avant le début de la partie dans une option du jeu (pour fixer un niveau de difficulté). Les astéroïdes seront munis d’une texture réaliste.
*  Le vaisseau sera constitué de formes géométriques pleines. Sa conception devra être suffisamment esthétique pour ressembler à un vaisseau spatial. La caméra sera attachée à ce vaisseau mais disposée un peu derrière lui pour qu’il soit visible. Un éclairage directionnel sera placé pour donner un rendu réaliste à la scène.
* Une station orbitale sera placée aléatoirement dans la scène. Elle sera constituée de formes géométriques pleines conférant aussi une esthétique adaptée. Elle devra comporter sur l’un de ses éléments, une texture avec le logo de Télécom Saint Etienne. Elle sera munie d’une lampe clignotante et tournera lentement sur elle même.
* Le déplacement du joueur sera commandé par des gestes des deux mains grâce à la WebCam. Une partie de l’interface utilisateur devra montrer l’image captée par la WebCam ainsi que des lignes ou des rectangles lui permettant de mieux contrôler ses mouvements. Les collisions avec les astéroïdes devront être détectées et devront arrêter la partie (partie perdue).
* Un chronomètre sera affiché pendant le déroulement de la partie et le temps mis par le joueur sera indiqué à la fin.

### Fonctionnalités à implémenter:
Les fonctionnalités suivantes doivent être obligatoirement implémentées dans le projet (en accord avec la description générale précédente) :
1. Affichage d’une scène 3D comportant un nombre fixe d’astéroïdes dont la position et la taille est tirée aléatoirement et munis d’une texture. Présence d’une option pour changer le nombre d’astéroïdes.
2. Modélisation du vaisseau et présence d’une éclairage directionnel pour donner un rendu réaliste à la scène.
3. Déplacements du vaisseau commandés par les mouvements des mains : rotations suivant 2 axes et translation du vaisseau dans la scène en même temps que la caméra.
4. Présence d’une zone affichant l’image de la WebCam en continu ainsi que des lignes ou des rectangles lui permettant de mieux contrôler ses mouvements.
5. Présence d’une station orbitale en rotation sur elle-même et munie d’une lampe clignotante et d’un logo de TSE.
6. Détection des collisions avec les astéroïdes (partie perdue) et de l’arrimage à la station orbitale (partie gagnée).
7. Détection de la fin de la partie et ré-initialisation pour la partie suivante.

Les fonctionnalités suivantes constitueront **un bonus sur la notation du projet**:
* la collision avec un astéroïde n’arrête pas la partie, mais provoque la désintégration de l’astéroïde et génère une pénalité ou un bonus suivant le type d’astéroïde.
