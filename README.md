<div align="center">

# Conway's Game of Life

**A C++ implementation of Conway's cellular automaton.**

![Language](https://img.shields.io/badge/language-C%2B%2B-00599C?logo=cplusplus&logoColor=white)
![Topic](https://img.shields.io/badge/topic-cellular%20automata-6f42c1)
![Status](https://img.shields.io/badge/status-learning%20project-lightgrey)

</div>

## Overview

This project implements Conway's Game of Life, a cellular automaton in which a grid evolves over discrete generations according to a small set of local rules.

Each cell is either alive or dead. Its state in the next generation depends on the number of neighboring live cells, producing patterns that can stabilize, oscillate, or move across the grid.

## Configuration

The original implementation exposes grid-size parameters:

| Parameter | Meaning |
|---|---|
| `Tamanho_X` | Grid width |
| `Tamanho_Y` | Grid height |

The simulation is displayed in the terminal. A small terminal font may be necessary to fit larger grids on screen.

## Requirements

- C++ compiler
- Linux terminal for the documented terminal-based workflow

## Build and run

The repository contains a helper script named `run.bat`. Its commands and paths should be checked for the environment in which you intend to run the program.

For a manual build, compile the source file:

```bash
g++ main.cpp -o game_of_life
./game_of_life
```

Adjust the compiler command if the source requires additional libraries or flags.

## Repository layout

```text
.
├── main.cpp
├── run.bat
└── README.md
```

## Concepts explored

- Cellular automata
- Grid and matrix representation
- Neighbor counting
- Discrete-time simulation
- Terminal rendering

## Project status

Educational implementation. The repository is intended as a compact study of cellular automata rather than a production simulation framework.

## References

- [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

## License

No license file was identified in the repository at the time of writing. Contact the author before redistributing or reusing the project.
