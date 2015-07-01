#include "CylinderObject.hh"

using namespace std;

int CylinderObject::getIntersections(const Ray &r, float &t1, float &t2) const
{
    Vector3F c_par = project(_center, _axis);
    Vector3F p_par = project(r.get_origin(), _axis);
    Vector3F d_par = project(r.get_direction(), _axis);

    // Check that ray is capable of hitting cylinder
    if ((r.get_direction() - d_par).get_magnitude() == 0)
    {
        t1 = -1;
        t2 = -1;
        return 0;
    }

    // Imaginary sphere to test intersections
    SphereObject sph = SphereObject(_radius, _center - c_par);

    // Imaginary ray projected into the cylinder's X-section plane
    // NOT normalized, so that t values transform correctly
    Ray r_proj = Ray(r.get_origin() - p_par, r.get_direction() - d_par, false);

    // Get intersections
    int count = sph.getIntersections(r_proj, t1, t2);

    // Check that intersections are within height of the cylinder
    // Check the 2nd intersection
    if ((count == 2) && ((p_par - c_par + d_par * t2).get_magnitude() > _height / 2))
    {
        // Intersection misses height
        t2 = -1;
        count--;
    }

    if ((count >= 1) && ((p_par - c_par + d_par * t1).get_magnitude() > _height / 2))
    {
        // Intersection misses height
        t1 = t2;
        t2 = -1;
        count--;
    }

    return count;
}

float CylinderObject::intersection(const Ray &r) const
{
    float t1, t2;

    // Get the intersections
    getIntersections(r, t1, t2);

    // Only care about the first intersection,
    // which will already be flagged if there are none
    return t1;
}

Vector3F CylinderObject::surface_normal(const Vector3F &point) const
{
    // Get vector from center to surface point
    Vector3F offset = point - _center;

    // Remove component along axis
    Vector3F norm = offset - project(offset, _axis);
    norm.normalize();
    
    return norm;
}

// Read input as r h (cx, cy, cz) (ax, ay, az) [r, g, b] ref
SPSceneObject ReadCylinder(istream &is)
{
    SPSceneObject obj; 
    if (!is) return obj;

    float r;
    float h;
    Vector3F v_c;
    Vector3F v_a;
    Color c;
    float ref;
    
    is >> r;
    is >> h;
    is >> v_c;
    is >> v_a;
    is >> c;
    is >> ref;

    if (is){
        obj = SPSceneObject(new CylinderObject(r, h, v_c, v_a, c, ref));
    }
    
    return obj;
}
















