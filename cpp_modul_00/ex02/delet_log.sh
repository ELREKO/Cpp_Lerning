#!/bin/bash

# Überprüfen, ob die Anzahl der Argumente korrekt ist
if [ $# -ne 1 ]; then
    echo "Usage: $0 <logfile>"
    exit 1
fi

# Eingabedatei und Ausgabedatei definieren
input_file=$1
output_file="${input_file%.log}_without_timestamp.log"

# Timestamp entfernen und Ausgabe in neue Datei schreiben
sed 's/^\[[0-9_]\+\] //' "$input_file" > "$output_file"

echo "Timestamps wurden aus $input_file entfernt und in $output_file gespeichert."
