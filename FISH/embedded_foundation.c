/*
 * EMBEDDED SYSTEMS FOUNDATION COURSE
 * ===================================
 * Begin your journey into embedded systems development
 * This covers concepts used in real microcontroller programming
 * 
 * Topics:
 * • Bitwise Operations (AND, OR, XOR, NOT, Shifts)
 * • Bit Manipulation & Bit Flags
 * • Memory Addresses & Pointer Arithmetic
 * • Struct Packing & Memory Layout
 * • Hardware Simulation using Structures
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

// ============================================================
// SECTION 1: BITWISE OPERATIONS FUNDAMENTALS
// ============================================================

void lesson_1_bitwise_basics()
{
    printf("\n=== LESSON 1: Bitwise Operations Basics ===\n");
    
    uint8_t a = 0b1100;  // Binary: 12 in decimal
    uint8_t b = 0b1010;  // Binary: 10 in decimal
    
    printf("a = 0b1100 (%d)\n", a);
    printf("b = 0b1010 (%d)\n\n", b);
    
    // AND (&) - Both bits must be 1
    printf("a & b = 0b1000 (%d)\n", a & b);
    
    // OR (|) - At least one bit must be 1
    printf("a | b = 0b1110 (%d)\n", a | b);
    
    // XOR (^) - Bits must be different
    printf("a ^ b = 0b0110 (%d)\n", a ^ b);
    
    // NOT (~) - Flip all bits
    printf("~a = 0x%02X (all bits flipped)\n", ~a);
    
    // Left Shift (<<) - Multiply by 2^n
    printf("a << 1 = 0b%b (%d) - multiply by 2\n", a << 1, a << 1);
    printf("a << 2 = 0b%b (%d) - multiply by 4\n", a << 2, a << 2);
    
    // Right Shift (>>) - Divide by 2^n
    printf("a >> 1 = 0b%b (%d) - divide by 2\n", a >> 1, a >> 1);
}

// ============================================================
// SECTION 2: BIT MANIPULATION - Setting, Clearing, Toggling
// ============================================================

void lesson_2_bit_manipulation()
{
    printf("\n=== LESSON 2: Bit Manipulation ===\n");
    
    uint8_t reg = 0b00000000;
    printf("Initial register: 0b%b\n\n", reg);
    
    // SET a bit (use OR with mask)
    // To set bit 3: reg |= (1 << 3)
    printf("Setting bit 3:\n");
    reg |= (1 << 3);
    printf("  After: 0b%b\n", reg);
    
    // CLEAR a bit (use AND with inverted mask)
    // To clear bit 3: reg &= ~(1 << 3)
    printf("Clearing bit 3:\n");
    reg &= ~(1 << 3);
    printf("  After: 0b%b\n", reg);
    
    // TOGGLE a bit (use XOR with mask)
    // To toggle bit 1: reg ^= (1 << 1)
    printf("Toggling bit 1:\n");
    reg ^= (1 << 1);
    printf("  After: 0b%b\n", reg);
    
    reg ^= (1 << 1);
    printf("Toggling bit 1 again:\n");
    printf("  After: 0b%b\n\n", reg);
    
    // CHECK if a bit is set
    if (reg & (1 << 1))
        printf("Bit 1 is SET ✓\n");
    else
        printf("Bit 1 is CLEAR ✗\n");
}

// ============================================================
// SECTION 3: BIT FIELD STRUCTURES (like hardware registers)
// ============================================================

/*
 * In embedded systems, hardware registers are often packed bits.
 * We use bit fields to map to them.
 * 
 * Example: GPIO Pin Register (8 bits)
 * Bit 0: Pin Value
 * Bit 1: Pin Direction (0=input, 1=output)
 * Bit 2: Pull-up enabled
 * Bits 3-7: Reserved
 */

typedef struct {
    uint8_t value : 1;      // Bit 0 - Single bit
    uint8_t direction : 1;  // Bit 1 - Single bit
    uint8_t pull_up : 1;    // Bit 2 - Single bit
    uint8_t reserved : 5;   // Bits 3-7 - 5 bits reserved
} GPIO_Pin;

