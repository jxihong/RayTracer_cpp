#include "Light.hh"

using namespace std;

//Read input as  (x, y, z) [r, g, b]
SPLight ReadLight(istream &is)
{
    SPLight l; 
    if (!is) return l;

    Vector3F v;
    Color c;

    is >> v;
    is >> c;

    if (is){
        l = SPLight(new Light(v ,c));
    }
    
    return l;
}




