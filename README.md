# extended-round-based-game
C-based game (player and mediator programs)

This repository includes files I have prepared for the technical assignment from TietoEvry (C Working Student).

The player program relies on fixed format of the status.txt file. The status file is ordered as follows: gold (1 line), bases (2 lines), active units. A sample status file is included. The player1.txt/player2.txt files store the number of rounds remaining until unit training is completed for the respective player, and the number of gold (also for the respective player).

Makefile is included. 
Compilation commands:
Player 1 executable: 
gcc gracz1/player.c gracz1/load_status.c gracz1/load_player_input.c gracz1/map.c gracz1/list.c gracz1/train.c gracz1/move.c gracz1/attack.c gracz1/save.c gracz1/mining.c -lpthread -o player1

Player 2 executable:
gcc gracz2/player.c gracz2/load_status.c gracz2/load_player_input.c gracz2/map.c gracz2/list.c gracz2/train.c gracz2/move.c gracz2/attack.c gracz2/save.c gracz2/mining.c -lpthread -o player2

Arbiter executable:
gcc mediator/mediator.c mediator/load_status.c mediator/load_orders.c -o arbiter

Run command: ./arbiter

The submission has been tested on MacOS Monterey 12.6.6 and Ubuntu 22.04.

----

Repozytorium zawiera pliki przygotowane jako rozwiązanie zadania technicznego w ramach TietoEvry (C Working Student).

Program gracza pracuje w oparciu o stały format pliku status.txt. Plik statusu jest uporządkowany w następujący sposób: złoto (1 linia), stan baz (2 linie), aktywne jednostki. Dołączono przykładowy plik status.txt. Pliki player1.txt/player2.txt przechowują liczbę ruchów pozostałą do ukończenia szkolenia jednostek i liczbę złota dla odpowiedniego gracza.

Dołączono plik makefile. 
Komendy kompilacji:
Player 1: 
gcc gracz1/player.c gracz1/load_status.c gracz1/load_player_input.c gracz1/map.c gracz1/list.c gracz1/train.c gracz1/move.c gracz1/attack.c gracz1/save.c gracz1/mining.c -lpthread -o player1

Player 2:
gcc gracz2/player.c gracz2/load_status.c gracz2/load_player_input.c gracz2/map.c gracz2/list.c gracz2/train.c gracz2/move.c gracz2/attack.c gracz2/save.c gracz2/mining.c -lpthread -o player2

Arbiter:
gcc mediator/mediator.c mediator/load_status.c mediator/load_orders.c -o arbiter

Mediatora uruchamia komenda: ./arbiter

Program przetestowano w środowiskach MacOS Monterey 12.6.6 oraz Ubuntu 22.04.