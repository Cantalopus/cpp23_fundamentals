module;

#include<fmt/format.h>
#include<SFML/Graphics.hpp>

export module utilities;

export void bitwise_operations(){
    //Printing Integers in Binary
    unsigned short int data{15};

    fmt::println("data (dec): {0:016d}", data);
    fmt::println("data (oct): {0:016o}", data);
    fmt::println("data (hex): {0:016x}", data);
    fmt::println("data (bin): {0:016b}", data);
}

export void bitwise_shift_operators(){
    //Shift operators
    unsigned short int value{0xff0u};

    fmt::println("Size of short int: {}", sizeof(unsigned short int));
    fmt::println("binary value: {:016b}, decimal value: {}", value, value);

    //Shift left by one bit
    value = static_cast<unsigned short int>(value << 1);
    fmt::println("binary value: {:016b}, decimal value: {}", value, value);

    //Shift left by one bit
    value = static_cast<unsigned short int> (value << 1);
    fmt::println("binary value: {:016b}, decimal value: {}", value, value);

    //Shift left by one bit
    value = static_cast<unsigned short int> (value << 1);
    fmt::println("binary value: {:016b}, decimal value: {}", value, value);

    //Shift left by one bit
    value = static_cast<unsigned short int> (value << 1);
    fmt::println("binary value: {:016b}, decimal value: {}", value, value);

    //Shift left by one bit
    value = static_cast<unsigned short int> (value << 1);
    fmt::println("binary value: {:016b}, decimal value: {}", value, value);

    //Shift left by one bit
    value = static_cast<unsigned short int> (value << 1);
    fmt::println("binary value: {:016b}, decimal value: {}", value, value);

    //Shift left by one bit
    value = static_cast<unsigned short int> (value << 1);
    fmt::println("binary value: {:016b}, decimal value: {}", value, value);

    //Shift left by one bit
    value = static_cast<unsigned short int> (value << 1);
    fmt::println("binary value: {:016b}, decimal value: {}", value, value);

    //Shift left by one bit
    value = static_cast<unsigned short int> (value << 1);
    fmt::println("binary value: {:016b}, decimal value: {}", value, value);

    //Shift left by one bit
    value = static_cast<unsigned short int> (value << 1);
    fmt::println("binary value: {:016b}, decimal value: {}", value, value);

    //Shift right by one bit
    value = static_cast<unsigned short int> (value >> 1);
    fmt::println("binary value: {:016b}, decimal value: {}", value, value);

    //Shift right by one bit
    value = static_cast<unsigned short int>(value >> 1);
    fmt::println("binary value: {:016b}, decimal value: {}", value, value);

    //Shift right by one bit
    value = static_cast<unsigned short int> (value >> 1);
    fmt::println("binary value: {:016b}, decimal value: {}", value, value);

    //Shift right by one bit
    value = static_cast<unsigned short int> (value >> 1);
    fmt::println("binary value: {:016b}, decimal value: {}", value, value);

    //Shift right by one bit
    value = static_cast<unsigned short int> (value >> 1);
    fmt::println("binary value: {:016b}, decimal value: {}", value, value);

    //Shift right by one bit
    value = static_cast<unsigned short int> (value >> 1);
    fmt::println("binary value: {:016b}, decimal value: {}", value, value);

    //Shift rihgt by one bit
    value = static_cast<unsigned short int> (value >> 1);
    fmt::println("binary value: {:016b}, decimal value: {}", value, value);

    //Shift right by one bit
    value = static_cast<unsigned short int> (value >> 1);
    fmt::println("binary value: {:016b}, decimal value: {}", value, value);

}

export void logical_bitwise_operators(){
    //Logical bitwise operators
    unsigned int value1 {0x3}; // 0000 0011
    unsigned int value2 {0x5}; // 0000 0101

    fmt::println("value1: {:032b}", value1);
    fmt::println("value2: {:032b}", value2);

    //Bitwise AND operator
    fmt::println("Bitwise and: ");
    fmt::println("value1 & value2: {:032b}", (value1 & value2));

    //Bitwise OR operator
    fmt::println("Bitwise OR: ");
    fmt::println("value1 | value2: {:032b}", (value1 | value2));

    //Bitwise NOT
    fmt::println("Bitwise NOT: ");
    fmt::println("~value1: {:032b}", ~value1);
    fmt::println("~value2: {:032b}", ~value2);

    //Bitwise XOR
    fmt::println("Bitwise XOR: ");
    fmt::println("value1 ^ value2: {:032b}", (value1 ^ value2));
}

