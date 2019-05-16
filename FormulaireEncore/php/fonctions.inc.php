<?php

       function AfficherDonnees($_tab)
      {
        echo "Nom: ". $_tab['nom'] . "<br/>";
        echo "Prénom: ". $_tab['prenom'] . "<br/>";
        echo "Ville: ". $_tab['ville'] . "<br/>";
        echo "Email: ". $_tab['courriel'] . "<br/>";
        echo "Site: ". $_tab['Site'] . "<br/>";
        echo "Sexe: ". $_tab['Sexe'] . "<br/>";
        echo "Fichier Photo: ". $_tab['photo'] . "<br/>";
        echo "Système d'exploitation: ". $_tab['SE'] . "<br/>";
        echo "Version: ". $_tab['version'] . "<br/>";
        echo "JAVA: ". $_tab['coche1'] . "<br/>";
        echo "C: ". $_tab['coche2'] . "<br/>";
        echo "PHP: ". $_tab['coche3'] . "<br/>";
        echo "Autre: ". $_tab['coche4'] . "<br/>";
        echo "login: ". $_tab['Login'] . "<br/>";
        echo "Mot de passe: ". $_tab['mdp'] . "<br/>";
        echo "Mot de passe Confirmé: ". $_tab['confmdp'] . "<br/>";
      }
      
        function AfficherDonneesV2($tab)
        {
            foreach ($tab as $champ => $valeur)
            {
                echo "$champ : $valeur <br/>";
            }
        }

        function AfficherDonneesV3($tab)
        {
            echo "<pre>";
            print_r($tab);
            echo"</pre>";
        }
        
        function VerifDoubleMdp($mdp1, $mdp2)
        {
            if($mdp1 == $mdp2)
            {
                echo"OK";
            }
            else
            {
                echo"KO";
            }
        }
        
        function VerifDoubleMdpV2($mdp1, $mdp2)
        {
            $verifMdp = false;
            
            if($mdp1 == $mdp2)
            {
                $verifMdp = true;
            }
            
        }
?>
  