

/* 
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

<html>
    <head>
        <title>TODO supply a title</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <script src="js/libs/jquery/jquery.js" type="text/javascript"></script>
        <script src="formddn.js" type="text/javascript"></script>
    </head>
    <body>
        <?php
        if (isset($_COOKIE['monNom']) && isset($_COOKIE['monPrenom'])) {
            echo "<h3>Afficher les éléments du formulaire</h3>";
            echo "nom:" . $_COOKIE['monNom']."<br/>Prenom:" . $_COOKIE['monPrenom'];
        } else {
            echo '<div>
        <form id = "formulaireNaissance" action = "php/traitement.php" method = "post">
        <label for = "nom" > Nom</label>
        <input type = "text" name = "nom" id = "nom" /><br/>
        <label for = "nom" > Prénom</label>
        <input type = "text" name = "prenom" id = "prenom" /><br/>
        <label for = "nom" > Date de naissance (JJ/MM/AAAA)</label>
        <input type = "text" name = "ddn" id = "ddn" required = "required"/><br/>
        <input type = "submit" />
        </form>
        </div>';  
        }
        
        ?>
    </body>
</html>