void lesson_3_bit_fields()
{
    printf("\n=== LESSON 3: Bit Field Structures ===\n");
    
    GPIO_Pin pin = {0};
    printf("GPIO Pin structure (simulating hardware register):\n");
    printf("Size: %zu byte(s)\n\n", sizeof(GPIO_Pin));
    
    // Set pin as OUTPUT with pull-up enabled
    pin.direction = 1;  // Output
    pin.pull_up = 1;    // Pull-up enabled
    pin.value = 1;      // High
    
    printf("Configuration:\n");
    printf("  Value: %d\n", pin.value);
    printf("  Direction: %d (1=OUTPUT)\n", pin.direction);
    printf("  Pull-up: %d (1=ENABLED)\n", pin.pull_up);
    printf("  Reserved: %d\n\n", pin.reserved);
    
    // In memory, this occupies just 1 byte!
    printf("Memory layout: 0b%b (as integer)\n", *(uint8_t *)&pin);
}

// ============================================================
// SECTION 4: MEMORY ADDRESSES & POINTERS (Embedded crucial!)
// ============================================================

void lesson_4_memory_addresses()
{
    printf("\n=== LESSON 4: Memory Addresses ===\n");
    
    uint32_t value = 0x12345678;
    uint32_t *ptr = &value;
    
    printf("Value: 0x%08X\n", value);
    printf("Address: %p\n", (void *)ptr);
    printf("Pointer size: %zu bytes\n\n", sizeof(ptr));
    
    // Dereferencing
    printf("Dereferencing pointer: 0x%08X\n", *ptr);
    
    // Pointer arithmetic
    uint32_t array[] = {0x11111111, 0x22222222, 0x33333333};
    printf("\nPointer arithmetic:\n");
    printf("array[0] address: %p -> 0x%08X\n", (void *)&array[0], array[0]);
    printf("array[1] address: %p -> 0x%08X\n", (void *)&array[1], array[1]);
    printf("array[2] address: %p -> 0x%08X\n", (void *)&array[2], array[2]);
    
    printf("\nDifference between consecutive pointers: %zu bytes (sizeof(uint32_t))\n",
           (uint8_t *)&array[1] - (uint8_t *)&array[0]);
}

// ============================================================
// SECTION 5: MEMORY-MAPPED HARDWARE REGISTERS
// ============================================================

/*
 * In embedded systems, hardware is accessed via memory-mapped I/O
 * We create pointers to specific memory addresses where registers exist
 */

typedef struct {
    volatile uint32_t CTRL;    // Control register at offset 0x00
    volatile uint32_t STATUS;  // Status register at offset 0x04
    volatile uint32_t DATA;    // Data register at offset 0x08
} PeripheralRegs;

void lesson_5_memory_mapped_io()
{
    printf("\n=== LESSON 5: Memory-Mapped Hardware Registers ===\n");
    
    // In real embedded systems, you'd do:
    // PeripheralRegs *peripheral = (PeripheralRegs *)0x40000000;
    // This maps to actual hardware at that address
    
    // For simulation:
    uint8_t memory[256];
    memset(memory, 0, sizeof(memory));
    PeripheralRegs *peripheral = (PeripheralRegs *)memory;
    
    printf("Simulating hardware peripheral at memory:\n");
    printf("Base address: %p\n\n", (void *)peripheral);
    
    // Write to registers
    peripheral->CTRL = 0xABCD1234;
    peripheral->STATUS = 0x00000001;
    peripheral->DATA = 0xDEADBEEF;
    
    printf("Registers written:\n");
    printf("  CTRL (offset 0x00): 0x%08X\n", peripheral->CTRL);
    printf("  STATUS (offset 0x04): 0x%08X\n", peripheral->STATUS);
    printf("  DATA (offset 0x08): 0x%08X\n", peripheral->DATA);
    
    printf("\nRegister sizes:\n");
    printf("  sizeof(PeripheralRegs): %zu bytes\n", sizeof(PeripheralRegs));
    printf("  CTRL offset: %zu\n", (uint8_t *)&peripheral->CTRL - (uint8_t *)peripheral);
    printf("  STATUS offset: %zu\n", (uint8_t *)&peripheral->STATUS - (uint8_t *)peripheral);
    printf("  DATA offset: %zu\n", (uint8_t *)&peripheral->DATA - (uint8_t *)peripheral);
}

