<link href="../css/style.css" rel="stylesheet" type="text/css"/>
<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

echo"Voici La Liste Des Utilisateurs Avec leurs Date De naissance";
require_once 'functions/fonctionsFrance.inc';
$bdd = connexionBD();
afficherNomDate();