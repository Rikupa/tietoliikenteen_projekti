# Tietoliikenteen Sovellusprojekti

## Projektin kuvaus

Tietoliikennelabrassa on IoT-reititin (Raspberry Pi), joka on Oamkin kampusverkossa. Opiskelijoiden tehtävänä on koodata Arduinolle client, joka mittaa kiihtyvyysanturin dataa ja välittää tietoa langattomasti IoT-reitittimelle valmiiksi annetun speksin mukaisesti. IoT-reititin on asennettu valmiiksi ja varastoi vastaanotettua dataa MySQL-tietokantaan. Tietokantaan tallentuvaan dataan on TCP-sokettirajapinta ja HTTP API. Kerättyä dataa haetaan rajanpinnasta omaan kannettavaan koodatulla ohjelmalla ja käsitellään koneoppimistarkoitukseen.

## Arkkitehtuurikuva
<picture>
 <img alt="Arkkitehtuurikuva" src="https://github.com/Rikupa/tietoliikenteen_projekti/blob/main/projektidiagrammi.jpg">
</picture>
