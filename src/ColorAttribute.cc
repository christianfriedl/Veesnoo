#include <iostream>
#include <sstream>
#include "Logger.h"
#include "ColorAttribute.h"

namespace nv {

    ColorAttribute::ColorAttribute():
            fg_(COLOR_WHITE), bg_(COLOR_BLACK), inverse_(false), bold_(false), underline_(false), blink_(false), pairNumber_(0)
    {
        pairNumber_ = CursesManager::get().findPair(fg_, bg_);
        if ( pairNumber_ == 0 )
            pairNumber_ = CursesManager::get().colorPair(fg_, bg_);
        if ( pairNumber_ == 0 )
            throw Exception("unable to create color pair");
    }
    ColorAttribute::ColorAttribute(short int fg, short int bg, bool inverse, bool bold, bool underline, bool blink):
            fg_(fg), bg_(bg), inverse_(inverse), bold_(bold), underline_(underline), blink_(blink), pairNumber_(0)
    {
        pairNumber_ = CursesManager::get().findPair(fg_, bg_);
        if ( pairNumber_ == 0 )
            pairNumber_ = CursesManager::get().colorPair(fg_, bg_);
        if ( pairNumber_ == 0 )
            throw Exception("unable to create color pair");
    }
    ColorAttribute::ColorAttribute(const ColorAttribute& other): 
            fg_(other.fg_), bg_(other.bg_), inverse_(other.inverse_), bold_(other.bold_), underline_(other.underline_), blink_(other.blink_), pairNumber_(other.pairNumber_)
    {
    }
    ColorAttribute& ColorAttribute::operator=(const ColorAttribute& other) {
        if ( this != &other ) {
            fg_ = other.fg_;
            bg_ = other.bg_;
            inverse_ = other.inverse_;
            bold_ = other.bold_;
            underline_ = other.underline_;
            blink_ = other.blink_;
            pairNumber_ = other.pairNumber_;
        }
        return *this;
    }
    ColorAttribute::~ColorAttribute() {
    }

    const std::string ColorAttribute::toString() const {
        std::ostringstream ostr;
        ostr << "<ColorPair ";
        ostr << "pairNumber = " << pairNumber_ << ", ";
        ostr << "fg = " << fg_ << ", ";
        ostr << "bg = " << bg_ << ", ";
        ostr << "inverse = " << inverse_ << ", ";
        ostr << "bold = " << bold_ << ", ";
        ostr << "underline = " << underline_ << ", ";
        ostr << "blink = " << blink_;
        ostr << ">";
        return ostr.str();
    }
}
