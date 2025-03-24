# Thinking about the Tasks 

## ex00 
### What kind of Error did we Handel 
#### ex00
- [ ] Input file muss enthalten sein
- [ ] Check input *.txt; *.csv oder keine Ende
- [ ] Find beginn and end of the compare file  
- [ ] Check list 
- [ ] Check Nummer bigger 0 less 1000 
- [ ] Check Number bigger Max Int 
- [ ] Check Year not bigger as the actual Date and less date 
- [ ] Check Date Valide (monthe Day year)
- [ ] Checke Output Nummer, is it to big? it is allow to use double ? 


## ex03 
Eingabe validieren:

    Positiv?
    Keine doppelten Werte (optional).

Daten in zwei Containern speichern:

    Einmal in std::vector.
    Einmal in std::deque.

Ford-Johnson-Algorithmus implementieren:

    Zwei Implementationen: eine für jeden Container.

Zeit messen und ausgeben:

    Zeit für std::vector.
    Zeit für std::deque.

Ausgabe formatieren:

    Unsortierte Liste.
    Sortierte Liste.
    Zeitmessung.

Fehlerbehandlung einbauen:

    Ungültige Eingaben korrekt abfangen.


----


// template von Conatiner für Containier 
In der C++-Standardbibliothek sind viele 
Container (z. B. std::vector, std::list) 
so definiert, dass sie zwei Template-Parameter haben

```c++
template <typename T, typename Allocator = std::allocator<T>>
class vector;
```
daher das Template in ex02

```c++ 
template<typename T, template <typename, typename> class Container>
```

