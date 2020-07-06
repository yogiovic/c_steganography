# c_steganography

viz. https://sk.wikipedia.org/wiki/Steganografia

Vypracovaný projekt do predmetu Jazyk C 2020

Napište testovací program "steg-decode.c", kde ve funkci main načtete ze
souboru zadaného jako jediný argument programu obrázek ve formátu PPM
a v něm najdete uloženou "tajnou" zprávu. Zprávu vytisknete na stdout.
Zpráva je řetězec znaků (char, včetně '\0') uložený po jednotlivých bitech
(počínaje LSb) na nejnižších bitech (LSb) vybraných bajtů barevných složek
v datech obrázku. Dekódování ukončete po dosažení '\0'.
Pro DU1 budou vybrané bajty určeny prvočísly (počínaje od 23) -- použijte
Eratostenovo síto podobně jako v příkladu "primes.c" a začněte prvočíslem 23.
Velikost bitového pole musí odpovídat velikosti obrazových dat.

Hodnotenie: 15/15
