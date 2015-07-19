#include "../include/PlaneObject.hh"

using namespace std;

// For a ray P + D * t, the intersection point is:
// t = -(P · N + d) / (D · N)
float PlaneObject::intersection(const Ray &r) const {
  float denominator = r.get_direction() * _normal;
    if(denominator == 0) {
      return -1;
    }
    
  float numerator = r.get_origin() * _normal + _dis;
  float t = -numerator / denominator;
    
  if(t >= 0){
    return t;
  }
  
  return -1;
}

// Read input as dist (x, y, z) [r, g, b] ref
SPSceneObject ReadPlane(istream &is) {
  SPSceneObject obj; 
  
  if (!is) return obj;

  float d;
  Vector3F v;
  Color c;
  float ref;
  
  is >> d;
  is >> v;
  is >> c;
  is >> ref;
    
  if (is){
    obj = SPSceneObject(new PlaneObject(d, v, c, ref));
  }
  
  return obj;
}


