# Tietoliikenteen Sovellusprojekti

## Projektin kuvaus

Tietoliikennelabrassa on IoT-reititin (Raspberry Pi), joka on Oamkin kampusverkossa. Opiskelijoiden tehtävänä on koodata Arduinolle client, joka mittaa kiihtyvyysanturin dataa ja välittää tietoa langattomasti IoT-reitittimelle valmiiksi annetun speksin mukaisesti. IoT-reititin on asennettu valmiiksi ja varastoi vastaanotettua dataa MySQL-tietokantaan. Tietokantaan tallentuvaan dataan on TCP-sokettirajapinta ja HTTP API. Kerättyä dataa haetaan rajanpinnasta omaan kannettavaan koodatulla ohjelmalla ja käsitellään koneoppimistarkoitukseen.

## Arkkitehtuurikuva
![image](https://github.com/Rikupa/tietoliikenteen_projekti/blob/main/Kuvat/arkkitehtuuri.png)"

## 3D-kuvat luokittelusta ennen ja jälkeen
![image](https://github.com/Rikupa/tietoliikenteen_projekti/blob/main/Kuvat/6Means_ennen2.png)"
![image](https://github.com/Rikupa/tietoliikenteen_projekti/blob/main/Kuvat/6Means_jalkeen2.png)"

## Tavoitteet
Tavoitteena oli koodata Arduinolle sovellus, joka mittaa kiihtyvyysanturin dataa ja lähettää sen 433Mhz radiorajapinnan yli IoT-reitittimelle (Rasberry pi)
tallennettavaksi MySQL tietokantaan. Tämän jälkeen Pythonilla koodattiin ohjelma, joka hakee datan tietokannasta HTTP API:n kautta ja välittää sen K-Means algoritmille. 
K-Means algoritmi tämän jälkeen luetteloi datan kuuteen eri joukkoon. Näiden pisteiden perusteella Arduinolle tehtiin oma K-Means malli, joka vertaa anturidataa malliin 
ja kertoo anturin asennon.

## Metodit
Projektissa oli käytössä ohjelmointikielinä Python ja C++ Mikrokontrollerina käytössä oli Arduino Uno 
yhdessä kiihtyvyysanturi(GY61), radiolähetin(WS-433) ja vastaanottimen(RWS-371) kanssa. Versionhallinnassa käytössä oli Git ja sen
jatkeena GitHub edistymisen tarkkailuun ja tehtyjen töiden tallentamiseen.

## Lopputulos
Mitatun datan siirto onnistuu radiorajapinnan yli tietokannalle. Tästä
datasta K-means algoritmilla tehty malli
implementoitiin Arduinoon, 
joka osasi onnistuneesti luokitella
anturidatan perusteella asennot oikein.

## Johtopäätökset
Projekti oli haastava, mutta 
opettavainen, koska K-Means –
algoritmi tehtiin itse alusta alkaen. 
Ennen projektia opiskeltu 
teoreettinen osaaminen vahvistui 
projektin aikana 
käytännön osaamisella ja ymmärrys 
koneoppimisesta syventyi.
