# minitalk

Welcome to the minitalk project repository by malescordia.

## Overview
minitalk is a lightweight inter-process communication (IPC) project at 42. The goal is to create a client-server architecture, where the client sends a string message to the server using a minimalistic communication protocol. The project emphasizes signal handling and the intricacies of inter-process communication in a Unix environment.

## Project Highlights
- Utilizes signals for communication between client and server.
- Focuses on efficient signal handling and message transmission.
- Written in C as part of the 42 curriculum.

## Key Files
- `client.c`: Sends a string message to the server.
- `server.c`: Receives the message from the client and displays it.

## How to Use
1. Clone the repository: `git clone https://github.com/malescordia/minitalk.git`
2. Navigate to the project folder: `cd minitalk`
3. Compile both the client and server: `make`
4. Launch the server in one terminal: `./server`
5. In another terminal, launch the client with a message: `./client "Hello, Minitalk"`

Enjoy exploring the world of minitalk!
