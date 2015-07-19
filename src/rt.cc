#include "../include/Vector3.hh"
#include "../include/Color.hh"
#include "../include/SphereObject.hh"
#include "../include/PlaneObject.hh"
#include "../include/SceneObject.hh"
#include "../include/Camera.hh"
#include "../include/Scene.hh"
#include "../include/Light.hh"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    Scene s;
    Camera cam;
   
    ifstream f;
    bool hasFile = false;

    string usage = "Usage: " + string(argv[0])+ " -f <filename>";
    if (argc > 1) {
      if (string(argv[1]) != "-f") {
	cerr << usage << endl;
	return -1;;
      }

      f.open(argv[2]);
      if (!f.good()) {
	cerr << "Couldn't open file " << argv[2] << endl;
	cerr << usage << endl;
	return -1;
      }
      hasFile = true;
    }

    istream &in = hasFile ? f : cin;
    if(!ReadScene(in, s, cam)) {
      cerr << "Parsing of scene description failed." << endl;
      return -1;
    }
    else  {
        // Render the scene to std out
        s.render(cout, cam, 500);
    }

    if (hasFile) f.close();
    
    return 0;
}
