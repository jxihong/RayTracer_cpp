#ifndef _CYLINDEROBJECT_HH_
#define _CYLINDEROBJECT_HH_

#include "SphereObject.hh"
#include "SceneObject.hh"
#include "Ray.hh"

#include <cmath>           

class CylinderObject : public SceneObject {

private:
  Vector3F _center;     // center of the cylinder
  Vector3F _axis;       // orientation of the cylinder's long axis.
  float _radius;
  float _height;

public:
  // Constructors
  CylinderObject() : SceneObject(), _center(), _axis(), _radius(0), _height(0) {}                  
  CylinderObject(float r, float h, const Vector3F &center, const Vector3F &axis, 
                 const Color &c = default_color, float reflectivity = 0) 
  : SceneObject(c, reflectivity), _center(center) , _axis(axis), _radius(r), _height(h) 
    { _axis.normalize();} 
  
  // Destructor
  ~CylinderObject() {}
  
  Vector3F get_center() const {return _center;}
  float get_radius() const {return _radius;}
  
  float intersection(const Ray &r) const;
  
  Vector3F surface_normal(const Vector3F &point) const;
  
  // helper functions
  int getIntersections(const Ray &r, float &t1, float &t2) const;
  
};

SPSceneObject ReadCylinder(std::istream &is);


#endif // _CYLINDEROBJECT_HH_