export void compound_bitwise_operators(){
    //Compound bitwise operators
    unsigned int sandbox_var{0b00110100};

    // Print out initial value
    fmt::println("Initial value: ");
    fmt::println("sandbox_var: {:032b}", sandbox_var);

    // Compound left shift
    fmt::println("Shift left 2 bit positions in place: ");
    sandbox_var <<= 2;
    fmt::println("sandbox_var: {:032b}", sandbox_var);

    // Compound right shift
    fmt::println("Shift right 4 bit positions in place: ");
    sandbox_var >>= 4;
    fmt::println("sandbox_var: {:032b}", sandbox_var);

    // Compound OR with 0000 0010 to have all lower 4 bits turned on
    fmt::println("Compound OR with 0000 1101: ");
    sandbox_var |= 0b00001111;
    fmt::println("sandbox_var: {:032b}", sandbox_var);

    // Compound AND with 0000 1100 to have all lower 4 bits turned on
    fmt::println("Compound AND with 0000 1111: ");
    sandbox_var &= 0b00001100;
    fmt::println("sandbox_var: {:032b}", sandbox_var);

    // XOR with 0000 0011 to turn on the 4 lowest bits again
    fmt::println("Compound XOR with 0000 1100: ");
    sandbox_var ^= 0b00000011;
    fmt::println("sandbox_var: {:032b}", sandbox_var);    
    
}

export void masks(){
    //Mask: highlight a bit of interest and turn off all the others
    unsigned int mask_bit_0{0b00000001}; // bit 0
    unsigned int mask_bit_1{0b00000010}; // bit 1
    unsigned int mask_bit_2{0b00000100}; // bit 2
    unsigned int mask_bit_3{0b00001000}; // bit 3
    unsigned int mask_bit_4{0b00010000}; // bit 4
    unsigned int mask_bit_5{0b00100000}; // bit 5
    unsigned int mask_bit_6{0b01000000}; // bit 6
    unsigned int mask_bit_7{0b10000000}; // bit 7

    //Sandbox variable
    unsigned int var {0b00000000};// Starts off all bits off
    fmt::println("var: {:032b}", var);

    //SETTING BITS
    //Setting : |= with mask of the bit

    fmt::println("Turning on bit in position 1");
    var |= mask_bit_1; //Turn on bit in position 1
    fmt::println("var: {:032b}", var);

    //RESETTING BITS : set to 0
    //Resetting : &= (~mask)

    fmt::println("Turning off bit in position 1");
    var &= (~mask_bit_1); //Turn off bit in position 1
    fmt::println("var: {:032b}", var);

    fmt::println("Settinh bit in position 5");
    var |= mask_bit_5;
    fmt::println("var: {:032b}", var);

    //Set all bits
    fmt::println("Setting all bits: ");
    var |= (mask_bit_0 | mask_bit_1 | mask_bit_2 | mask_bit_3 |
            mask_bit_4 | mask_bit_5 | mask_bit_6 | mask_bit_7);
    fmt::println("var: {:032b}", var);
/*
    fmt::println("Reset bits at pos 0, 2, 4, 6: ");
    var &= ~(mask_bit_0 | mask_bit_2 | mask_bit_4 | mask_bit_6);
    fmt::println("var: {:032b}", var);

    //Check state of a bit: & with mask
    fmt::println("Checking the state of each bit position(on/off): ");
    fmt::println("bit0 is {}", static_cast<bool>(var & mask_bit_0));
    fmt::println("bit1 is {}", static_cast<bool>(var & mask_bit_1));
    fmt::println("bit2 is {}", static_cast<bool>(var & mask_bit_2));
    fmt::println("bit3 is {}", static_cast<bool>(var & mask_bit_3));
    fmt::println("bit4 is {}", static_cast<bool>(var & mask_bit_4));
    fmt::println("bit5 is {}", static_cast<bool>(var & mask_bit_5));

    fmt::println("bit6 is {}", static_cast<bool>(var & mask_bit_6));
    fmt::println("bit6 is {}", (var & mask_bit_6) >> 6);

    fmt::println("bit7 is {}", static_cast<bool>(var & mask_bit_7));
  	fmt::println("bit7 is {}", (var & mask_bit_7) >> 7 );

    //Toggle bits
    //Toggle : var ^ mask

    //Toggle bit 0
    fmt::println("Toggle bit 0: ");
  	var ^= mask_bit_0;
  	fmt::println("var: {:032b}", var);

    //Toggle bit7
    fmt::println("Toggle bit 7: ");
  	var ^= mask_bit_7;
  	fmt::println("var: {:032b}", var);

    //Toggle multiple bits in one go : the 4 higher bits
    fmt::println("Toggle multiple bits in one go : the 4 higher bits: ");
  	var ^= (mask_bit_7 | mask_bit_6 | mask_bit_5 | mask_bit_4);
  	fmt::println("var: {:032b}", var);

*/

}

export void window(){

    sf::RenderWindow window(sf::VideoMode{{800,900}}, "Bitwise Operators");

    while(window.isOpen()){
        while(const std::optional<sf::Event> event = window.pollEvent()){
            if(event->is<sf::Event::Closed>())
                window.close();
        }

        

        window.clear();

        

        window.display();
    }
}