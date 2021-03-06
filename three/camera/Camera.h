//
// Created by byter on 29.07.17.
//

#ifndef THREEQT_CAMERA
#define THREEQT_CAMERA

#include <math/Matrix4.h>
#include <math/Vector3.h>
#include <math/Quaternion.h>
#include <math/Ray.h>
#include <core/Object3D.h>

namespace three {

struct Viewport
{
  unsigned fullWidth=0;
  unsigned fullHeight=0;
  unsigned offsetX=0;
  unsigned offsetY=0;
  unsigned width=0;
  unsigned height=0;

  bool isNull() {
    return fullWidth == 0 && fullHeight == 0;
  }
};

class Camera : public Object3D
{
protected:
  math::Matrix4 _matrixWorldInverse;
  math::Matrix4 _projectionMatrix;

  Camera() : _projectionMatrix(math::Matrix4::identity()), _matrixWorldInverse(_matrixWorld.inverse()) {}

public:
  using Ptr = std::shared_ptr<Camera>;

  const math::Matrix4 &projectionMatrix() const {return _projectionMatrix;}
  //math::Matrix4 &projectionMatrix() {return _projectionMatrix;}
  const math::Matrix4 &matrixWorldInverse() const {return _matrixWorldInverse;}
  //math::Matrix4 &matrixWorldInverse() {return _matrixWorldInverse;}

  math::Vector3 getWorldDirection() const override
  {
    math::Quaternion quaternion = getWorldQuaternion();

    return math::Vector3(0, 0, - 1).apply(quaternion);
  }

  void updateMatrixWorld(bool force) override {

    Object3D::updateMatrixWorld(force);

    _matrixWorldInverse = _matrixWorld.inverse();
  }

  virtual void applyTo(math::Ray &ray, const math::Vector3 &coords) = 0;

  virtual void updateProjectionMatrix() = 0;
};

}


#endif //THREEQT_CAMERA
