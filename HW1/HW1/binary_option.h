#ifndef binary_option_h
#define binary_option_h
#include "option.h"

class BinaryOption: public Option {
public:
    BinaryOption() { }
    BinaryOption(Date expiration, double strike,
                 OptionType type) : Option(expiration, strike, type) { }
    virtual double price();
};

#endif /* binary_option_h */
