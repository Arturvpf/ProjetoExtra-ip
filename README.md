# Niryo One Robotic Arm Controller for CoppeliaSim

<div align="center">

![CoppeliaSim](https://img.shields.io/badge/CoppeliaSim-4.3+-blue.svg)
![C Language](https://img.shields.io/badge/Language-C-brightgreen.svg)
![License](https://img.shields.io/badge/License-Educational-yellow.svg)

*A C program to control the Niryo One robotic arm for simulating electronic voting processes in CoppeliaSim*

</div>

## Table of Contents
- [Project Overview](#project-overview)
- [Team Members](#team-members)
- [Features](#features)
- [Project Architecture](#project-architecture)
- [Installation & Setup](#installation--setup)
- [Usage Guide](#usage-guide)
- [File Structure](#file-structure)
- [API Reference](#api-reference)
- [Contributing](#contributing)
- [Resources](#resources)

## Project Overview

This project is an optional assignment for the Introduction to Programming course in Computer Engineering at UFPE. The objective is to develop a C program that controls the Niryo One robotic arm in the CoppeliaSim simulator to simulate electronic voting processes.

The program reads voting sequences from a text file and translates them into precise robotic movements, where the arm "presses" virtual buttons corresponding to each digit in the voting sequence.

### Academic Context
This is the first phase of the robotics project. Only teams that successfully complete the simulation phase will be eligible to proceed to the practical phase using the real Niryo One robot. The project deliverable is a short video (maximum 5 minutes) explaining the developed solution.

## Team Members

| Name | GitHub |
|------|--------|
| **Artur Vinicius Pereira Fernandes** | (arturvpf) |
| **Nathan Barbosa** | (sannathan) |
| **Felipe Mateus Falcao Barreto** | (felipemfb) | 


## Features

### Core Functionality
- **CoppeliaSim Integration**: Seamless connection via remote API
- **File-based Input**: Reads voting sequences from configurable text files
- **Precision Control**: Accurate joint positioning for digit selection
- **Automatic Reset**: Returns to home position after each sequence
- **Real-time Feedback**: Console logging for operation status

### Advanced Features
- **Modular Architecture**: Separate functions for different arm movements
- **Error Handling**: Robust file I/O and connection management
- **Configurable Timing**: Adjustable delays for different movement phases
- **Easy Calibration**: Simple parameter adjustment for different setups

## Project Architecture

```
CoppeliaSim Environment
    ↓
Remote API Connection
    ↓
C Control Program
    ↓
Joint Position Commands
    ↓
Niryo One Simulation
```

## Installation & Setup

### Prerequisites
- **CoppeliaSim 4.3+** - [Download here](https://www.coppeliarobotics.com/downloads)
- **GCC Compiler** or compatible C compiler
- **CoppeliaSim Remote API** library files

### Setup Steps
1. **Install CoppeliaSim**
   ```bash
   # Download and install CoppeliaSim from official website
   # Ensure remote API is enabled in the simulation
   ```

2. **Clone Repository**
   ```bash
   git clone [repository-url]
   cd ProjetoExtra-ip
   ```

3. **Prepare Input Files**
   ```bash
   # Edit voting_sequences.txt with your desired number sequences
   echo "12345" > voting_sequences.txt
   echo "67890" >> voting_sequences.txt
   ```

## Usage Guide

### Basic Usage
1. **Start CoppeliaSim** and load the Niryo One scene
2. **Enable Remote API** (usually on port 19999)
3. **Compile the program**:
   ```bash
   gcc niryo_controller.c -o niryo_controller -I./remoteApi -L./remoteApi -lremoteApi
   ```
4. **Run the controller**:
   ```bash
   ./niryo_controller
   ```

### Configuration
- **Input File**: Modify `voting_sequences.txt` to change voting sequences
- **Connection Settings**: Update IP/port in source code if needed
- **Movement Parameters**: Adjust joint angles and timing in the arrays

## File Structure

```
ProjetoExtra-ip/
├── niryo_controller.c          # Main robotic arm controller
├── niryo_advanced_controller.c # Advanced version with extended features  
├── voting_sequences.txt        # Input sequences for voting simulation
├── example_sequences.txt       # Additional example input data
├── Main/
│   └── main.c                  # Alternative main implementation
└── README.md                   # This documentation file
```

## API Reference

### Core Functions
- `InitialPosition()` - Moves arm to home/zero position
- `DefinedPoint()` - Positions arm at reference point (above digit 5)
- `ConfirmVote()` - Executes vote confirmation sequence
- `Vote()` - Executes movement for a specific digit

### Configuration Arrays
- `numj3[]`, `numj2[]`, `numj1[]` - Joint positions for digits 0-9
- `t1[]`, `t2[]`, `t3[]`, `t4[]` - Timing arrays for movement phases

## Contributing

### Development Guidelines
1. Follow consistent C coding standards
2. Add comprehensive comments for all functions
3. Test thoroughly in simulation before hardware deployment
4. Document any parameter changes or calibration updates

### Reporting Issues
- Use GitHub Issues for bug reports
- Include CoppeliaSim version and system information
- Provide input files that reproduce the issue

## Resources

### Official Documentation
- [CoppeliaSim Download](https://www.coppeliarobotics.com/downloads) - Get the latest version
- [CoppeliaSim Documentation](https://www.coppeliarobotics.com/helpFiles/index.html) - Complete API reference
- [Project Drive Folder](https://drive.google.com/drive/folders/1UEslC_PPhohbdYZ5a6dVI-MGLrZ6fo_R?usp=share_link) - Project details and requirements

### Learning Materials
- [YouTube - CoppeliaSim C Setup](https://www.youtube.com/watch?v=gQTDW-8lxTI&ab_channel=NareshMarturi) - Setup tutorial
- [YouTube - Robotics Course Playlist](https://www.youtube.com/playlist?list=PLjzuoBhdtaXOoqkJUqhYQletLLnJP8vjZ) - Complete course
- [Project Groups Spreadsheet](https://docs.google.com/spreadsheets/d/1QtdHF4W7NTMjuiaZrwLgFa29I9G-9U8rdZfHW-clLj4/edit#gid=0) - Team coordination

### Technical References
- [Remote API Documentation](https://www.coppeliarobotics.com/helpFiles/en/remoteApiOverview.htm)
- [Joint Control Examples](https://www.coppeliarobotics.com/helpFiles/en/jointCtrlCallbackScript.htm)
- [C Remote API Functions](https://www.coppeliarobotics.com/helpFiles/en/remoteApiFunctions.htm)

## License

This project is developed for educational purposes as part of the Introduction to Programming course in Computer Engineering at UFPE. Feel free to use and modify the code for learning and educational applications.

## Acknowledgments

- **Course Instructors** - For providing the optional robotics project framework
- **CoppeliaSim Team** - For the excellent simulation environment
- **Niryo Robotics** - For the open-source robot platform
- **UFPE Computer Engineering Program** - For supporting hands-on robotics education

---

**Optional Project - Introduction to Programming Course**  
*Computer Engineering - UFPE*

*Note: This is the simulation phase of the project. Only teams that successfully complete this phase will be eligible for the practical phase with the real Niryo One robot.*
