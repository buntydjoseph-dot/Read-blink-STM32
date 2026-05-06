
# Bare-Metal STM32 GPIO Control: Digital Input to LED

This repository contains a simple, bare-metal C program written for STM32 microcontrollers (specifically targeting the STM32F4 series). It demonstrates how to interact with hardware registers directly to read a digital input and write a digital output without relying on external libraries like HAL (Hardware Abstraction Layer) or standard peripheral libraries.

## 📌 Project Overview

The program continuously polls the logical state of an input pin (**PA0**). Depending on the voltage level manually applied to that pin, it toggles an LED connected to pin **PA6**:
* **Pin Driven HIGH (PA0 is 1):** LED turns OFF (PA6 is LOW)
* **Pin Driven LOW (PA0 is 0):** LED turns ON (PA6 is HIGH)

This is an excellent foundational project for understanding memory-mapped I/O, bitwise operations, and clock configuration in ARM Cortex-M microcontrollers.

## 🛠️ Hardware Requirements

*   **Microcontroller:** STM32F4 series Development Board (e.g., Nucleo, Discovery). *Note: If using a different STM32 family, memory addresses may need adjustment.*
*   **Input:** Pin `PA0` (requires manually jumping the pin to 3.3V or GND to change its state).
*   **Output:** LED connected to `PA6`.

## 🧠 How It Works (Register Level)

The program directly manipulates the following memory-mapped registers:

1.  **`RCC_AHB1ENR` (Reset and Clock Control):** 
    Enables the clock for the GPIOA peripheral so it can be configured and used.
2.  **`GPIOA_MODER` (GPIO Port Mode Register):** 
    *   Sets `PA6` as a General Purpose Output pin.
    *   Sets `PA0` as an Input pin.
3.  **`GPIOA_IDR` (GPIO Input Data Register):** 
    Reads the current logical state (High/Low) of the `PA0` input pin based on the power level applied to it.
4.  **`GPIOA_ODR` (GPIO Output Data Register):** 
    Sets the output state of `PA6` to either turn the LED on or off based on the `GPIOA_IDR` reading.

## 🚀 Getting Started

### Prerequisites
*   An ARM cross-compiler (e.g., `arm-none-eabi-gcc`).
*   An IDE like STM32CubeIDE, Keil uVision, or a custom Makefile setup.
*   A flashing tool (e.g., STM32 ST-LINK Utility, OpenOCD).

### Installation & Execution
1.  Clone this repository:
    ```bash
    git clone (https://github.com/buntydjoseph-dot/Read-blink-STM32.git)
    ```
2.  Create a new bare-metal project in your preferred IDE for your specific STM32 board.
3.  Replace the auto-generated `main.c` with the `main.c` provided in this repository.
4.  Compile/Build the project.
5.  Flash the compiled binary to your STM32 microcontroller.
6.  Manually apply a HIGH (3.3V) or LOW (GND) signal to `PA0` using a jumper wire and watch the LED on `PA6` react!

## 👤 Author
**Joshva Jonathan Joseph**

## 📄 License
This project is open-source and available under the [MIT License](LICENSE).
