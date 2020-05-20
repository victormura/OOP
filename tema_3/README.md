
# Proiect 3 | Tema 8

**Cerințe comune tuturor temelor:** 
1. Utilizarea sabloanelor 
2. Utilizarea STL 
3. Utilizarea variabilelor, funcțiilor statice, constantelor și a unei functii const 
4. Utilizarea conceptelor de RTTI raportat la template-uri 
5. Tratarea excepțiilor 
6. Citirea informațiilor complete a n obiecte, memorarea și afișarea acestora.

**Cerințe generale aplicate fiecărei teme din acest fișier:** 
* să se identifice și să se implementeze ierarhia de clase; - clasele să conțină constructori, destructori, =, funcție prietena de citire a datelor; 
* clasa de baza sa conțină funcție virtuala de afisare, rescrisa în clasele derivate, iar operatorul de citire să fie implementat ca funcție prieten (în clasele derivate să se facă referire la implementarea acestuia în clasa de baza).

___
Se dorește implementarea unei aplicații care sa permita gestionarea conturilor deschise la banca X. Fiecare cont bancar are obligatoriu un detinator, o data a deschiderii lui și un sold. În cazul conturilor de economii, trebuie retinuta si rata dobânzii (care poate fi pe 3 luni, pe 6 luni sau la un an), precum și un istoric al reactualizarii soldurilor de la deschidere și până în prezent. În cazul în care deținătorul optează pentru un cont curent, el beneficiază de un număr de tranzacții gratuite și altele contra cost (de exemplu orice depunere este gratuită, dar retragerea poate sa coste dacă s-a depășit numărul de tranzacții gratuite, sau e făcută de la bancomatele altor bănci; sau orice cumparatura online are un cost, etc.). Simulati cat mai corect activitatea băncii X.
**Structura de date:** unordered_map sau unordered_set.
___
**Cerința suplimentară:** 
* Să se adauge toate campurile relevante pentru modelarea acestei probleme. 
*  Să se construiască clasa template GestionareConturi care sa conțină informații despre banca X. Clasa conține indexul unui cont (incrementat automat la adaugarea unuia nou prin supraincarcarea operatorului +=) și o structură de date. 
*  Să se construiască o specializare pentru tipul Cont_Economii care sa afișeze toate conturile de economii care au rata dobânzii la 1 an.
