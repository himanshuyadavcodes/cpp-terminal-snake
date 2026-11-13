# C++ Terminal Snake Engine

A lightweight, real-time terminal implementation of Classic Snake written in C++ for Windows, featuring non-blocking keyboard input polling, wrap-around boundary mechanics, and dynamic tail-segment tracking.

## Features
- **Non-Blocking Input Loop:** Uses `<conio.h>` (`_kbhit` and `_getch`) for real-time `W` `A` `S` `D` directional control with 180-degree self-reversal prevention.
- **Toroidal (Wrap-Around) Grid:** Crossing any border seamlessly wraps the snake to the opposite wall.
- **State & Collision Tracking:** Tracks body segment coordinates frame-by-frame to detect fruit consumption and self-intersection crashes.

## Build & Run (Windows / MinGW)
```bash
g++ -std=c++20 src/main.cpp -o snake
./snake