// ============================================================
// SECTION 6: PRACTICAL - GPIO CONTROL SIMULATION
// ============================================================

typedef struct {
    volatile uint8_t pins;
    volatile uint8_t direction;  // 0 = input, 1 = output
    volatile uint8_t pull_up;
} GPIO_Port;

void gpio_set_pin(GPIO_Port *port, int pin, int state)
{
    if (state)
        port->pins |= (1 << pin);
    else
        port->pins &= ~(1 << pin);
}

int gpio_read_pin(GPIO_Port *port, int pin)
{
    return (port->pins >> pin) & 1;
}

void gpio_set_direction(GPIO_Port *port, int pin, int dir)
{
    if (dir)
        port->direction |= (1 << pin);
    else
        port->direction &= ~(1 << pin);
}

void lesson_6_gpio_simulation()
{
    printf("\n=== LESSON 6: GPIO Control Simulation ===\n");
    
    // Create virtual GPIO port
    GPIO_Port portA = {0, 0, 0};
    
    // Configure pins
    printf("Configuring pins:\n");
    gpio_set_direction(&portA, 0, 1);  // Pin 0 as output
    gpio_set_direction(&portA, 1, 1);  // Pin 1 as output
    gpio_set_direction(&portA, 2, 0);  // Pin 2 as input
    
    printf("  Pin 0: OUTPUT\n");
    printf("  Pin 1: OUTPUT\n");
    printf("  Pin 2: INPUT\n");
    
    // Control outputs
    printf("\nControlling outputs:\n");
    gpio_set_pin(&portA, 0, 1);
    printf("  Pin 0 set HIGH: %d\n", gpio_read_pin(&portA, 0));
    
    gpio_set_pin(&portA, 1, 0);
    printf("  Pin 1 set LOW: %d\n", gpio_read_pin(&portA, 1));
    
    printf("\nPort state:\n");
    printf("  PINS register: 0b%b\n", portA.pins);
    printf("  DIRECTION register: 0b%b (1=output)\n", portA.direction);
}

// ============================================================
// SECTION 7: REGISTER BITFIELD MACROS
// ============================================================

// These are real patterns used in embedded development

#define REG_SETBIT(reg, bit)        ((reg) |= (1 << (bit)))
#define REG_CLEARBIT(reg, bit)      ((reg) &= ~(1 << (bit)))
#define REG_TOGGLEBIT(reg, bit)     ((reg) ^= (1 << (bit)))
#define REG_CHECKBIT(reg, bit)      (((reg) >> (bit)) & 1)
#define REG_SETMASK(reg, mask)      ((reg) |= (mask))
#define REG_CLEARMASK(reg, mask)    ((reg) &= ~(mask))

void lesson_7_register_macros()
{
    printf("\n=== LESSON 7: Register Manipulation Macros ===\n");
    
    uint8_t status_reg = 0b00000000;
    
    printf("Initial: 0b%b\n\n", status_reg);
    
    printf("Setting bit 3:\n");
    REG_SETBIT(status_reg, 3);
    printf("  Result: 0b%b\n", status_reg);
    
    printf("Toggling bit 1:\n");
    REG_TOGGLEBIT(status_reg, 1);
    printf("  Result: 0b%b\n", status_reg);
    
    printf("Checking if bit 3 is set: %d\n", REG_CHECKBIT(status_reg, 3));
    printf("Checking if bit 7 is set: %d\n", REG_CHECKBIT(status_reg, 7));
    
    printf("\nClearing all bits with mask 0b1000:\n");
    REG_CLEARMASK(status_reg, 0b1000);
    printf("  Result: 0b%b\n", status_reg);
}

// ============================================================
// SECTION 8: CHALLENGE - Timer Register Simulation
// ============================================================

typedef struct {
    volatile uint16_t count;
    volatile uint16_t max;
    volatile uint8_t control;  // Bit 0: enabled, Bit 1: interrupt
} TimerReg;

void timer_init(TimerReg *timer, uint16_t max_value)
{
    timer->count = 0;
    timer->max = max_value;
    timer->control = 0;
}

void timer_start(TimerReg *timer)
{
    REG_SETBIT(timer->control, 0);
}

void timer_stop(TimerReg *timer)
{
    REG_CLEARBIT(timer->control, 0);
}

