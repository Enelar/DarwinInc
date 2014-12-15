//#include "../../../Eigen/Eigen/Dense"
//Eigen::Vector2f vec;

#include "Iw2D.h"

typedef CIwVec2 vecI;
typedef CIwFVec2 vecF;
typedef CIwVec2 vecD;

typedef CIwVec3 vecI3;
typedef CIwFVec3 vecF3;
typedef CIwVec3 vecD3;

typedef CIwVec4 vecI4;
typedef CIwFVec4 vecF4;
typedef CIwVec4 vecD4;

typedef vecF vec;
typedef vecF3 vec3;
typedef vecF4 vec4;

#define construct_vec(base, X, Y) vec(base##X, base##Y)
#define deconstruct_vec(vec, base, X, Y) base##X = vec.x, base##Y = vec.y