#ifndef _LIGHT_HH_
#define _LIGHT_HH_

#include "Vector3.hh"
#include "Color.hh"

#include <boost/shared_ptr.hpp>

class Light {

private:

  Vector3F _pos; // position
  Color _color;

public:
  // Constructors
  Light() : _pos() , _color() {}                  
  Light(const Vector3F &p, const Color &c) : _pos(p) , _color(c) {}
  
  // Destructor
  ~Light() {}
  
  Vector3F get_position() const { return _pos; }
  Color get_color() const { return _color; }
};

//# Boost Shared Pointer for Light
typedef boost::shared_ptr<Light> SPLight;

SPLight ReadLight(std::istream &is);

#endif // _LIGHT_HH_
