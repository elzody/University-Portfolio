// If this header file isn't included already, then include it
#ifndef THERMO_HEADERS_THERMOMATH_H_
#define THERMO_HEADERS_THERMOMATH_H_

// Converts ms to µs
unsigned int convert_ms_us(int ms) {
    return ms * 1000;
}

// Converts µs to ms
unsigned int convert_us_ms(unsigned int us) {
    return us / 1000;
}

#endif /* THERMO_HEADERS_THERMOMATH_H_ */
