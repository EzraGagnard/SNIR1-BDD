<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

define("SERVEURBD", "172.18.58.14");
define("LOGIN", "snir");
define("MOTDEPASSE", "snir");
define("NOMDELABASE", "GagnardEval2019");

function connexionBd() {
    try {
        $bdd = new PDO('mysql:host=' . SERVEURBD . ';dbname=' . NOMDELABASE, LOGIN, MOTDEPASSE);
    } catch (Exception $ex) {
        die('<br/>Pb connexion serveur BD : ' . $ex->getMessage());
    }
    return $bdd;
}

// *************************************    Question 10  *******************  Fonctionne
function afficheFilms() {
    
    require_once 'fonctionsVideotheque.inc';
     $bdd = connexionBd();
     
    $requete = $bdd->query("SELECT titre,duree FROM film ORDER BY duree DESC;") 
            or die(print_r($requete->errorInfo()));

    echo "<h4>Liste des films en fonctions de la durée</h4>";
    echo "<table>";
    echo "<tr> <th> Titre </th> <th> Durée </th> </tr>";

    while ($ligne = $requete->fetch()) {
        $titre = $ligne['titre'];
        $duree = $ligne['duree'];
        echo "<tr> <td>" . $titre . "</td>  <td>" . $duree . "</td> </tr>";
    }
    echo "</table>";
    $requete->closeCursor();
}

// *************************************    Question 11  *******************  Fonctionne pas du tout
function listeFilmFromActeur($nomActeur) {
    
require_once 'fonctionsVideotheque.inc';
    $bdd = connexionBD();
    
    $requete = $bdd->prepare('SELECT genreFilm,titre,duree FROM film,genre,acteur WHERE genre.idGenre=film.idGenre and acteur.nomActeur = :nomAct ;');
    
    $requete->bindParam(':nomAct', $nomActeur);

    $requete->execute() 
            or die(print_r($requete->errorInfo()));

    echo "<h4>Affichage des films de l'acteur</h4>";
    echo "<table>";
    echo "<tr> <th> Genre </th> <th> Titre </th> <th> Durée </th> </tr>";

    while ($ligne = $requete->fetch()) {
        $genre = $ligne['genreFilm'];
        $titre = $ligne['titre'];
        $duree = $ligne['duree'];
        echo "<tr> <td>" . $genre . "</td>  <td>" . $titre . "</td> <td>" . $duree . "</td> </tr>";
    }
    echo "</table>";
    $requete->closeCursor();
}


// *************************************    Question 12 afficheNomFilmsDuree
function afficheNomFilmsDuree($genreFilm) {
    $bdd = connexionBd();
    $requete = $bdd->query("SELECT Distinct titre,duree,nomActeur,prenomActeur FROM genre,film,acteur ;");
    $requete->execute() or die(print_r($requete->errorInfo()));
    echo "<table>";
    echo "<tr> <th> Titre </th> <th> Durée </th> <th> Acteur </th> </tr>";

    while ($ligne = $requete->fetch()) {
        $titre = $ligne['titre'];
        $duree = $ligne['duree'];
        $nomActeur = $ligne['nomActeur'];
        $prenomActeur =$ligne['prenomActeur'];
         $chaine = $prenomActeur." ".$nomActeur;
        echo "<tr> <td>" . $titre . "</td> <td>" . $duree . "</td> <td>" . $chaine . "</td> </tr>";
    }
    echo "</table>";
    $requete->closeCursor();
   return $genreFilm;
}
    
    
// *************************************    Question 12/13 getListGenre()
function getListGenre() {
   $template = '<option value="%value%">%value%</option>';

    $bdd = connexionBd();
    $requete = $bdd->prepare("SELECT nomActeur FROM acteur ;");


    $requete->execute()
            or die(print_r($requete->errorInfo()));

    while ($data = $requete->fetch()) {
        $nomActeur = $data['nomActeur'];
        $listeActeur = str_replace('%value%', $nomActeur, $template);

        echo $listeActeur;
    }

    $requete->closeCursor();
}

// *************************************    Question 13 getListActeur()
