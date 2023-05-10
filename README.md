# Grafika

## Beadandó feladat:

### Egy egyszerű játék, amelynek célja adott számú gyémánt összegyűjtése.

#### Technikai tudnivalók:

- Betöltés után megjelenik egy 'Help' képernyő, amely rövid leírást ad a játékról és az irányításról, ezt az F1 billentyű lenyomásával lehet bezárni ( és később megnyitni is )
- A játék belsőnézetes, a játékos az egér és a billentyűk segítségével tud mozogni
- A pálya egy erdei tisztás, amit köd **_(Köd)_** borít
- A játék elején kiválasztható a játék nehézsége, minél nagyobb a nehézségi szint, annál nagyobb a köd **_(Felhasználói felület)_**
- A fények a + és - billentyűkkel szabályozhatóak

#### Játékmenet:

- A pályán random koordinátákon megjelenik egy Gyémánt objektum, amely forgó és emelkedő-süllyedő mozgást végez (animált)
- Ha neki megy egy gyémántnak a játékos **_(Ütközésvizsgálat)_** fel tudja venni és a pontszám eggyel nő, majd egy random helyen megjelenik egy újabb gyémánt (ameddig nem nyert)
- A képernyő jobb felső sarkában látható az aktuális pontszám
- Adott számú gyémánt összegyűjtése után a játék véget ér, a játékos nyert, ezt egy felugró képernyő jelzi
