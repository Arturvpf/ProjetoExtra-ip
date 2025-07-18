# 🤖 Niryo One Robotic Arm Controller for CoppeliaSim

<div align="center">

![CoppeliaSim](https://img.shields.io/badge/CoppeliaSim-4.3+-blue.svg)
![C Language](https://img.shields.io/badge/Language-C-brightgreen.svg)
![License](https://img.shields.io/badge/License-Educational-yellow.svg)

*An advanced robotic arm control system for simulating electronic voting processes using the Niryo One robot in CoppeliaSim environment*

</div>

## 📋 Table of Contents
- [Project Overview](#-project-overview)
- [Team Members](#-team-members)
- [Features](#-features)
- [Project Architecture](#-project-architecture)
- [Installation & Setup](#-installation--setup)
- [Usage Guide](#-usage-guide)
- [File Structure](#-file-structure)
- [API Reference](#-api-reference)
- [Contributing](#-contributing)
- [Resources](#-resources)

## 🎯 Project Overview

This project demonstrates advanced robotic programming by controlling a Niryo One robotic arm within the CoppeliaSim simulation environment. The system reads numeric sequences from input files and translates them into precise robotic movements, simulating an electronic voting process where the arm "presses" virtual buttons corresponding to each digit.

### 🎓 Academic Context
Developed as part of an advanced robotics course, this project serves as a stepping stone from simulation to real-world robotics applications. Teams that successfully complete the simulation phase are eligible to test their algorithms on actual Niryo One hardware.

## 👥 Members

| **[Member 1]** | Arturvpf
| **[Member 2]** | Felipemfb
| **[Member 3]** | Sannathan


## ✨ Features

### Core Functionality
- 🔗 **CoppeliaSim Integration**: Seamless connection via remote API
- 📖 **File-based Input**: Reads voting sequences from configurable text files
- 🎯 **Precision Control**: Accurate joint positioning for digit selection
- 🔄 **Automatic Reset**: Returns to home position after each sequence
- ⚡ **Real-time Feedback**: Console logging for operation status

### Advanced Features
- 🎛️ **Modular Architecture**: Separate functions for different arm movements
- 🛡️ **Error Handling**: Robust file I/O and connection management
- 📊 **Configurable Timing**: Adjustable delays for different movement phases
- 🔧 **Easy Calibration**: Simple parameter adjustment for different setups

## 🏗️ Project Architecture

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

## 🚀 Installation & Setup

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

## 📖 Usage Guide

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

## 📁 File Structure

```
ProjetoExtra-ip/
├── 📄 niryo_controller.c          # Main robotic arm controller
├── 📄 niryo_advanced_controller.c # Advanced version with extended features  
├── 📄 voting_sequences.txt        # Input sequences for voting simulation
├── 📄 example_sequences.txt       # Additional example input data
├── 📁 src/
│   └── 📄 main.c                  # Alternative main implementation
├── 📁 docs/
│   ├── 📄 API_Reference.md        # Detailed API documentation
│   └── 📄 Setup_Guide.md          # Comprehensive setup instructions
└── 📄 README.md                   # This documentation file
```

## 🔧 API Reference

### Core Functions
- `InitialPosition()` - Moves arm to home/zero position
- `DefinedPoint()` - Positions arm at reference point (above digit 5)
- `ConfirmVote()` - Executes vote confirmation sequence
- `Vote()` - Executes movement for a specific digit

### Configuration Arrays
- `numj3[]`, `numj2[]`, `numj1[]` - Joint positions for digits 0-9
- `t1[]`, `t2[]`, `t3[]`, `t4[]` - Timing arrays for movement phases

## 🤝 Contributing

### Development Guidelines
1. Follow consistent C coding standards
2. Add comprehensive comments for all functions
3. Test thoroughly in simulation before hardware deployment
4. Document any parameter changes or calibration updates

### Reporting Issues
- Use GitHub Issues for bug reports
- Include CoppeliaSim version and system information
- Provide input files that reproduce the issue

## 📚 Resources

### Official Documentation
- [CoppeliaSim Download](https://www.coppeliarobotics.com/downloads) - Get the latest version
- [CoppeliaSim Documentation](https://www.coppeliarobotics.com/helpFiles/index.html) - Complete API reference
- [Niryo One Documentation](https://docs.niryo.com/) - Robot specifications

### Learning Materials
- [YouTube - CoppeliaSim C Setup](https://www.youtube.com/watch?v=gQTDW-8lxTI&ab_channel=NareshMarturi) - Setup tutorial
- [YouTube - Robotics Course Playlist](https://www.youtube.com/playlist?list=PLjzuoBhdtaXOoqkJUqhYQletLLnJP8vjZ) - Complete course
- [Project Groups Spreadsheet](https://docs.google.com/spreadsheets/d/1QtdHF4W7NTMjuiaZrwLgFa29I9G-9U8rdZfHW-clLj4/edit#gid=0) - Team coordination

### Technical References
- [Remote API Documentation](https://www.coppeliarobotics.com/helpFiles/en/remoteApiOverview.htm)
- [Joint Control Examples](https://www.coppeliarobotics.com/helpFiles/en/jointCtrlCallbackScript.htm)
- [C Remote API Functions](https://www.coppeliarobotics.com/helpFiles/en/remoteApiFunctions.htm)

## 📄 License

This project is developed for educational purposes as part of an academic robotics course. Feel free to use and modify the code for learning and educational applications.

## 🙏 Acknowledgments

- **Course Instructors** - For providing the challenge framework and guidance
- **CoppeliaSim Team** - For the excellent simulation environment
- **Niryo Robotics** - For the open-source robot platform
- **Academic Institution** - For supporting hands-on robotics education

---
Feel free to adapt and expand this project for your own robotic simulation experiments!
Projeto extra da cadeira de introdução a programação do curso de engenharia da computação
