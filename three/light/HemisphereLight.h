//
// Created by byter on 24.09.17.
//

#ifndef THREE_QT_HEMISPHERELIGHT_H
#define THREE_QT_HEMISPHERELIGHT_H

#include "Light.h"

namespace three {

class HemisphereLight : public Light
{
  Color _groundColor;

public:
  HemisphereLight(const Color &skyColor, const Color &groundColor, float intensity)
     : Light(light::Resolver<HemisphereLight>::make(this), skyColor, intensity), _groundColor(groundColor)
  {
    updateMatrix();

    _position = math::Vector3(0, 1, 0);
  }

  const Color &skyColor() {return color();}
  const Color &groundColor() {return _groundColor;}
};

}
#endif //THREE_QT_HEMISPHERELIGHT_H
