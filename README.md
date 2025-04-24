Zadání 2. úkolu

Vytvořte program, který bude pracovat s bankovním účtem. Na účtě se evidují tyto údaje: jméno majitele účtu, číslo účtu, zůstatek a maximální povolený výběr. Je umožněno vybírat z účtu požadovanou částku tak, aby byla splněno podmínka maximálního výběru a nevznikl po výběru na účtě záporný zůstatek. (Účet neužmoní provést takový výběr, který nebude možné realizovat v rámci zůstatku na účtě.) Vklad je neomezený, ale ošetřte případ hackerského útoku, :); . Účet navíc eviduje počet úspěšných vkladů a počet úspěšných výběrů, součet všech vkladů a součet všech výběrů. Účet dále eviduje historii vkladaných nebo vybíraných částek. Maximální počet operací vkladů a výběru je určen při vytvoření objektu účtu.

Nadefinujte třídu 'Ucet' podle zadání. Operace vkladu a výběru neprovádí žádnou vstupní nebo výstupní operaci (čtení dat, zápis dat), částka k výběru/ke vkladu se předává parametrem. Maximální povolný výběr je řešen konstantou třídy a má hodnotu 5 000 Kč. Program vždy po provedení operace zobrazít informaci o úspěšnosti/neúspěšnosti provedení operace. Třída umožní zobrazit či zapat do souboru všechny údaje ve formátu uvedeném níže. Třída umožní načíst údaje jméno majitel účtu, číslo účtu a zůstatek.

Metody třídy implementujte podle potřeby a to s co největším využitím principů OOP.

Funkčnost programu:
Po spuštění program zjistí, zda má zadán jako parametr jméno souboru s aktuálním stavem účtu. Pokud nikoliv, účet naplní uživatelem zadanými údaji na klávesnici - max. počet operací vkladu a výběru; jméno uživatele a číslo účtu. Zůstatek na účtu je v tomto případě 0,- Kč, stejně tak součet příchozích a odchozích plateb. Jinak je číslo účtu, jméno majitele a jeho stav přečten ze souboru, ve kterém mají tvar:

Číslo účtu (celé číslo v rozsahu 100001 až 109999)

Jméno a příjmení majitele (oddělené mezerou)

Zůstatek na účtu (nezáporné číslo s přesností na dvě desetinná místa)

Počet vkladů (nezáporné celé číslo)

Počet výběrů (nezáporné celé číslo)

Součet příchozích plateb (nezáporné číslo s přesností na dvě desetinná místa)

Součet odchozích plateb (nezáporné číslo s přesností na dvě desetinná místa)
Maxium počtu opererací vkladu
Historie vkladů: údaje oddělené středníkem
Historie výběrů: údaje oddělené středníkem

Program bude poté umožňovat následující funkce volbou z menu:

0. Konec programu. Součástí ukončení programu je záznam aktuálního stavu účtu do vnějšího souboru. Pokud bylo jméno souboru zadáno jako parametr, přepíše se novým stavem. Jinak jméno souboru zadá uživatel.

1. Výpis stavu účtu: vypíše se v přehledném formátu všechny údaje účtu.

2. Výpis souhrnných informací o účtu (ve formátu číslo účtu, majitel, zůstatek, počet vkladů a počet výběrů, součet příchozích a odchozích plateb).

3. Uložit částku na vybraný účet. Požadovaná hodnota částky se vloží na účet a zobrazí se informace o úspěchu provedení operace.

4. Vybrat částku z účtu. Výběrem požadované částky nelze jít do minusu a nelze vybrat více než je nastavené maximum pro výběr z účtu. Zobrazí se informace o úspěchu provedení operace.

Pozn.: Pokud zadá uživatel neplatnou volbu menu, bude o této chybě informován. 
