# Tietoliikenteen Sovellusprojekti

## Projektin kuvaus

1. Opiskelijoiden tehtävänä on koodata Arduinolle ohjelma, joka mittaa kiihtyvyysanturin dataa ja välittää tietoa 433 MHz radiorajapinnan yli IoT-reitittimelle, valmiiksi annetun kirjaston mukaisesti.
2. IoT-reititin (Raspberry Pi) on asennettu valmiiksi OAMKin tietoliikennelaboratorioon ja se toimii koulun sisäisessä kampusverkossa. Reititin myös varastoi vastaanotettua dataa MySQL-tietokantaan.
3. Pythonilla koodattiin TCP-socket -ohjelma, joka hakee datan tietokannasta HTTP API:n kautta ja välittää sen K-Means algoritmille CSV-tiedostona.
4. K-Means algoritmi luetteloi datan kuuteen eri joukkoon. Näiden pisteiden perusteella Arduinolle tehtiin oma K-Means malli, joka vertaa anturidataa malliin ja kertoo anturin asennon.

## Arkkitehtuurikuva
![image](https://github.com/Rikupa/tietoliikenteen_projekti/blob/main/Kuvat/arkkitehtuuri.png)
|:--:|
<b>Järjestelmän arkkitehtuurikuva; kuvaa sitä, kuinka eri järjestelmät liittyvät toisiinsa.</b>

## Kiihtyvyysanturimittaukset Arduinolla ja lähetys 433 MHz radiolla

Mikrokontrollerina oli Arduino Uno, yhdessä kiihtyvyysanturin(GY-61), radiolähettimen(WS-433) ja -vastaanottimen(RWS-371) kanssa.

![image](https://github.com/Rikupa/tietoliikenteen_projekti/blob/main/Kuvat/arduino_code.png)
|:--:|
<b>Koodi kiihtyvyysanturille, jolla kuusi eri suuntaa mitattiin.</b>

![image](https://github.com/Rikupa/tietoliikenteen_projekti/blob/main/Kuvat/arduino.jpg)
|:--:|
<b>Kuvassa Arduino Uno, johon liitetty kiihtyvyysanturi sekä kytkentäalusta, jossa radiolähetin ja -vastaanotin.</b>

## K-Means

1. Pythonilla koodattiin K-Means -algoritmi, joka laski etäisyydet datapisteistä arvottuihin keskipisteisiin.
2. Saaduista etäisyyksistä laskettiin uudet keskipisteet.
3. Etäisyyksien uudelleenlaskentaa (iterointi) tehtiin niin kauan, että uusien keskipisteiden paikat eivät muuttuneet.

![image](https://github.com/Rikupa/tietoliikenteen_projekti/blob/main/Kuvat/python_KMeans.png)
|:--:|
<b>Kuvassa Arduino Uno, johon liitetty kiihtyvyysanturi sekä kytkentäalusta, jossa radiolähetin ja -vastaanotin.</b>

![image](https://github.com/Rikupa/tietoliikenteen_projekti/blob/main/Kuvat/python_iteration.png)
|:--:|
<b>Kuvassa koodi, jossa toistetaan keskipisteiden laskua, kunnes keskipisteiden paikka ei enää muutu.</b>

![image](https://github.com/Rikupa/tietoliikenteen_projekti/blob/main/Kuvat/6Means_yhdistetty.png)
|:--:|
<b>Kuvassa Arduino Uno, johon liitetty kiihtyvyysanturi sekä kytkentäalusta, jossa radiolähetin ja -vastaanotin.</b>


## Tavoitteet
Tavoitteena oli koodata Arduinolle sovellus, joka mittaa kiihtyvyysanturin dataa ja lähettää sen  yli IoT-reitittimelle (Rasberry pi)
tallennettavaksi MySQL tietokantaan. 


## Metodit
Projektissa oli käytössä ohjelmointikielinä Python ja C++  Versionhallinnassa käytössä oli Git ja sen
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
