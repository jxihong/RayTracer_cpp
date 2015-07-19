#ifndef _COLOR_HH_
#define _COLOR_HH_

#include <iostream>
#include <cassert>

class Color {

private:
  float _red;
  float _green;
  float _blue;

public:
  // Constructors
  Color() : _red(0), _green(0), _blue(0) {}                  
  Color(float r, float g, float b) : _red(r), _green(g), _blue(b) {} 
  
  // Destructor
  ~Color() {}
  
  float get_red()   const { return _red; }
  float get_green() const { return _green; }
  float get_blue()  const { return _blue; }
  
  void set_red(float val)   { _red = val; }
  void set_green(float val) { _green = val; }
  void set_blue(float val)  { _blue = val; }
  
  //Compound Assignment Operations
  Color & operator+=(const Color &c);
  Color & operator-=(const Color &c);
  Color & operator*=(const Color &c);
  
  Color & operator*=(float s);
  Color & operator/=(float s);
  
  // Makes sure (r, g, b) are in [0, 1]
  void clamp();

};

// Arithmetic Operations
const Color operator*(const Color &a, const Color &b);
const Color operator+(const Color &a, const Color &b);
const Color operator-(const Color &a, const Color &b);

const Color operator*(const Color &a, float s); 
const Color operator*(float s, const Color &b);
const Color operator/(const Color &a, float s);

std::ostream & operator<<(std::ostream &os, const Color &c);
std::istream & operator>>(std::istream &is, Color &c);

#endif // _COLOR_HH_



