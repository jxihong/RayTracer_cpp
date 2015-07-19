#ifndef _CAMERA_HH_
#define _CAMERA_HH_

#include "Vector3.hh"
#include "Color.hh"
#include "Ray.hh"

#include <cassert>
#include <cmath>

const float pi = 3.14159;

class Camera {

private:

  Vector3F _pos;          // position
  Vector3F _dir;          // direction (normalized)
  Vector3F _cameraUp;     // (normalized)
  Vector3F _cameraRight;  // (normalized)
  
  float _fov;             // the horizontal viewing angle of the camera(degree)
  float _dist;            // distance
  
  bool _valid;

public:
  // Constructors   
  Camera() :  _valid(false) {}           
  
  Camera(const Vector3F &pos, const Vector3F &look_at, const Vector3F &up, float fov = pi / 3);
  
  // Destructor
  ~Camera() {}
  
  //# we will assume that the image has the same width and height
  Ray getRayForPixel(int x, int y, int imgSize) const;
  
  bool valid() { return _valid; }
};

Camera ReadCamera(std::istream &is);

#endif // _CAMERA_HH_
