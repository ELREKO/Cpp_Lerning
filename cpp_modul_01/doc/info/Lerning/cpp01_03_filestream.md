<[back](cpp01_02_pointer_vs_reference.md) | [main](/) | [forward](cpp01_00_lerning.md)>

---


# Filestream

## 1. **Einleitung**

`fstream` ist eine Klasse aus der `<fstream>`-Bibliothek und bietet drei Hauptarten von Streams:
- `ifstream` (Input File Stream) zum Lesen von Dateien
- `ofstream` (Output File Stream) zum Schreiben in Dateien
- `fstream` (File Stream) zum sowohl Lesen als auch Schreiben in Dateien


## **Beispiele für `ifstream` (Lesen aus einer Datei)**


```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("example.txt"); // Öffnen der Datei zum Lesen

    if (!inputFile.is_open()) { // Überprüfen, ob die Datei erfolgreich geöffnet wurde
        std::cerr << "Fehler: Die Datei konnte nicht geöffnet werden!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) { // Zeilenweise aus der Datei lesen
        std::cout << line << std::endl;
    }

    inputFile.close(); // Datei schließen
    return 0;
}
```

### **Beispiele für `ofstream` (Schreiben in eine Datei)**

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outputFile("output.txt"); // Öffnen der Datei zum Schreiben

    if (!outputFile.is_open()) { // Überprüfen, ob die Datei erfolgreich geöffnet wurde
        std::cerr << "Fehler: Die Datei konnte nicht geöffnet werden!" << std::endl;
        return 1;
    }

    outputFile << "Hello, World!" << std::endl; // Schreiben in die Datei
    outputFile << "Dies ist eine weitere Zeile." << std::endl;

    outputFile.close(); // Datei schließen
    return 0;
}
```

### **Beispiele für `fstream` (Lesen und Schreiben in eine Datei)**

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::fstream file("example.txt", std::ios::in | std::ios::out | std::ios::app); // Öffnen der Datei zum Lesen und Schreiben

    if (!file.is_open()) { // Überprüfen, ob die Datei erfolgreich geöffnet wurde
        std::cerr << "Fehler: Die Datei konnte nicht geöffnet werden!" << std::endl;
        return 1;
    }

    // Schreiben in die Datei
    file << "Neue Zeile" << std::endl;

    // Zurück zum Anfang der Datei gehen
    file.clear(); // Fehlerstatus zurücksetzen
    file.seekg(0, std::ios::beg);

    // Lesen aus der Datei
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close(); // Datei schließen
    return 0;
}
```

- **Schreibmodi:**
  - `std::ios::app` – Anhängen an das Ende der Datei
  - `std::ios::trunc` – Dateiinhalt löschen, wenn die Datei geöffnet wird
  - `std::ios::ate` – Zur Datei gehen, wenn sie geöffnet wird

- **Lesemodi:**
  - `std::ios::beg` – Vom Beginn der Datei lesen
  - `std::ios::cur` – Vom aktuellen Lese-/Schreibposition lesen
  - `std::ios::end` – Vom Ende der Datei lesen
