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
        /*
         * To change this license header, choose License Headers in Project Properties.
         * To change this template file, choose Tools | Templates
         * and open the template in the editor.
         */
        /* echo $_GET['login'];
          echo "MDP:  ";
          echo $_GET['motDePasse'];
         * 
         */

        /*         * **************** POST ***************** */
        echo "<h1>Page traitement formulaire</h1>";
        echo "<br/>";

        $nom = $_POST["nom"];
        $prenom = $_POST["prenom"];
        $ddn = $_POST["ddn"];
        
        /*         * **************** GET ***************** 
        echo "<h1>Page traitement formulaire</h1>";
        echo "<br/>";

        $nom = $_GET["nom"];
        $prenom = $_GET["prenom"];
        $ddn = $_GET["ddn"];
        */
        
        /*         * **************** Avec Cookies ***************** */
          
        setcookie("monNom",$nom,0,"/");
        setcookie("monPrenom",$prenom,0,"/");
        
        afficherLogin($nom,$prenom,$ddn);
        afficherCookie();
        

        /*         * **************** Avec Formulaire ***************** */
        require_once './fonctions.inc.php';
        afficherFormulaire($nom, $prenom, $date);
        
        ?>
    </body>
</html>
