/* 
 * File:   ColorRGB.cpp
 * Author: Denys_Viliuzhanin
 * 
 * Created on January 9, 2014, 7:01 PM
 */

#include "ColorRGB.h"

ColorRGB::ColorRGB(uint8 r, uint8 g, uint8 b): 
        red(r), green(g), blue(b) {
    
}

ColorRGB::ColorRGB(const ColorRGB& orig): 
        red(orig.red), green(orig.green), blue(orig.blue) {
    
}

ColorRGB::~ColorRGB() {
}

bool ColorRGB::isLess(const ColorRGB& other) const {
    return true;
}

bool ColorRGB::isGreater(const ColorRGB& other) const {
    return true;
}

bool ColorRGB::isEqual(const ColorRGB& other) const {
    return true;
}

bool ColorRGB::isNotEqual(const ColorRGB& other) const {
    return true;
}
    
    
std::ostream& ColorRGB::toStream(std::ostream& stream) const {
    stream<<"["<<int(red)<<","<<int(green)<<","<<int(blue);
    return stream;
}
