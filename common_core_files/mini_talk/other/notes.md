# My Notes

- I used write() with single quotes to write a single char, since the double quotes acts as a string and includes '\0' at the end.
- I used ft_putstr_fd() instead of ft_printf() for a lighter processing since ft_print() does parsing and validation to detect what to print.

## ToDo

- I got stuck at handling "why the scond message isn't recieved".

## My reading notes

The struct `sigaction` in C is a data structure used to define the behavior of a process when it receives a specific signal. It is primarily used with the `sigaction()` system call to establish custom signal handlers, query current signal dispositions, or reset default signal actions.

Key Members of struct sigaction:

`sa_handler`: A pointer to a signal-catching function that takes a single int argument (the signal number). Used when `SA_SIGINFO` is not set.

`sa_sigaction`: A pointer to a more advanced signal-catching function that takes three arguments: the signal number, a `siginfo_t *` (providing detailed signal context), and a `void *` (pointing to the signal context, typically a ucontext_t). Used when `SA_SIGINFO` is set.

`sa_mask`: A sigset_t that specifies additional signals to be blocked (masked) while the signal handler is executing. This prevents reentrancy issues.

`sa_flags`: A set of flags that modify signal handling behavior. Common flags include:

- `SA_SIGINFO`: Enables the three-argument form of the handler `sa_sigaction`.
- `SA_RESTART`: Causes interrupted system calls to be automatically restarted.
- `SA_NODEFER`: Prevents the signal from being blocked during handler execution.
- `SA_NOCLDSTOP`: Suppresses `SIGCHLD` signals when child processes stop.
- `SA_NOCLDWAIT`: Prevents child processes from becoming zombies after termination.
- `sa_restorer`: (Obsolete) A pointer to a signal trampoline function; not intended for application use and not specified by `POSIX`.

Important Notes:

The `sa_handler` and `sa_sigaction` members are stored in a union and should not be used simultaneously.

The structure is defined in `<signal.h>`, and the `sigaction()` function uses it to install or query signal actions.

It is the preferred, more reliable, and portable alternative to the older `signal()` function. This structure enables precise control over signal handling, including signal masking, extended signal information, and reliable, persistent handlers.
