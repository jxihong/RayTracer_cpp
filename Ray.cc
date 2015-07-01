#include "Ray.hh"

Ray::Ray(const Vector3F &orig, const Vector3F &dir, bool normalize) :
    _orig(orig) , _dir(dir) {

    if(normalize)  _dir.normalize();
}

Vector3F Ray::getPointAtT(float t) const
{
    assert(t >= 0);
    
    Vector3F point = _orig + (_dir * t);
    return point;
}

Ray Ray::reflect(const Vector3F &p, const Vector3F &n, float DELTA /*= 0.0001*/) const
{
    // New direction negates component in direction of n
    // Dpar = project(-D, N)
    // Dr = D + 2 * Dpar
    Vector3F new_dir = _dir + 2.f * project(-_dir, n);

    // New origin offset from intersection point
    // Rr = (X + Dr * delta) + Dr * t
    Vector3F new_orig = p + new_dir * DELTA;

    return Ray(new_orig, new_dir);
}









