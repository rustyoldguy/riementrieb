#VERSION := 0.1
CC = cc
LD = g++
CFLAGS   :=  -g -O0 -Wall -c
SOURCE := main.cpp menuefrage.cpp riemen.cpp winkelfunktionen.cpp
OBJ := main.o menuefrage.o riemen.o winkelfunktionen.o
DEST := riementrieb

$(DEST): $(OBJ)
	$(LD) -o $(DEST) $(OBJ)
#Mit Wildcards können wir Befehle auf eine Gruppe von Dateien anwenden. 
#Hier sollen nun alle .c-Dateien  zu .o-Dateien kompiliert werden. 
#Diese werden mit dem %-Operator gesucht. Der gefundene Dateiname kann mit $< verwendet werden.
%.o: %.c

	$(CC) -c $<

#Befehl    Bedeutung
# -c       Compile and assemble, but do not link.

main.o: $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE)
