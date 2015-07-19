#include "../include/Color.hh"

using namespace std;

Color & Color::operator+=(const Color &c)
{
  if (this != &c) {
    _red   += c._red;
    _green += c._green;
    _blue  += c._blue;
  }
  return *this;
}

Color & Color::operator-=(const Color &c)
{
  if (this != &c) {
    _red   -= c._red;
    _green -= c._green;
    _blue  -= c._blue;
  }
  return *this;
}

Color & Color::operator*=(const Color &c)
{
  if (this != &c) {
    _red   *= c._red;
    _green *= c._green;
    _blue  *= c._blue;
  }
  return *this;
}

Color & Color::operator*=(float s)
{
    _red   *= s;
    _green *= s;
    _blue  *= s;
    
    return *this;
}

Color & Color::operator/=(float s)
{
    assert(s != 0);

    _red   /= s;
    _green /= s;
    _blue  /= s;
    
    return *this;
}

void Color::clamp()
{
  _red   = (_red   < 0) ? 0 : ((_red   > 1) ? 1 : _red);
  _green = (_green < 0) ? 0 : ((_green > 1) ? 1 : _green);
  _blue  = (_blue  < 0) ? 0 : ((_blue  > 1) ? 1 : _blue);
}

const Color operator*(const Color &a, const Color &b)
{
  return Color(a) *= b;
}

const Color operator+(const Color &a, const Color &b)
{
  return Color(a) += b;
}

const Color operator-(const Color &a, const Color &b)
{
  return Color(a) -= b;
}

// Color / scalar
const Color operator/(const Color &a, float s)
{
    assert(s != 0);

    return Color(a) /= s;
}

// Color * scalar
const Color operator*(const Color &a, float s)
{
  return Color(a) *= s;
}

// scalar * Color
const Color operator*(float s, const Color &b)
{
  return Color(b) *= s;
}

// Ouput as [r, g, b]
std::ostream & operator<<(std::ostream &os, const Color &c)
{ 
    os  << "[" << c.get_red() << ", "
	<< c.get_green() << ", " 
	<< c.get_blue() << "]"; 
    return os; 
} 

// Read input as [r, g, b]
std::istream & operator>>(std::istream &is, Color &c)
{
    float values[3];
   
    char ch;
    
    if(!is)  return is;
    
    is >> ch;
    if(ch != '[') is.clear(std::ios_base::failbit);
    
    // [r,g,b]
    for (int i = 0; i < 3; i++) {
      is >> values[i] >> ch;
      
      if ((i < 2 && ch != ',') || (i == 2 && ch != ']')) {
	is.clear(ios_base::failbit);
      }
    }

    if(is){
        c = Color(values[0], values[1], values[2]);
    }

    return is;
}


