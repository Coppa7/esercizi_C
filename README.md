# esercizi_C
Raccolta di esercizi di programmazione in C preparatori per l'esame di Fondamenti di Informatica; si basano soprattutto sulla gestione di stringhe, liste, memoria dinamica, file ecc. *Gli esercizi sono svolti basandosi non tanto sull'efficienza, ma quanto più sulla velocità di risoluzione; alcune soluzioni potrebbero essere quindi inefficienti ma valide, per motivi didattici;

Shrink.c : Partendo da una generica stringa, alloca una nuova stringa che contiene una sola volta tutti i caratteri della prima in ordine.

shrink_lista.c : non del tutto simile a shrink.c; qui la funzione shrink alloca una nuova stringa basandosi su una mask (una stringa di 0 e 1), cioè considerando solo i caratteri corrispondenti agli 1. Dopodichè, data una lista di stringhe, ognuna viene sostituita con la propria versione "ridotta", tranne se quest'ultima inizia con la 'Z': in tal caso viene eliminato il nodo corrispondente.

amplifica_stringa.c : Anche qui viene data una stringa e una maschera (in questo caso però mask è un vettore di interi). Funziona in modo simile ma la maschera può presentare anche numeri positivi diversi da 0 e 1: viene allocata una nuova stringa che presenta il numero di caratteri della stringa iniziale tante volte quanto è il numero corrispondente di mask.

shrink_sottosequenze.c : Data una stringa (contenuta nel file di input) costituita da soli caratteri minuscoli (a-z) e da parentesi tonde (che si presuppongono non annidate e già accoppiate), la funzione shrink scrive su un file di output la stringa ottenuta da input sostituendo a tutte le sottosequenze individuate dalle parentesi con il carattere più frequente della sottosequenza stessa (che può essere uno qualsiasi in caso di parità).

Centra.c : Aggiunge uno 0 al centro di una lista concatenata, creando un nuovo nodo centrale se è pari o sostituendo il valore centrale se è dispari.

Mazzo_sbagliato.c : Dato un file ben formattato il cui nome è fornito da linea di comando, controlla se un mazzo di carte francesi (fornite nel file) è incompleto o contiene duplicati.

CDR.c : Preso un numero intero positivo k (si ipotizza sia già dato quindi senza necessità di controllo), la funzione analizza alloca e restituisce un vettore di classi di resto del numero k in base ai numeri dati dall'utente, e nella quale ogni classe CDR descrive il massimo e il minimo numero appartenente a tale classe oltre che alla loro quantità.

diff_max_lista.c : Data una lista di interi positivi crescenti, trova la differenza fra 2 elementi a e b della lista (differenza intesa come b-a in cui a<b) con la maggiore frequenza. Se 2 differenze hanno stessa frequenza allora la funzione ne ritorna una qualsiasi.

lettera_min.c : Semplice programma che ritorna (con un algoritmo ricorsivo) la più piccola (alfabeticamente minore) lettera di una parola.

minRC.c : Data una matrice di float, trova i primi n valori della matrice tali da essere minimi sia di riga che di colonna, stampando le loro coordinate. La matrice viene letta da file.

mergestr_func.c : funzione (non programma) che concatena ordinatamente due array di stringhe.

gara.c : Dato un file composto da <cognome, nazione>, stampare a schermo il numero di partecipanti da ciascuna nazione.

mat_aristocrescente.c : Una matrice è definita aristocrescente se il massimo della riga i si trova in una colonna precedente rispetto al massimo della riga 
i+1, con i che va dalla prima alla penultima riga. Si possono supporre assenti elementi duplicati nella stessa riga.

zip.c : Data una lista di caratteri, crea una stringa che contiene in ordine i caratteri della lista nella forma <c> oppure <cK> dove K rappresenta il numero di occorrenze consecutive del carattere nella lista.

policode.c : Data una lista di codicipersona e policode, alloca e crea una nuova lista che contiene tutte le persone cui policode non sono compatibili con NESSUN altra persona. Due policode sono compatibili se sono uno l'inverso dell'altro (speculari) o se sono uno il complementare dell'altro (siccome i policode hanno una lunghezza massima di 9 caratteri e contengono solo i caratteri 'D' ed 'S', per essere complementari i due policode devono avere le 'S' e le 'D' invertite)

percorso.c : Una matrice di 0-1 rappresenta una mappa dove lo 0 rappresenta un passaggio libero e 1 rappresenta un ostacolo. Data una lista che rappresenta un percorso da seguire, determinare quante mosse è possibile fare prima di incontrare un ostacolo o uscire dalla mappa, e stampare l'ultima posizione "lecita".
