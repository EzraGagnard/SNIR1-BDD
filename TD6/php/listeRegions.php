<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function getListRegion() {
    require_once 'functions/fonctionsFrance.inc';
    $bdd = connexionBD();
    $requete = $bdd->prepare("SELECT region_nom from regions; ");
    $requete->execute() or die(print_r($requete->errorInfo()));

    while ($ligne = $requete->fetch()) {
        echo "<option value=" . $ligne['region_id'] . ">" . $ligne['region_nom'] . "</option>";
    }
    $requete->closeCursor();
}

function getListRegion_CorrecProf() {
    require_once 'functions/fonctionsFrance.inc';


    $template = '<option value="%value%">%value%</option>';
    $bdd = connexionBD();
    $requete = $bdd->prepare("SELECT region_nom FROM regions ORDER BY region_nom;");
    $requete->execute() or die(print_r($requete->errorInfo()));

    while ($data = $requete->fetch()) {
        $nomRegion = str_replace('%value%', $data['region_nom'], $template);
        echo $nomRegion;
    }
    $requete->closeCursor();
}

function AfficheDeptfromRegion($idRegion) {
    require_once 'functions/fonctionsFrance.inc';
    $bdd = connexionBD();
   // echo $idRegion;
    $requete = $bdd->prepare("SELECT departement_nom, departement_code, departement_region_id from regions,departements "
            . "where departements.departement_region_id = regions.regions_id "
            . "and departements.departement_region_id like :region_id ;");
    $requete->bindParam(":region_id", $idRegion);

    $requete->execute() or die(print_r($requete->errorInfo()));



    echo"<table id='table'><tr>"
    . "<th class='titre'>Numéro Département</th> <th class='titre'>Nom Département</th></tr>";

    while ($ligne = $requete->fetch()) {
        echo"<tr><td>" . $ligne['departement_code'] . "</td>"
        . "<td>" . $ligne['departement_nom'] . "</td>";
    }
    echo "</tr></table>";
    $requete->closeCursor();
}