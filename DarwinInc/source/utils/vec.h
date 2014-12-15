//#include "../../../Eigen/Eigen/Dense"
//Eigen::Vector2f vec;

#include "Iw2D.h"

typedef CIwVec2 vecI;
typedef CIwFVec2 vecF;
typedef CIwVec2 vecD;

typedef vecF vec;

#define construct_vec(base, X, Y) vec(base##X, base##Y)
#define deconstruct_vec(vec, base, X, Y) base##X = vec.x, base##Y = vec.y