void timer_tick(TimerReg *timer)
{
    if (REG_CHECKBIT(timer->control, 0))
    {
        timer->count++;
        if (timer->count >= timer->max)
        {
            REG_SETBIT(timer->control, 1);  // Set interrupt flag
            timer->count = 0;
        }
    }
}

void lesson_8_timer_simulation()
{
    printf("\n=== LESSON 8: Challenge - Timer Register Simulation ===\n");
    
    TimerReg timer;
    timer_init(&timer, 5);
    
    printf("Timer initialized (max: 5 ticks)\n");
    printf("Starting timer...\n\n");
    timer_start(&timer);
    
    for (int i = 0; i < 12; i++)
    {
        timer_tick(&timer);
        printf("Tick %2d: count=%2d, interrupt=%d\n",
               i + 1, timer.count, REG_CHECKBIT(timer.control, 1));
        
        if (REG_CHECKBIT(timer.control, 1))
        {
            printf("         >>> INTERRUPT! Timer reached max\n");
            REG_CLEARBIT(timer.control, 1);  // Clear interrupt
        }
    }
}

// ============================================================
// SECTION 9: DATA TYPES FOR EMBEDDED
// ============================================================

void lesson_9_data_types()
{
    printf("\n=== LESSON 9: Embedded Data Types ===\n");
    
    printf("Standard C types:\n");
    printf("  char:        %zu bytes (%d to %d)\n", sizeof(char), -128, 127);
    printf("  short:       %zu bytes\n", sizeof(short));
    printf("  int:         %zu bytes\n", sizeof(int));
    printf("  long:        %zu bytes\n", sizeof(long));
    printf("  float:       %zu bytes\n", sizeof(float));
    printf("  double:      %zu bytes\n\n", sizeof(double));
    
    printf("Fixed-width types (stdint.h):\n");
    printf("  uint8_t:     %zu bytes (0 to 255)\n", sizeof(uint8_t));
    printf("  int8_t:      %zu bytes (-128 to 127)\n", sizeof(int8_t));
    printf("  uint16_t:    %zu bytes (0 to 65535)\n", sizeof(uint16_t));
    printf("  int16_t:     %zu bytes (-32768 to 32767)\n", sizeof(int16_t));
    printf("  uint32_t:    %zu bytes (0 to 4294967295)\n", sizeof(uint32_t));
    printf("  int32_t:     %zu bytes\n\n", sizeof(int32_t));
    
    printf("Why fixed-width types matter in embedded:\n");
    printf("  • Consistency across different architectures\n");
    printf("  • Predictable memory layout\n");
    printf("  • Easy hardware register mapping\n");
}

// ============================================================
// MAIN MENU
// ============================================================

int main()
{
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║         EMBEDDED SYSTEMS FOUNDATION COURSE                 ║\n");
    printf("║        Learn the fundamentals before microcontrollers     ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");
    
    lesson_1_bitwise_basics();
    lesson_2_bit_manipulation();
    lesson_3_bit_fields();
    lesson_4_memory_addresses();
    lesson_5_memory_mapped_io();
    lesson_6_gpio_simulation();
    lesson_7_register_macros();
    lesson_8_timer_simulation();
    lesson_9_data_types();
    
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║        🎓 FOUNDATION COMPLETE! Ready for: 🎓              ║\n");
    printf("║                                                            ║\n");
    printf("║  NEXT: Microcontroller Programming (Arduino/STM32/ESP32)  ║\n");
    printf("║                                                            ║\n");
    printf("║  Recommended Path:                                        ║\n");
    printf("║  1. Start with Arduino (easiest)                          ║\n");
    printf("║  2. Move to STM32 (professional)                          ║\n");
    printf("║  3. Then ESP32 (IoT/Wireless)                             ║\n");
    printf("║                                                            ║\n");
    printf("║  Key projects to practice:                                ║\n");
    printf("║  • LED blink with GPIO                                    ║\n");
    printf("║  • Button reading with interrupts                         ║\n");
    printf("║  • PWM LED brightness control                             ║\n");
    printf("║  • UART serial communication                              ║\n");
    printf("║  • I2C/SPI sensor reading                                 ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n\n");
    
    return 0;
}
