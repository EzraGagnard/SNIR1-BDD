<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <?php
        require_once 'fonctions.inc.php';
        AfficherDonneesV3($_POST);
        
        echo"<h3>Verification mot de passe version 1 </h3>";
        VerifDoubleMdpV2($_POST['mdp'], $_POST['confirmMDP']);
        if($reponseVerif)
        {
            echo"OK Version 2";
        }
        echo"KO Version 2";
        ?>
    </body>
</html>
