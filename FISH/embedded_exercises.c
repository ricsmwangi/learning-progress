/*
 * EMBEDDED SYSTEMS PRACTICE EXERCISES
 * ===================================
 * Solve these problems to master embedded C concepts
 * Then check solutions at the bottom
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

// ============================================================
// EXERCISE 1: Bit Manipulation Basics
// ============================================================

/*
PROBLEM 1.1: Given a register value, write code to:
a) Set bit 5
b) Clear bit 3  
c) Toggle bit 7
d) Check if bit 2 is set

Register value: 0b10101010

Expected output after each operation:
a) After setting bit 5: 0b10111010
b) After clearing bit 3: 0b10110010
c) After toggling bit 7: 0b00110010
d) Bit 2 is: [check result]
*/

void exercise_1_1()
{
    printf("\n=== EXERCISE 1.1: Basic Bit Operations ===\n");
    
    uint8_t reg = 0b10101010;
    printf("Initial register: 0b%b\n", reg);
    
    // a) Set bit 5
    reg |= (1 << 5);
    printf("a) After setting bit 5: 0b%b\n", reg);
    
    // b) Clear bit 3
    reg &= ~(1 << 3);
    printf("b) After clearing bit 3: 0b%b\n", reg);
    
    // c) Toggle bit 7
    reg ^= (1 << 7);
    printf("c) After toggling bit 7: 0b%b\n", reg);
    
    // d) Check bit 2
    printf("d) Bit 2 is: %d\n", (reg >> 2) & 1);
}

// ============================================================
// EXERCISE 2: LED Control Simulation
// ============================================================

/*
PROBLEM 2: Simulate an 8-pin LED port
- Pins 0-3: LEDs (0=OFF, 1=ON)
- Pins 4-7: LED brightness (0=off, 1=25%, 2=50%, 3=75%, 4=100%)

Write functions:
- turn_led_on(pin)
- turn_led_off(pin)
- set_brightness(pin, level)
- is_led_on(pin)

Test with LED 0 on and LED 1 at 75% brightness
*/

typedef struct {
    uint8_t leds;         // Bits 0-3: LED on/off
    uint8_t brightness;   // Brightness register for LED control
} LEDPort;

void turn_led_on(LEDPort *port, int led)
{
    port->leds |= (1 << led);
}

void turn_led_off(LEDPort *port, int led)
{
    port->leds &= ~(1 << led);
}

int is_led_on(LEDPort *port, int led)
{
    return (port->leds >> led) & 1;
}

void exercise_2()
{
    printf("\n=== EXERCISE 2: LED Control ===\n");
    
    LEDPort portA = {0};
    
    // Turn on LED 0
    turn_led_on(&portA, 0);
    printf("LED 0 state: %d (1=ON)\n", is_led_on(&portA, 0));
    
    // Turn on LED 1
    turn_led_on(&portA, 1);
    printf("LED 1 state: %d (1=ON)\n", is_led_on(&portA, 1));
    
    // Turn off LED 0
    turn_led_off(&portA, 0);
    printf("After turning off LED 0: %d (0=OFF)\n", is_led_on(&portA, 0));
    
    printf("Port state: 0b%b\n", portA.leds);
}

// ============================================================
// EXERCISE 3: Hardware Register Simulation
// ============================================================

/*
PROBLEM 3: Simulate a UART (serial communication) peripheral
Structure:
- TX_READY bit (bit 0): 1 when ready to send
- RX_READY bit (bit 1): 1 when data available
- TX_EMPTY bit (bit 2): 1 when transmit buffer empty
- RX_OVERFLOW bit (bit 3): 1 when receive buffer overflow

Implement:
- is_tx_ready(status)
- is_rx_ready(status)
- check_and_clear_overflow(status)
*/

#define TX_READY       (1 << 0)
#define RX_READY       (1 << 1)
#define TX_EMPTY       (1 << 2)
#define RX_OVERFLOW    (1 << 3)

int is_tx_ready(uint8_t status)
{
    return (status & TX_READY) != 0;
}

int is_rx_ready(uint8_t status)
{
    return (status & RX_READY) != 0;
}

int check_and_clear_overflow(uint8_t *status)
{
    if (*status & RX_OVERFLOW)
    {
        *status &= ~RX_OVERFLOW;  // Clear overflow bit
        return 1;
    }
    return 0;
}

void exercise_3()
{
    printf("\n=== EXERCISE 3: UART Register Simulation ===\n");
    
    uint8_t uart_status = TX_READY | TX_EMPTY | RX_OVERFLOW;
    printf("Initial status: 0b%b\n", uart_status);
    
    printf("TX Ready: %d\n", is_tx_ready(uart_status));
    printf("RX Ready: %d\n", is_rx_ready(uart_status));
    
    if (check_and_clear_overflow(&uart_status))
        printf("Overflow cleared!\n");
    
    printf("Status after clearing overflow: 0b%b\n", uart_status);
}

// ============================================================
// EXERCISE 4: Bit Mask Operations
// ============================================================

/*
PROBLEM 4: Given a configuration register, implement:

Config register bit layout:
Bits 0-2: Mode (0=standby, 1=active, 2=idle, 3=error)
Bits 3-4: Speed (0=slow, 1=medium, 2=fast, 3=turbo)
Bit 5: Interrupt enable
Bit 6: Debug mode
Bit 7: Power on

Functions:
- set_mode(reg, mode)
- set_speed(reg, speed)
- enable_interrupt(reg)
- set_power(reg, on/off)
*/

