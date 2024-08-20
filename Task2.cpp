#include <iostream>
#include <cmath>
using namespace std;

class CPoint3D {
    public:
        double x, y, z;
        CPoint3D (double dX = 0.0, double dY = 0.0, double dZ = 0.0)
        : x(dX), y(dY), z(dZ) {}

        CPoint3D operator + (const CPoint3D& point) const {
                return CPoint3D(x + point.x, y + point.y, z + point.z);
        }

        CPoint3D operator - (const CPoint3D& point) const {
                return CPoint3D(x - point.x, y - point.y, z - point.z);
        }

        CPoint3D operator * (double dFactor) const {
                return CPoint3D(x * dFactor, y * dFactor, z * dFactor);
        }

        CPoint3D operator / (double dFactor) const {
                return CPoint3D(x / dFactor, y / dFactor, z / dFactor);
        }


        double SquaredLength () const {
                return (x * x) + (y * y) + (z * z);
        }

        double Length () const {
                return sqrt(SquaredLength());
        }

        double SquaredDistance (const CPoint3D& v) const {
                return ((x - v.x) * (x - v.x) + (y - v.y) * (y - v.y) + (z - v.z) * (z - v.z));
        };

        double Distance (const CPoint3D& v) const {
                return sqrt(SquaredDistance(v));
        }

        CPoint3D Cross(const CPoint3D& v) const {
                return CPoint3D(
                    y * v.z - z * v.y,
                    z * v.x - x * v.z,
                    x * v.y - y * v.x
                );
        }

        double Dot(const CPoint3D& v) const {
                return x * v.x + y * v.y + z * v.z;
        }

        // Task 1. Method which return the distance D from P to an inf line of A and B
        double distance_D(const CPoint3D& A, const CPoint3D& B) const {

                CPoint3D AB = B - A;
                CPoint3D AP = *this - A;
                CPoint3D crossProduct = AP.Cross(AB);

                double crossProductMagnitude = crossProduct.Length();
                double ABLength = AB.Length();

                return crossProductMagnitude / ABLength;
        }
        // Task 2. Method which return the square of the distance from the nearest point from line segment from A to B
        double SquaredDistanceFromNearest(const CPoint3D& A, const CPoint3D& B) const {
                CPoint3D AB = B - A;
                CPoint3D AP = *this - A;

                double pFactor = AP.Dot(AB) / AB.SquaredLength();

                CPoint3D nearestPoint;
                if (pFactor < 0) {
                        nearestPoint = A;
                }
                else if (pFactor > 1) {
                        nearestPoint = B;
                }
                else {
                        nearestPoint = A + AB * pFactor;
                }

                return (*this - nearestPoint).SquaredLength();
        }
};
