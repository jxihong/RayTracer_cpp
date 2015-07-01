#ifndef _SCENE_HH_
#define _SCENE_HH_

#include "CylinderObject.hh"
#include "SphereObject.hh"
#include "SceneObject.hh"
#include "PlaneObject.hh"
#include "Vector3.hh"
#include "Camera.hh"
#include "Color.hh"
#include "Light.hh"
#include "Ray.hh"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>
#include <cassert>
#include <stdexcept>
#include <vector>
#include <string>
#include <limits>
#include <cmath>
#include <map>

class Scene {

private:
  std:: vector<SPSceneObject> _objects;
  std::vector<SPLight> _lights;
  
  // helper functions
 
  // takes a ray and returns the closest scene object and time of intersection
  SPSceneObject findClosestObject(const Ray &r, float &tIntersect) const;
  Color colorAtPoint(SPSceneObject obj, const Vector3F &pIntersect) const;

public:
  // Constructors
  Scene() : _objects() , _lights() {}                  
  
  // Destructor
  ~Scene() {}
  
  void add_object(SPSceneObject obj);
  void add_light(SPLight l);
  
  //# traces a ray in the scene to see what the color for that ray should be
  Color traceRay(const Ray &r, int depth = 10) const;
  
  void render(std::ostream &os, const Camera &cam, int imgSize) const;
};

bool ReadScene(std::istream &is, Scene &s, Camera &cam);

#endif // _SCENE_HH_
