# Phoenix-RTOS Process Tree Traversal & System Call Implementation

This project demonstrates the implementation of a custom system call and a user-space application for exploring the process tree within the **Phoenix-RTOS** microkernel environment. The goal is to traverse the system processes to a specific depth and retrieve process information (PID) from the kernel.


## Project Architecture

The project is organized into layers representing the operating system hierarchy. This structure ensures a clean separation between kernel-level logic and user-space execution:

### 1. `kernel_side/`
Contains modifications to the Phoenix-RTOS microkernel.
* **`syscalls.c`**: Implementation of the kernel-level logic for the new system call. It directly interacts with the process management structures.
* **`syscalls.h`**: Definition of the unique system call ID used for identification.

### 2. `library_side/`
Acts as the bridge (API) between user-space and kernel-space, allowing applications to invoke kernel functions.
* **`sys.c`**: The wrapper function that triggers the `__syscall` interface.
* **`getsetvariable.h`**: Header definitions and function prototypes for the custom API.

### 3. `user_apps/`
Practical demonstrations of the system call in a user environment.
* **`test_path/`**: The primary application. It performs a "Longest Path" or "Depth Traversal" test within the process tree.
* **`setVariable/`**: An auxiliary application used to verify variable persistence and syscall connectivity.


## How It Works

1.  **System Call Integration**: A new syscall was registered within the kernel, allowing user-space programs to query protected process data.
2.  **Tree Traversal Logic**: The `test_path` application implements a depth-first traversal strategy to navigate the process hierarchy until it reaches a user-defined depth.
3.  **Boot Integration**: To overcome QEMU keyboard mapping issues, the application is integrated into the `syspage`. This allows it to execute automatically during the system boot sequence.


## Results

The implementation was successfully verified in a QEMU environment. The program demonstrated the ability to reach a depth of 10 and correctly identify the target process (Leaf PID).

**Execution Proof:**
![Result Screenshot](./docs/screenshot_depth10.png)
*(Note: The full execution log can be seen in the screenshot above, showing successful leaf detection at Depth 10.)*

## Building and Running

To build the project and run it within the Phoenix-RTOS environment, follow these steps:

1.  **Build the entire image:**
    ```bash
    TARGET=ia32-generic-qemu ./phoenix-rtos-build/build.sh all project image
    ```
2.  **Run in QEMU:**
    ```bash
    ./scripts/ia32-generic-qemu.sh
    ```
3.  **Manual Execution (via psh):**
    ```bash
    /bin/test_path 10
    ```

## Academic Context
This project was developed as a final assignment for the Operating Systems course at **Warsaw University of Technology (WUT)**.

**Author:** Esin  
**Date:** April 2026
