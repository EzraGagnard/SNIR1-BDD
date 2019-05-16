<?php

/*
 * To change this license header, choose License Haeders in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


define("SERVEURBD", "172.18.58.14");
define("LOGIN", "snir");
define("MOTDEPASSE", "snir");
define("NOMDELABASE", "france2015plus");

function connexionBD() {
    try {
        $bdd = new PDO('mysql:host=' . SERVEURBD . ';dbname=' . NOMDELABASE, LOGIN, MOTDEPASSE);
        //  $bdd = new PDO('mysql:host=172.18.58.14; dbname=france2015plus;',"snir","snir");
    } catch (Exception $ex) {
        die('<br/>Pb connexion serveur BD: ' . $ex->getMessage());
    }
    return $bdd;
}
//Question 1
function afficherPersonne() {
    require_once 'functions/fonctionsFrance.inc';
    $bdd = connexionBD();

    $requete = $bdd->prepare("SELECT nom,prenom,dateNaissance,ville_nom,ville_code_postal,departement_nom,region_nom from utilisateurs,villes,regions,departements "
            . "where departements.departement_region_id = regions.regions_id and utilisateurs.ville_id = villes.ville_id and departements.departement_id = villes.ville_departement_id;");


    $requete->execute() or die(print_r($requete->errorInfo()));

    echo"<table id='table'><tr>"
    . "<th class='titre'>Nom</th> <th class='titre'>Prénom</th><th class='titre'>Date de naissance</th>"
    . "<th class='titre'>Ville</th> <th class='titre'>Code postal</th><th class='titre'>Nom du département</th>"
    . "<th class='titre'>Nom de la région</th></tr>";

    while ($ligne = $requete->fetch()) {
        echo"<tr>"
        . "<td>" . $ligne['nom'] . "</td>"
        . "<td>" . $ligne['prenom'] . "</td>"
        . "<td>" . $ligne['dateNaissance'] . "</td>"
        . "<td>" . $ligne['ville_nom'] . "</td>"
        . "<td>" . $ligne['ville_code_postal'] . "</td>"
        . "<td>" . $ligne['departement_nom'] . "</td>"
        . "<td>" . $ligne['region_nom'] . "</td>";
    }
    echo "</tr></table>";
    $requete->closeCursor();
}
//Question 2
function afficherVillesFromCp($codePostal) {
    $bdd = connexionBD();

    $requete = $bdd->prepare("select ville_nom from villes,departements where "
            . "departements.departement_id=villes.ville_departement_id and ville_code_postal like :codePostal;");
    $requete->bindParam(":codePostal", $codePostal);

    $requete->execute() or die(print_r($requete->errorInfo()));

    $nbLigne = $requete->rowCount();

    // si pas de correspondance
    if ($nbLigne == 0) {
        $nomVille = "pas de villes correspondant";
    }
    // si une seule correspondance
    if ($nbLigne == 1) {
        $nomVille = $requete->fetchColumn(0);
    }
    // si plus d'une seule correspondance
    if ($nbLigne > 1) {
        $nomVille = "";
        while ($ligne = $requete->fetch()) {
            $nomVille = $nomVille . "<br/>" . $ligne['ville_nom'];
        }
    }
    // liberation des ressources de la requete
    $requete->closeCursor();
    return $nomVille;
}
//Question 3
function afficherCompteVillesFromCp($codePostal) {
    $bdd = connexionBD();

   // $requete = $bdd->prepare("select COUNT(ville_nom) as nbVilles from villes,departements where "
   //         . "departements.departement_id=villes.ville_departement_id and ville_code_postal like :codePostal;");
    $requete = $bdd->prepare("SELECT COUNT(ville_nom) as nbVilles "
            . "FROM villes WHERE villes.ville_code_postal LIKE :codePostal");
           
    $requete->bindParam(":codePostal", $codePostal);

    $requete->execute() or die(print_r($requete->errorInfo()));

  while ($ligne = $requete->fetch()){
      $nbVilles = $ligne['nbVilles'];
  }
  echo"Il y a <b>$nbVilles</b> villes correspondantes à ce code postal";  
 
  $requete->closeCursor();

}
//Question 4
function afficherPopulationParDepartement($dept){
    $bdd = connexionBD();
    
    $requete = $bdd->prepare("SELECT COUNT(ville_nom) as nbVilles "
            ."FROM villes WHERE villes.ville_departement LIKE :dept "
            ."GROUP BY ville_departement_id");
    $requete->bindParam(":dept", $dept);
    
    $requete->execute() or die(print_r($requete->errorInfo()));
    
    while ($ligne = $requete->fetch()) {
        $nbVilles = $ligne['nbVilles'];
    }
    echo "Il y a <b>$nbVilles</b> villes dans le département <b>$dept</b>"; 
     
}
    
   
//Question N°5
function afficherNomDate() {

    $bdd = connexionBD();

    $requete = $bdd->prepare("SELECT nom, dateNaissance FROM utilisateurs;");

    $requete->execute() or die(print_r($requete->errorInfo()));

    echo"<table>";
    echo"<tr><th>Nom</th> <th>Date de naissance</th></tr>";
    while ($ligne = $requete->fetch()) {
        $nom = $ligne['nom'];
        $dateNaissance = convertirDateNaissance($ligne['dateNaissance']);

        echo"<tr><td>$nom</td> <td>$dateNaissance</td></tr>";
    }
    echo "</table>";

    $requete->closeCursor();
}

function convertirDateNaissance($date) {

    $bdd = connexionBD();

    $requete = $bdd->query("SET lc_time_names = 'fr_FR';");

    $requete = $bdd->prepare("SELECT dayname(:date) AS jour, day(:date) AS numJour, "
            . "MONTHNAME(:date) AS mois, year(:date) AS annee "
            . "FROM utilisateurs;");

    $requete->bindParam(":date", $date);

    $requete->execute() or die(print_r($requete->errorInfo()));

    while ($ligne = $requete->fetch()) {
        $jour = $ligne['jour'];
        $numJour = $ligne['numJour'];
        $mois = $ligne['mois'];
        $annee = $ligne['annee'];
    }
    $date = $jour . " " . $numJour . " " . $mois . " " . $annee;

    $requete->closeCursor();

    return $date;
}

//Question 6
function getListPersonne() {
    $bdd = connexionBD();
    $requete = $bdd->prepare("SELECT utilisateur_id,nom,prenom,dateNaissance from utilisateurs; ");
    $requete->execute() or die(print_r($requete->errorInfo()));

    while ($ligne = $requete->fetch()) {
        echo "<option value=" . $ligne['utilisateur_id'] . " >" . $ligne['nom'] . $ligne['prenom']. $ligne['dateNaissance']."</option>";
    }
    $requete->closeCursor();
}
//pas sure

function afficherCompteVillesFromCp_SANSCOUNT($codePostal) {
    $bdd = connexionBD();

    $requete = $bdd->prepare("select ville_nom from villes,departements where "
            . "departements.departement_id=villes.ville_departement_id and ville_code_postal like :codePostal;");
    $requete->bindParam(":codePostal", $codePostal);

    $requete->execute() or die(print_r($requete->errorInfo()));

    $nbLigne = $requete->rowCount();

    $requete->closeCursor();
    return $nbLigne;
}

