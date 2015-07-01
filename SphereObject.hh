#ifndef _SPHEREOBJECT_HH_
#define _SPHEREOBJECT_HH_

#include "SceneObject.hh"
#include "Ray.hh"

#include <cmath>          

class SphereObject : public SceneObject {

private:
  Vector3F _center;
  float _radius;

public:
  // Constructors
  SphereObject() : SceneObject(), _center(), _radius(0) {}                  
  SphereObject(float r, const Vector3F &center, const Color &c = default_color, float reflectivity = 0) 
  : SceneObject(c, reflectivity), _center(center) , _radius(r) {} 
  
  // Destructor
  ~SphereObject() {}
  
  Vector3F get_center() const { return _center; }
  float get_radius() const { return _radius; }
  
  float intersection(const Ray &r) const;
  
  Vector3F surface_normal(const Vector3F &point) const;
  
  //helper functions
  
  // Return the total number of valid intersections (0, 1, or 2)
  // Set t1 and t2 to the t-values of the intersection points, or to your "no intersection" value
  // When there are two valid intersection points, store the smaller one in t1
  // When there is only one valid intersection point, always store it in t1, and set t2 to "no intersection"
  // When there are no valid intersection points, set both t1 and t2 to "no intersection" before returning 0
  int getIntersections(const Ray &r, float &t1, float &t2) const;
};

SPSceneObject ReadSphere(std::istream &is);


#endif // _SPHEREOBJ_HH_
