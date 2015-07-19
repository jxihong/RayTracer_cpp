#ifndef _PLANEOBJECT_HH_
#define _PLANEOBJECT_HH_

#include "SceneObject.hh"
#include "Ray.hh"

class PlaneObject : public SceneObject {

private:
  Vector3F _normal; //surface normal
  float _dis;

public:
  // Constructors
  PlaneObject() : SceneObject(), _normal(), _dis(0) {}                  
  PlaneObject(float dis, const Vector3F &normal, const Color &c = default_color, float reflectivity = 0) 
  : SceneObject(c, reflectivity), _normal(normal) , _dis(dis) 
  {_normal.normalize();} 
  
  // Destructor
  ~PlaneObject() {}
  
  Vector3F get_surface_normal() const { return _normal; }
  float get_distance() const { return _dis; }
  
  float intersection(const Ray &r) const;
  
  Vector3F surface_normal(const Vector3F &point) const {return _normal;}
};

SPSceneObject ReadPlane(std::istream &is);


#endif // _PLANEOBJECT_HH_