uint8_t set_mode(uint8_t reg, uint8_t mode)
{
    reg &= ~(0x7);  // Clear bits 0-2
    reg |= (mode & 0x7);
    return reg;
}

uint8_t set_speed(uint8_t reg, uint8_t speed)
{
    reg &= ~(0x3 << 3);  // Clear bits 3-4
    reg |= ((speed & 0x3) << 3);
    return reg;
}

uint8_t enable_interrupt(uint8_t reg)
{
    reg |= (1 << 5);
    return reg;
}

uint8_t set_power(uint8_t reg, int on)
{
    if (on)
        reg |= (1 << 7);
    else
        reg &= ~(1 << 7);
    return reg;
}

void exercise_4()
{
    printf("\n=== EXERCISE 4: Bit Mask Operations ===\n");
    
    uint8_t config = 0x00;
    
    config = set_mode(config, 1);           // Active mode
    config = set_speed(config, 2);          // Fast speed
    config = enable_interrupt(config);      // Enable interrupt
    config = set_power(config, 1);          // Power on
    
    printf("Configuration register: 0x%02X (0b%b)\n", config, config);
    
    // Verify settings
    printf("Mode: %d\n", config & 0x7);
    printf("Speed: %d\n", (config >> 3) & 0x3);
    printf("Interrupt enabled: %d\n", (config >> 5) & 1);
    printf("Power on: %d\n", (config >> 7) & 1);
}

// ============================================================
// EXERCISE 5: String & Embedded Combination
// ============================================================

/*
PROBLEM 5: Create a command parser for embedded system
Commands:
- "LED_ON X" - Turn on LED X
- "LED_OFF X" - Turn off LED X
- "STATUS" - Show port status

Parse the command and execute it
*/

void parse_command(char *cmd, LEDPort *port)
{
    if (strncmp(cmd, "LED_ON", 6) == 0)
    {
        int pin = atoi(cmd + 7);  // Parse the number after "LED_ON "
        turn_led_on(port, pin);
        printf("LED %d turned ON\n", pin);
    }
    else if (strncmp(cmd, "LED_OFF", 7) == 0)
    {
        int pin = atoi(cmd + 8);
        turn_led_off(port, pin);
        printf("LED %d turned OFF\n", pin);
    }
    else if (strcmp(cmd, "STATUS") == 0)
    {
        printf("LED Port Status: 0b%b\n", port->leds);
    }
    else
    {
        printf("Unknown command\n");
    }
}

void exercise_5()
{
    printf("\n=== EXERCISE 5: Command Parser ===\n");
    
    LEDPort port = {0};
    
    // Simulate command input
    char commands[][20] = {
        "LED_ON 0",
        "LED_ON 2",
        "STATUS",
        "LED_OFF 0",
        "STATUS"
    };
    
    for (int i = 0; i < 5; i++)
    {
        printf("Command: %s -> ", commands[i]);
        parse_command(commands[i], &port);
    }
}

// ============================================================
// EXERCISE 6: Timer Register Challenge
// ============================================================

/*
PROBLEM 6: Implement a PWM (Pulse Width Modulation) simulation

PWM Register bits:
Bits 0-3: Frequency (0=1kHz, 1=5kHz, 2=10kHz, 3=20kHz)
Bits 4-7: Duty cycle (0-15 represents 0-100%)

Set frequency to 10kHz and duty cycle to 50%
*/

typedef struct {
    uint8_t freq_duty;
} PWMReg;

void set_pwm_freq(PWMReg *pwm, uint8_t freq)
{
    pwm->freq_duty &= 0xF0;  // Clear bits 0-3
    pwm->freq_duty |= (freq & 0xF);
}

void set_pwm_duty(PWMReg *pwm, uint8_t duty)
{
    pwm->freq_duty &= 0x0F;  // Clear bits 4-7
    pwm->freq_duty |= ((duty & 0xF) << 4);
}

void exercise_6()
{
    printf("\n=== EXERCISE 6: PWM Simulation ===\n");
    
    PWMReg pwm = {0};
    
    set_pwm_freq(&pwm, 2);    // 10 kHz
    set_pwm_duty(&pwm, 8);    // 50% (8/16)
    
    printf("PWM Register: 0x%02X\n", pwm.freq_duty);
    printf("Frequency: %d kHz\n", (1 << (pwm.freq_duty & 0xF)));
    printf("Duty Cycle: %d%%\n", ((pwm.freq_duty >> 4) * 100) / 16);
}

// ============================================================
// MAIN - Run all exercises
// ============================================================

int main()
{
    printf("\n╔════════════════════════════════════════════════════════════╗\n");
    printf("║     EMBEDDED SYSTEMS PRACTICE EXERCISES                   ║\n");
    printf("║  Test your understanding of bitwise and register ops      ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");
    
    exercise_1_1();
    exercise_2();
    exercise_3();
    exercise_4();
    exercise_5();
    exercise_6();
    
    printf("\n╔════════════════════════════════════════════════════════════╗\n");
    printf("║  EXERCISES COMPLETE! Ready for microcontroller coding    ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    return 0;
}
