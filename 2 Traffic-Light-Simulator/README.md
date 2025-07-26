# Traffic Light Simulator

A Finite State Machine (FSM) based traffic light simulator written in C++. It simulates the transition between RED, GREEN, and YELLOW lights with customizable durations and an optional pedestrian signal.

## Features
- **FSM-Based Logic**: Uses a robust state machine for light transitions.
- **ASCII Visualization**: Displays a visual representation of the traffic light in the terminal.
- **Customizable Durations**: Configure timings for RED, GREEN, and YELLOW phases.
- **Pedestrian Mode**: Includes a "WALK" / "DON'T WALK" signal synchronized with the traffic light.
- **Real-Time Simulation**: Uses a timer to countdown to the next state transition.

## How to Run

### Compilation
Compile the source code using `g++`. Note that this project uses Windows-specific headers (`windows.h`) for the `Sleep` function.

```bash
g++ main.cpp -o traffic_sim
```

### Execution
Run the compiled executable:

```bash
./traffic_sim
```

## Example Configuration & Simulation

```bash
========================================
       TRAFFIC LIGHT SIMULATOR
========================================

  Default durations:
    RED    = 5s
    GREEN  = 5s
    YELLOW = 2s

  Customize durations? (y/n): n
  Enable pedestrian signal? (y/n): y

  Current Configuration:
  RED    = 5s
  GREEN  = 5s
  YELLOW = 2s
  Pedestrian signal = ON

  Starting simulation...

========================================
       TRAFFIC LIGHT SIMULATOR
========================================

        +-------+
        |   *   |
        |       |
        |       |
        +-------+

  Light:  RED
  Timer:  5s remaining
  Ped:    WALK

  [=====     ]

  Press Ctrl+C to stop
========================================
```
