#include "polarcoordinate.h"
#include "cmath"
#include "vector2d.h"

PolarCoordinate::PolarCoordinate(double radius, double angle)
    : _radius(radius), _angle(angle) {}

PolarCoordinate &PolarCoordinate::operator= (const PolarCoordinate &b) {
  if (this != &b) {
    _radius = b._radius;
    _angle = b._angle;
  }
  return *this;
}

PolarCoordinate vec2d_to_polar(const Vector2d &vec) {
  double radius = vec.magnitude();
  double angle = atan2(vec.getY(), vec.getX());
  return {radius, angle};
}

Vector2d polar_to_vec2d(const PolarCoordinate &polar) {
  double x = polar.getRadius() * cos(polar.getAngle());
  double y = polar.getRadius() * sin(polar.getAngle());
  return {x, y};
}

PolarCoordinate PolarCoordinate::operator+(const PolarCoordinate &b) const {
  return vec2d_to_polar(polar_to_vec2d(*this) + polar_to_vec2d(b));
}

PolarCoordinate PolarCoordinate::operator-(const PolarCoordinate &b) const {
  return vec2d_to_polar(polar_to_vec2d(*this) - polar_to_vec2d(b));
}

PolarCoordinate &PolarCoordinate::operator+=(const PolarCoordinate &b) {
  *this = *this + b;
  return *this;
}

PolarCoordinate &PolarCoordinate::operator-=(const PolarCoordinate &b) {
  *this = *this - b;
  return *this;
}

PolarCoordinate PolarCoordinate::operator*(double b) const {
  return vec2d_to_polar(polar_to_vec2d(*this) * b);
}

PolarCoordinate PolarCoordinate::operator/(double b) const {
  return vec2d_to_polar(polar_to_vec2d(*this) / b);
}

PolarCoordinate &PolarCoordinate::operator*=(double b) {
  *this = *this * b;
  return *this;
}

PolarCoordinate &PolarCoordinate::operator/=(double b) {
  *this = *this / b;
  return *this;
}