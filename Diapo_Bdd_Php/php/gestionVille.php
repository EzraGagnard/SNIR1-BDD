<link href="../css/style.css" rel="stylesheet" type="text/css"/>
<?php

/* 
 * To change this license header, choose License Haeders in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



require_once 'functions/fonctionsFrance.inc';
$nomVille= $_POST["ville"];


$nomDepartement = getNomDepartementFromVille($nomVille);
echo "<div>";
echo "ville de <b>$nomVille</b> se trouve dans le departement: <br/>";
echo "<b>$nomDepartement</b>";
echo "</div>";