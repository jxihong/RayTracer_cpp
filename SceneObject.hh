#ifndef _SCENEOBJECT_HH_
#define _SCENEOBJECT_HH_

#include "Vector3.hh"
#include "Color.hh"
#include "Ray.hh"

#include <boost/shared_ptr.hpp>

const Color default_color(0.5, 0.5, 0.5); // grey 

class SceneObject {

private:
  Color _surface_color;
  float _ref; // surface reflectivity

public:
  // Constructors
  SceneObject(const Color &c = default_color, float r = 0) : _surface_color(c), _ref(r) {} 
  
  // Destructor
  virtual ~SceneObject() {}
  
  Color get_surface_color() const { return _surface_color; }
  void set_surface_color(const Color &c) { _surface_color = c; }
  
  float get_surface_reflectivity() { return _ref; }
  
  // If an intersection has occurred, the function return the lowest t value for the intersection
  // If no intersection occurred, return "invalid" value (t = -1)
  virtual float intersection(const Ray &r) const = 0;
  
  // This function will be used when an intersection occurs
  // the argument should be a point which is assumed to be on the surface of the object
  // the return-value is a surface normal for that point
  virtual Vector3F surface_normal(const Vector3F &point) const = 0;
  
  // Returns the color of a point on an object
  virtual Color point_color(const Vector3F &point) {return _surface_color;}
};

// Boost Shared Pointer for SceneObject
typedef boost::shared_ptr<SceneObject> SPSceneObject;

// Function Pointer that Reads SceneObjects 
typedef SPSceneObject (*SceneObjectReader)(std::istream &is);


#endif // _SCENEOBJECT_HH_
