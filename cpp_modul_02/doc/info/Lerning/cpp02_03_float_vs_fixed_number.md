<[back](cpp02_02_orthodox_canonical.md) | [main](/) | [forward](cpp02_00_lerning.md) >

--- 


# Gleitkommazahlen (Floating Point Numbers)

[1](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html)  
**Genauigkeit vs. Präzision**
- **Ganzzahlige (Integer) Zahlen** sind *sehr genau*, aber nicht immer präzise genug, wenn es um feinere Abstufungen geht. Sie können nur ganze Werte ohne Nachkommastellen darstellen.
- **Gleitkommazahlen (Floating Point)** hingegen bieten eine *hohe Präzision* durch die Fähigkeit, Dezimalwerte zu speichern. Sie sind jedoch *nicht immer genau*, da sie aufgrund der begrenzten Mantissenlänge und des Exponenten oft Rundungsfehler enthalten. Dies führt zu Ungenauigkeiten bei Berechnungen.

[2](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html)  
**Darstellung von Gleitkommazahlen (Float)**
- Gleitkommazahlen werden im Speicher durch die IEEE 754-Norm repräsentiert. Dabei teilt sich eine 32-Bit-Float-Zahl in drei Hauptkomponenten auf:
  
  `seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm`  
  **s = Vorzeichenbit (sign)**  
  **e = Exponent**  
  **m = Mantisse (fraction)**

- **Vorzeichenbit (S)**: Das höchstwertige Bit (Position 31) bestimmt das Vorzeichen. `0` bedeutet positiv, `1` bedeutet negativ.
- **Exponent (E)**: Belegt die Bits von Position 30 bis 23 und speichert den verschobenen Exponenten (mit einem Bias, um negative Exponenten darzustellen).
- **Mantisse (M)**: Die verbleibenden Bits (Positionen 22 bis 0) repräsentieren die signifikanten Stellen der Zahl. Die Mantisse beginnt implizit immer mit `1`.

Beispiel für eine Float-Zahl:
```
1 + 1/2 + 0/4 + 1/8 + 1/16 = 1.6875
```

### Float-Vergleich
Gleitkommazahlen sind aufgrund von Rundungsfehlern *nicht direkt zum Vergleichen* geeignet. Dies liegt an der begrenzten Präzision, mit der Zahlen gespeichert werden. Statt eines direkten Vergleichs mit `==` wird oft ein Vergleich unter Berücksichtigung eines kleinen Toleranzwertes (Epsilon) verwendet:

- Der kleinste Unterschied (Maschinengenauigkeit) bei einem `float` wird durch *Epsilon* dargestellt. Für einen 32-Bit-Float beträgt dieser Wert typischerweise etwa:
  ```
  Epsilon ≈ 1.1920929e-7
  ```
- Dies repräsentiert die minimale Differenz, die zwei benachbarte Float-Zahlen voneinander haben können.

### Überlauf (Overflow)
- Bei **Ganzzahlen (Integer)** führt ein Überlauf oft dazu, dass der Wert auf Null oder einen anderen Wert zurückspringt, ohne dass dies direkt erkennbar ist.
- Bei **Gleitkommazahlen** wird ein Überlauf meistens durch eine Darstellung von positiver oder negativer Unendlichkeit signalisiert (`+∞` oder `-∞`). Dadurch kann der Überlauf leichter erkannt werden.
- Vorsicht ist geboten bei der Konvertierung von `float` zu `int`, da dies zu unerwarteten Ergebnissen führen kann, insbesondere wenn ein Überlauf auftritt.

Eine mögliche Lösung zur Vermeidung von Überlauf ist die Verwendung von **Double**, da dieses Format mehr Bits für den Exponenten und die Mantisse hat und somit größere Werte und eine höhere Präzision erlaubt.

---

# Festkommazahlen (Fixed Point Numbers)

Im Gegensatz zu [Gleitkommazahlen](#Floating-Point-Numbers) sind **Festkommazahlen (Fixed Point Numbers)** eine gute Alternative, um:
- Eine **höhere Leistung** zu erzielen, da nur Ganzzahlen verarbeitet werden.
- Eine **höhere Genauigkeit** im Vergleich zu Gleitkommazahlen zu gewährleisten.
- Die **Vergleichbarkeit** zu verbessern, da keine Rundungsfehler auftreten.

### Berechnung der Festkommazahlen
Festkommazahlen werden durch eine feste Anzahl von Bits für den Ganzzahl- und Nachkommaanteil dargestellt. Dies wird durch das Format `fixed<w,b>` spezifiziert, wobei:
- `w` die gesamte Anzahl der Bits ist (inklusive Vorzeichenbit).
- `b` die Anzahl der Bits für den Nachkommaanteil ist.

**Beispiel:**
- Betrachten wir die Zahl `2,75` im `fixed<8,3>` Format:
  ```
  2,75 (dezimal) = 00010.110 (binär)
  ```
  Dies kann zerlegt werden in:
  ```
  2^1 + 2^(-1) + 2^(-2) = 2,75
  ```

Das Format `fixed<8,3>` bedeutet, dass insgesamt 8 Bits zur Verfügung stehen, wobei 3 Bits für den Nachkommaanteil reserviert sind. Die restlichen 5 Bits (einschließlich eines Vorzeichenbits, falls notwendig) repräsentieren den Ganzzahlanteil.

**Berechnung mit Binärzahlen:**
Die binäre Darstellung einer Festkommazahl kann durch den exakten Wert berechnet werden. Nehmen wir:
```
0x2^4 + 0x2^3 + 0x2^2 + 1x2^1 + 0x2^0 + 1x2^(-1) + 1x2^(-2) + 0x2^(-3)
```
- Ganzzahlteil: `2^1 = 2`
- Bruchteil: `2^(-1) + 2^(-2) = 0,75`

Daher ist der Wert der Zahl: `2 + 0,75 = 2,75`.

### Vor- und Nachteile von Festkommazahlen:
- **Vorteile**: Schnelle Berechnung und konstante Genauigkeit. Sie sind nützlich für eingebettete Systeme oder Umgebungen, in denen Speicher und Rechenleistung begrenzt sind.
- **Nachteile**: Sie können nicht so große Werte oder so feine Unterschiede wie Gleitkommazahlen darstellen, da die Anzahl der Bits begrenzt ist.
