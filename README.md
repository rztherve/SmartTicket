# SmartTicket 🎟️

Petit projet en **C++ / Qt / SQLite** pour illustrer la création et la gestion de tickets (système billettique simplifié).

## Objectif
Ce projet a pour but de démontrer :
- L'utilisation du C++ moderne (C++17)
- L’utilisation de **Qt5** (Core, SQL)
- La gestion d’une base **SQLite**
- L’organisation professionnelle du code et du projet (CMake, Git)

## Compilation
```bash
sudo apt install build-essential cmake qtbase5-dev libqt5sql5-sqlite libsqlite3-dev
mkdir build && cd build
cmake ..
make -j$(nproc)
./smartticket
