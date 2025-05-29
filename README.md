# minitalk

## 📡 Description

**minitalk** is a 42 project that introduces inter-process communication in Unix using POSIX signals. The objective is to implement a basic client-server communication system, where messages are transmitted bit by bit using `SIGUSR1` and `SIGUSR2`.

This project offers a hands-on approach to signal handling, bit manipulation, and asynchronous communication.

---

## 🎯 Objective

Build two programs :

- **Server** : Waits for messages sent by clients.
- **Client** : Sends a message (string) to the server, one bit at a time, using Unix signals.

Once the server receives the full message, it prints it to the terminal.

---

## 🚀 Features

### ✅ Communication System

- Sends messages from client to server using :
  - `SIGUSR1` → bit `0`.
  - `SIGUSR2` → bit `1`.
- Signals are sent for each bit of each character in the message.
- End of message is marked by a null terminator (`'\0'`).

### 📥 Server

- Starts by displaying its **PID**.
- Listens for incoming bits and rebuilds characters.
- Prints the received message to the terminal.

### 📤 Client

- Takes the **server PID** and the **message** as arguments.
- Converts each character of the string into binary.
- Sends each bit with a corresponding signal.
- Waits briefly between signals to ensure the server processes them.

---

## 🧠 Technical Highlights

- Uses `sigaction()` for signal handling.
- Implements signal acknowledgment (optional bonus).
- Handles message termination and edge cases.
- Ensures reliable bitwise transmission via proper timing.

---

## 🛠️ Compilation

```bash
make
./server
```
In another terminal.
```bash
./client <PID> <Message>
```

---

## 📝 Resources
- **`1`** : https://webusers.i3s.unice.fr/~tettaman/Classes/L2I/ProgSys/6_ProgSysLinuxSignaux.pdf
