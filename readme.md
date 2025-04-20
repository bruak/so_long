# so_long

A simple 2D game where you collect coins and reach the exit, implemented using the MiniLibX graphics library.

## Table of Contents
- [so\_long](#so_long)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Game Rules](#game-rules)
  - [Requirements](#requirements)
  - [Installation](#installation)
  - [Controls](#controls)
  - [Map Format](#map-format)
  - [Implementation Details](#implementation-details)
  - [Project Structure](#project-structure)

## Overview

so_long is a minimalist 2D game where the player must collect all coins in a map and reach the exit while navigating through walls. The game is built using the MiniLibX graphics library and focuses on proper memory management, error handling, and basic game mechanics.

## Game Rules

- The player can move in four directions: up, down, left, and right
- The player cannot move through walls
- The player must collect all coins before being able to exit the map
- The game keeps track of the number of moves and displays them in the terminal
- The game ends when the player reaches the exit after collecting all coins

## Requirements

- macOS or Linux
- MiniLibX graphics library
- C compiler (gcc/clang)
- make

## Installation

1. Clone the repository
```bash
git clone <repository-url>
cd so_long
```

2. Compile the game
```bash
make
```

3. Run the game with a valid map
```bash
./so_long maps/map.ber
```

## Controls

- **W or ↑**: Move up
- **A or ←**: Move left
- **S or ↓**: Move down
- **D or →**: Move right
- **ESC**: Quit the game

## Map Format

Maps must be stored in files with the `.ber` extension and follow these rules:

- **1**: Wall
- **0**: Empty space
- **P**: Player starting position (only one allowed)
- **E**: Exit (only one allowed)
- **C**: Collectible/Coin (at least one required)

Maps must be rectangular, surrounded by walls, and contain a valid path where the player can reach all coins and the exit.

Example of a valid map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## Implementation Details

The game implements:

- Map parsing and validation
- Pathfinding to ensure all coins and exit are reachable
- Proper memory management
- Event handling for keyboard input
- Rendering with MiniLibX
- Error handling for invalid maps or missing files

## Project Structure

- **base.c**: Main file with initialization and game loop
- **data1.c - data6.c**: Core game logic including map handling, player movement, etc.
- **so_long.h**: Header file containing all function declarations and structure definitions
- **libft/**: Custom library with utility functions
- **minilibx/**: Graphics library for rendering
- **maps/**: Directory containing various map files for the game
- **textures/**: Game assets in XPM format
  - **s.xpm**: Player sprite
  - **g.xpm**: Collectible/Coin sprite
  - **p.xpm**: Exit sprite
  - **f.xpm**: Floor sprite
  - **w.xpm**: Wall sprite

---

*This project is part of the 42 School curriculum.*