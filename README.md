```markdown
# 🧭 NavigationSystem – Dein Wegweiser in C++

Weil selbst der beste Code manchmal den Weg braucht – hier ist mein objektorientiertes Navigationssystem in C++.  
Ein simples, aber gut strukturiertes Projekt zur Verwaltung von Orten, Adressen und Navigationslogik.  
Denn wer den Code meistert, braucht keinen Kompass mehr 💡

## 🚀 Was macht dieses Projekt?

Dieses Programm simuliert ein einfaches Navigationssystem, das Orte und Adressen verwaltet und den Weg zwischen ihnen plant.  
Es dient als Demonstration für sauberes OOP in C++ mit Fokus auf Erweiterbarkeit und modularem Design.

## 🧠 Features

- Verwaltung von Orten und ihren Adressen  
- Navigationseinheit mit einfacher Steuerung  
- Klar getrennte Verantwortlichkeiten zwischen Daten- und Logikebene  
- Grundlage für komplexere Navigationsalgorithmen

## 🛠️ Projektstruktur

```
NavigationSystem/
├── main.cpp                  # Einstiegspunkt
├── adresse.cpp/.h            # Repräsentiert eine Adresse
├── ort.cpp/.h                # Repräsentiert einen Ort
├── navigationsystem.cpp/.h  # Logik des Navigationssystems
├── CMakeLists.txt            # Build-Konfiguration mit CMake
```

## 🧪 Kompilierung & Ausführung

### Voraussetzungen

- C++ Compiler (`g++`, `clang++`, etc.)  
- [CMake](https://cmake.org/) installiert

### Schritte

```bash
cd NavigationSystem
mkdir build && cd build
cmake ..
make
./NavigationSystem  # oder der generierte Binary-Name
```

## 👨‍🎓 Über mich

Ich bin Informatikstudent mit Begeisterung für C++ und Software, die klar, skalierbar und zukunftssicher ist.  
Dieses Projekt ist ein weiterer Schritt auf dem Weg – und der Weg ist hier das Ziel 🛣️

## 🔮 Erweiterungsideen

- Integration einer Routenberechnung  
- Visualisierung mit grafischer Benutzeroberfläche (GUI)  
- Speicherung und Laden von Daten via JSON  
- Unterstützung für Kartenmaterial und Geokoordinaten

„Ein gutes Navigationssystem kennt den Weg. Ein guter Code zeigt ihn.“
