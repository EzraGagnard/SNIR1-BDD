<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */




require_once 'functions/fonctionsFrance.inc';
$bdd = connexionBD();
$codePostal= $_POST["codePostal"];


$nomVille = afficherVillesFromCp($codePostal);
echo "<div>";
echo "la (ou les) ville avec le code postal: <b>$codePostal</b> ont pour nom: <br/>";
echo "<b>$nomVille</b>";
echo "</div>";