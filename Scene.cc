#include "Scene.hh"

using namespace std;

void Scene::add_object(SPSceneObject obj) {
  assert(obj != NULL); 
  
  _objects.push_back (obj);
}

void Scene::add_light(SPLight l) {
  assert(l != NULL); 
  
  _lights.push_back (l);
}

SPSceneObject Scene::findClosestObject(const Ray &r, float &tIntersect) const {
  vector<SPSceneObject>::const_iterator iter; 
    
  SPSceneObject closest;
  float t;
  float min = numeric_limits<float>::max();
  
  for (iter = _objects.begin(); iter != _objects.end(); ++iter) 
    { 
      t = (*iter)->intersection(r);
      
      if (t >= 0 && t < min)
        {
	  min = t;
	  closest = *iter;
        }
    }
  
  tIntersect = closest != 0 ? min : -1;
  
  return closest;
}

Color Scene::colorAtPoint(SPSceneObject obj, const Vector3F &pIntersect) const {
  Color rColor(0,0,0);
  
  Vector3F L;
  Vector3F N = obj->surface_normal(pIntersect);
  
  vector<SPLight>::const_iterator iter; 
  
  for (iter = _lights.begin(); iter != _lights.end(); ++iter) 
    { 
      L = (*iter)->get_position() - pIntersect;
      L.normalize();
        
      rColor += ((*iter)->get_color()) * (obj->get_surface_color()) * fmaxf(N * L, 0);
    }
  
  rColor.clamp();
    
  return rColor;
}

Color Scene::traceRay(const Ray &r, int depth) const
{
    Color rColor(0,0,0);
    float t;
    
    SPSceneObject obj = this->findClosestObject(r, t);
    if(t < 0 || obj == NULL){
        return rColor;
    }
    
    Vector3F intersect_loc = r.getPointAtT(t);
    rColor = this->colorAtPoint(obj, intersect_loc);
    
    // Surface reflectivity
    float ref = obj->get_surface_reflectivity();
    if (ref != 0 && depth > 0)
    {
      // Color based on reflection
      Color reflect_c = traceRay(r.reflect(intersect_loc, obj->surface_normal(intersect_loc)), depth - 1);

      rColor += ref * reflect_c;
    }
    
    return rColor;
}

void Scene::render(ostream &os, const Camera &cam, int imgSize) const {
  static int maxval = 255;
  
  //P3 width height maxval
  os << "P3 " 
     << imgSize << " "
     << imgSize << " "
     << maxval   << endl ; 
  
  for (int y = 0; y < imgSize; y++){
    for (int x = 0; x < imgSize; x++)
      {
	Ray pixelRay = cam.getRayForPixel(x, y, imgSize);
	Color pixelColor = this->traceRay(pixelRay);
            
	os << (int)(pixelColor.get_red()   * maxval) << " " 
	   << (int)(pixelColor.get_green() * maxval) << " " 
	   << (int)(pixelColor.get_blue()  * maxval) << endl;
      }
  }
}

bool ReadScene(istream &is, Scene &s, Camera &cam) {
    bool success = true;

    // Map of type names to SceneObjectReader functions
    map<string, SceneObjectReader> readFuncs;

    readFuncs["plane"] = ReadPlane;
    readFuncs["sphere"] = ReadSphere;
    readFuncs["cylinder"] = ReadCylinder;
    
    string line;
    int line_number = 0;
    for (getline(is, line); is.good(); getline(is, line))
    {
      
      line_number++; // Increment line number

      // Check for comment line
      if (line.length() == 0 || line[0] == '#') continue;
      
      // Create a string stream to read the line
      istringstream iss(line);
      
      // Read in the next component type
      string type;
      iss >> type;
      
      if (!iss) continue;

      try {
	if (readFuncs.find(type) != readFuncs.end()) {
	  SPSceneObject obj;
	  
	  // Read object using appropriate function
	  obj = readFuncs[type](iss);
	  
	  if (obj == NULL) throw runtime_error("");
	  else {  
	    s.add_object(obj);
	  }
	}
	else if (type == "light") {
	  SPLight l;
	  
	  l = ReadLight(iss);
	  
	  if (l == NULL) throw runtime_error("");
	  else {
	    s.add_light(l);
	  }
	}
	else if (type == "camera") {
	  cam = ReadCamera(iss);
	  
	  if (!cam.valid()) throw runtime_error("");
	}
	else {
	  success = false;
	  cerr << "Error: Unrecognized type " << type << " on line " << line_number
	       << endl;
	}
      }
      catch (const runtime_error &e) {
	success = false;
	cerr << "Error: Couldn't read type " << type << " on line " << line_number
	     << endl;
      }
    }
    return success;
}


