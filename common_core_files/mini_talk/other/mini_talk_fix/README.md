_This project has been created as part of the 42 curriculum by halragga_

# MiniTalk

## 📋 Description

### Mini Talk - 42 Amman Project

A Unix signal-based inter-process communication (IPC) system, or in human simple words: a program that allows a client to send messages to a server using only `SIGUSR1` and `SIGUSR2` signals.

### Project Overview

**Mini Talk** is a 42 school project that demonstrates:

- Signal handling using `sigaction()` with `SA_SIGINFO` flag
- Bit manipulation for character encoding/decoding
- Inter-process communication (IPC) via signals
- Robust error handling and edge case management
- Memory management with dynamic string allocation

## 🧑‍💻 Instructions

### 🏗️ Installation

1. copy the `SSH` clone link.
2. go to your terminal and nvigate to the desired directory.    
3. write this command in your terminal `git clone <clone link>` and replace `<clone link>` with actual link.    
4. hit `Enter` and now you got your clone ready.

### 🔧 Compilation

1. to compile the project you have 2 options, either compile the mandatory part, or the bonus part, you can compile both too (each in a separate command):
    - mandatory:
        . write this command in your terminal `make`.
    - bonus:
        . write this command in your terminal `make bonus`.
2. to clean the project:
    - `make clean` to the remove the object files only.
    - `make fclean` to objects, excutables, archieves, all at once.
    - `make re` to recompile the project.

### 🚀 Excution

1. mandatory:
    1. on terminal 1: Start the server `./server`
        - the output should be: `Server PID: 12345`
    2. terminal 2: Send a message to server:
        - `./client 12345 "Hello, server!"`
2. bonus:
    1. terminal 1: Start the bonus server:L `./server_bonus`
        - the output should be: `Server PID: 12345`
    2. terminal 2: Send a message to the server:
        - `./client_bonus 12345 "Hello, server!"`
        - output:
            1. `.` one dot per byte received (byte/char acknowledgment)
            2. `##message received!##` on a new line (message acknowledgment)

## 🌐 Resources

I relied on the following resources side by side with my peers support and guidance:

1. co-pilot's ability to plan manage and guidance throught the project's requirements to reduce the time spent on the project and to explain in detail whatever question or misunderstanding I get.
2. the siganal.h man page which gave me helpful and useful insights on the signals to be used, in addition to the function provided by the subject.

## Additional

### 🎯 Objectives

#### Mandatory Part

- ✅ Transmit any size message between client and server
- ✅ Server displays its PID on startup
- ✅ Client receives server acknowledgement after each bit
- ✅ Use only `SIGUSR1` and `SIGUSR2` signals
- ✅ Handle multiple messages without server restart
- ✅ Minimize global variables

#### Bonus Part

- ✅ Server sends confirmation when message reception is complete
- ✅ Client displays a character (`.`) per received byte
- ✅ Client displays confirmation message on completion

---

### 🏗️ Project Structure

```bash
mini_talk/
├── Makefile                 # Compilation automation
├── mini_talk.h             # Main header file
├── mini_talk_bonus.h       # Bonus header file
├── README.md               # This file
│
├── c_files/
│   ├── server_main.c       # Mandatory server implementation
│   ├── client_main.c       # Mandatory client implementation
│   ├── server_main_bonus.c # Bonus server with feedback
│   └── client_main_bonus.c # Bonus client with progress display
│
├── Libft/                  # Custom C library
│   ├── *.c                 # 40+ utility functions
│   ├── libft.h
│   └── Makefile
│
└── other/
    ├── FINAL_42_EVALUATION_REPORT.md
    ├── MEMORY_ANALYSIS.md
    ├── feedback.md
    └── Testing utilities
```

---

### 💻 Technical Implementation

#### Signal-Based Communication Protocol

The project uses a **8-bit binary encoding** for each character:

1. **Bit Transmission**:
   - Extract one bit at a time from the character (MSB first)
   - Send `SIGUSR2` for bit value `1`
   - Send `SIGUSR1` for bit value `0`

2. **Acknowledgement**:
   - Server acknowledges each bit by sending `SIGUSR1` back
   - Client waits for acknowledgement before sending next bit
   - This ensures reliable transmission

3. **Message Termination**:
   - After all characters, send a null terminator (`\0`)
   - Signals the end of the message

#### Example: Sending Character 'A' (65 = 01000001)

```bash
Bit: 7  6  5  4  3  2  1  0
Val: 0  1  0  0  0  0  0  1
Sig: 1  2  1  1  1  1  1  2

0 → Send `SIGUSR1`, wait for ACK
1 → Send `SIGUSR2`, wait for ACK
... (repeat for all 8 bits)
```

#### Key Data Structures

##### Server Signal Handler (Mandatory)

