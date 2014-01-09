/* 
 * File:   ColorRGB.h
 * Author: Denys_Viliuzhanin
 *
 * Created on January 9, 2014, 7:01 PM
 */

#ifndef COLORRGB_H
#define	COLORRGB_H

#include <iostream>

class ColorRGB {
public:
    typedef  unsigned char uint8;
public:
    ColorRGB(uint8 red, uint8 green, uint8 blue);
    ColorRGB(const ColorRGB& orig);
    virtual ~ColorRGB();
    
    bool isLess(const ColorRGB& other) const;
    bool isGreater(const ColorRGB& other) const;
    bool isEqual(const ColorRGB& other) const;
    bool isNotEqual(const ColorRGB& other) const;
    
    std::ostream& toStream(std::ostream& stream) const;
    
     
private:
    uint8 red;
    uint8 green;
    uint8 blue;
};

std::ostream& operator<< (std::ostream& stream, const ColorRGB& color) {
    return color.toStream(stream);
}

#endif	/* COLORRGB_H */

