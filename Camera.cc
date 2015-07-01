#include "Camera.hh"

using namespace std;

Camera::Camera(const Vector3F &pos, const Vector3F &look_at, const Vector3F &up, float fov)
    : _pos(pos), _fov(fov) {

  //The camera's direction vector simply becomes the 
  //difference between the look-at position and the camera's position, normalized
  
  _dir = look_at - _pos;
  _dir.normalize();
  
  //cameraRight = direction × up (using right-hand rule)
  
  _cameraRight = cross(_dir, up);
  _cameraRight.normalize();
  
  //cameraUp = cameraRight × direction (using right-hand rule)
  
  _cameraUp = cross(_cameraRight, _dir);
  _cameraUp.normalize();
    
  //dist = 0.5 / tan(fov / 2)
  
  _dist = 0.5 / tanf(_fov / 2);
    
  _valid = true;
}

Ray Camera::getRayForPixel(int x, int y, int imgSize) const {
  assert(_valid);
  assert(x >= 0 && x < imgSize);
  assert(y >= 0 && y < imgSize);
    
  // dist = distance between camera location and the grid of pixels, as
  // computed earlier.  direction = normalized camera direction vector.
  
  Vector3F pixelDir = ((_dist * _dir) +
		       ((0.5f - (float) y / (float) (imgSize - 1)) * _cameraUp) +
		       (((float) x / (float) (imgSize - 1) - 0.5f) * _cameraRight));

  Ray pixelRay(_pos, pixelDir);
  return pixelRay;
}


// Read input as (p_x, p_y, p_z) (l_x, l_y, l_z) (u_x, u_y, u_z)
Camera ReadCamera(istream &is) {
  Camera cam; 

  if (!is) return cam;
  
  Vector3F p;
  Vector3F d;
  Vector3F u;

  is >> p;
  is >> d;
  is >> u;

  if (is){
    cam = Camera(p, d, u);
  }
  
  return cam;
}