```c
static void handle_signal(int signum, siginfo_t *info, void *context)
{
    static int bit_index;              // Tracks bit position (0-7)
    static unsigned char crnt_char;    // Accumulates bits
    static char *msg_str;              // Dynamically allocated message
    
    crnt_char <<= 1;                   // Shift left to make room
    if (signum == SIGUSR2)
        crnt_char |= 1;                // Set bit to 1
    
    bit_index++;
    if (bit_index == 8)                // Complete character received
    {
        ft_str_saver(crnt_char, &msg_str);  // Save/display
        bit_index = 0;
        crnt_char = 0;
    }
    
    kill(info->si_pid, SIGUSR1);       // Send acknowledgement
}
```

##### Client Transmission

```c
static void ft_send(pid_t pid, char c)
{
    int bit = 7;
    while (bit >= 0)
    {
        g_ack_received = 0;
        
        if ((c >> bit) & 1)            // Check bit value
            kill(pid, SIGUSR2);        // Bit is 1
        else
            kill(pid, SIGUSR1);        // Bit is 0
        
        while (g_ack_received == 0)    // Wait for acknowledgement
            pause();
        
        bit--;
    }
}
```

---

### 🛡️ Error Handling

The project implements comprehensive error handling:

| Error Code | Meaning |
|-----------|---------|
| 1 | Invalid arguments or signal setup failure |
| 2 | `sigemptyset()` failed |
| 3 | `sigaddset()` failed |
| 4 | Memory allocation failure |
| 5 | Signal transmission failure |
| 6-8 | `sigaction()` setup failed |

All errors are reported to `stderr` with descriptive messages.

---

### 📊 Bonus Features

#### Enhanced Server (bonus)

- Sends `SIGUSR2` signal when entire message is received
- Enables client to confirm successful delivery
- Maintains message accumulation across multiple sends

#### Enhanced Client (bonus)

- Displays progress: one `.` per byte received
- Prints `##message received!##` on completion
- Counts bits received and provides visual feedback
- Enhanced signal handler with `SA_SIGINFO` for more data

---

### 🔍 Libft Library

This project uses a custom C library (`Libft`) with 40+ utility functions including:

- Memory functions: `ft_calloc()`, `ft_memset()`, `ft_memcpy()`
- String functions: `ft_strlen()`, `ft_strdup()`, `ft_strjoin()`, `ft_strtrim()`
- Character checks: `ft_isalpha()`, `ft_isdigit()`, `ft_isalnum()`
- Conversion functions: `ft_atoi()`, `ft_itoa()`
- Printf replacement: `ft_printf()` with format specifiers

**Compilation**: Automatically compiled via `make` - builds `libft.a` archive

---

### ⚙️ Compilation Flags

```makefile
CFLAGS = -Wall -Wextra -Werror -I. -I$(LIBFT_PATH)
```

- `-Wall -Wextra -Werror`: Strict warning enforcement
- `-I.`: Include current directory (for headers)
- `-I$(LIBFT_PATH)`: Include Libft directory

---

### 🧪 Testing

Included test scripts:

- `mini_talk_tester.sh` - Basic functionality tests
- `minitalk_42_final_evaluation.sh` - Full 42 evaluation
- `final_42_evaluation_corrected.sh` - Corrected scoring

Run tests:

```bash
bash other/mini_talk_tester.sh
bash other/minitalk_42_final_evaluation.sh
```

---

### 📝 Implementation Notes

#### Variable Constraints

- **Mandatory**: Limited global variables (only `sig_atomic_t` for signal flags)
- **Bonus**: Same constraints maintained

#### Memory Safety

- Dynamic string allocation for message buffer
- Proper cleanup with `free()`
- No memory leaks (verified with valgrind)

#### Signal Safety

- Used `sigaction()` with `SA_SIGINFO` flag
- Safe type: `volatile sig_atomic_t` for signal flags
- Proper signal masking with `sigemptyset()` and `sigaddset()`

#### Process Communication

- Validates PID before sending signals
- Handles edge cases: invalid PIDs, non-existent processes
- Reliable bit-by-bit transmission with acknowledgement

---

### 🐛 Known Limitations

- Character encoding limited to ASCII/extended ASCII
- No built-in message queuing (sequential processing)
- Server performance depends on signal delivery speed
- On heavily loaded systems, signal delivery may be delayed

---

### 📚 Resources & References

- POSIX signals: `man 7 signal`, `man 2 sigaction`
- Bit manipulation techniques
- Process communication patterns
- Signal handling best practices

---

### 👤 Author

**Hussam Ragga** (`halragga@student.42amman.com`)
- 42 Amman Student

---

### 📄 License

Part of 42 School Curriculum - All Rights Reserved

---

### ✨ Highlights

- **Pure C implementation** - No external libraries except Libft
- **Efficient bit manipulation** - Clean encoding/decoding logic
- **Robust error handling** - Comprehensive validation and error reporting
- **Signal mastery** - Advanced sigaction usage with SA_SIGINFO
- **Memory conscious** - Minimal global state, proper cleanup
- **Bonus implementation** - Full feedback system with progress display
- **Test coverage** - Evaluation scripts included
- **Well-documented** - Code comments and comprehensive README

---

**Last Updated**: February 8, 2026
**Final Score**: 22/25 (88% - Excellent)
