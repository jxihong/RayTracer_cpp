#ifndef _RAY_HH_
#define _RAY_HH_

#include "Vector3.hh"
#include <cassert>

class Ray {

private:

  Vector3F _orig;
  Vector3F _dir;

public:
  // Constructors
  Ray() : _orig() , _dir() {}                  
  Ray(const Vector3F &orig, const Vector3F &dir, bool normalize = true);
  
  // Destructor
  ~Ray() {}
  
  Vector3F get_origin()   const { return _orig; }
  Vector3F get_direction() const { return _dir; }
  
  // Returns the point for a particular t value
  Vector3F getPointAtT(float t) const;
  
  // Reflect ray off of position with surface normal
  Ray reflect(const Vector3F &p, const Vector3F &n, float DELTA = 0.0001) const;
};

#endif // _RAY_HH_









