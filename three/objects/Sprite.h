//
// Created by byter on 03.09.17.
//

#ifndef THREE_QT_SPRITE_H
#define THREE_QT_SPRITE_H

#include <core/Object3D.h>
#include <material/SpriteMaterial.h>

namespace three {

struct Intersect
{
  const float distance;
  const math::Vector3 intersectPoint;
  const Face3 face;
  const Object3D &object;

  Intersect(const float distance, const math::Vector3 &intersectPoint, const Face3 *face, const Object3D &object)
     : distance(distance), intersectPoint(intersectPoint), face(*face), object(object)
  {}
};

class Sprite : public Object3D
{
  Material::Ptr _material;

  explicit Sprite(Material::Ptr material) : _material(material)
  {}

public:
  static Ptr make(Material::Ptr material = SpriteMaterial::make())
  { return Ptr(new Sprite(material)); }

  void raycast(Raycaster raycaster, std::vector<Intersect> &intersects)
  {
    math::Vector3 intersectPoint;

    math::Vector3 worldPosition = math::Vector3::fromMatrixPosition(_matrixWorld);
    intersectPoint = raycaster.ray().closestPointToPoint(worldPosition);

    math::Vector3 worldScale = math::Vector3::fromMatrixScale(_matrixWorld);
    float guessSizeSq = worldScale.x() * worldScale.y() / 4;

    if (worldPosition.distanceToSquared(intersectPoint) > guessSizeSq) return;

    float distance = raycaster.ray().origin().distanceTo(intersectPoint);

    if (distance < raycaster.near() || distance > raycaster.far()) return;

    intersects.emplace_back(distance, intersectPoint, nullptr, *this);
  }
};

}
#endif //THREE_QT_SPRITE_H
