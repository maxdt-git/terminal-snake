# SnakeC

A classic Snake game that runs directly in the terminal, written in C with no external libraries.

**Stack:** C · POSIX `termios` · ANSI escape codes · Make

## Description

The snake moves on a 40×20 board drawn with ANSI escape codes. Eat the food to grow; hitting a wall or your own body ends the game.

Technical points:

- **Raw terminal mode** with `termios`: no echo, no line buffering, non-blocking reads (`VMIN = 0`, `VTIME = 0`), so the game keeps running while waiting for input. The original terminal settings are restored on exit.
- **Arrow-key parsing** from ANSI escape sequences (`ESC [ A/B/C/D`).
- **Snake stored as a linked list**: a new head is added each tick and the tail is freed unless food was eaten, so movement costs O(1). All nodes are freed at the end of the game.
- Wall and self-collision detection, random food placement.

## Instructions

Requirements: `gcc` and `make`, on Linux or macOS.

```bash
make        # builds ./snake
./snake     # play with the arrow keys
make fclean # removes objects and binary
```

## Project structure

| File | Role |
|---|---|
| `main.c` | Game loop: read input → update → render → wait |
| `game.c` | Snake (linked list), movement, collisions, food |
| `input.c` | Non-blocking arrow-key reading |
| `render.c` | Board drawing with ANSI escape codes |
| `terminal.c` | Raw mode on / restore |
| `ft_utils.c` | Small libc reimplementations |
