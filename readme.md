# Microcontroller Class Repository

Welcome to the repository for my microcontroller classes. This repository contains numerous small sketches used throughout the course, designed to help students grasp both fundamental and advanced concepts in microcontroller programming.

## Course Overview

### Introduction to Microcontrollers

Although I encourage my students to explore other microcontrollers like the ESP32 or STM32 series, the ATmega328P — commonly known as the Arduino — is perfectly suited for beginners. With 135 minutes of class time per week, it’s challenging to achieve a deep understanding of microcontrollers. The ATmega328P is a straightforward microcontroller with about 300 pages of internal documentation (excluding the instruction set), making it accessible for new learners.

### Course Structure

#### Part 1: Fundamentals

The first part of the course is not heavily microcontroller-specific. It covers:
- Bit operations
- Two's complement representation
- Internal data representation

#### Part 2: Register-Level Programming

In the second part, we focus on register-level programming, which is crucial for:
- Understanding microcontroller architecture
- Utilizing sensors without relying on external libraries

#### Part 3: Interrupt-Based Programming

The third part introduces interrupt-based programming. We start with:
- Simple hardware interrupts
- Timer interrupts, primarily for PWM purposes

#### Part 4: SPI Bus

Finally, we delve into one of the most important bus systems for microcontrollers: the SPI bus. I have chosen SPI over I2C because I already teach I2C in another class, and I aim to avoid overlap for students enrolled in both courses. In this section, we:
- Use the microcontroller as both SPI master and SPI slave
- Explore the differences between SPI burst mode and SPI daisy chain mode

## Using the Repository

Feel free to explore the sketches and use them as a reference or starting point for your projects. This repository is designed to support your learning journey and provide practical examples to reinforce theoretical concepts discussed in class.

Happy coding!
Bernd Donner
