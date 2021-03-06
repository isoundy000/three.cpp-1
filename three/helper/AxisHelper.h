//
// Created by byter on 20.08.17.
//

#ifndef THREE_QT_AXISHELPER_H
#define THREE_QT_AXISHELPER_H

#include <objects/Line.h>
#include <memory>

namespace three {
namespace helper {

class AxisHelper : public Line {

  static Geometry::Ptr createGeometry(float size)
  {
    Geometry::Ptr geometry;// = new BufferGeometry();
    //geometry.addAttribute( 'position', new Float32BufferAttribute( vertices, 3 ) );
    //geometry.addAttribute( 'color', new Float32BufferAttribute( colors, 3 ) );
    return geometry;
  }

  static Material::Ptr createMaterial(float size) {
    Material::Ptr material;// = new LineBasicMaterial( { vertexColors: VertexColors } );
    return material;
  }

  AxisHelper(float size) : Line(createGeometry(size), createMaterial(size)) {}

public:
  using Ptr = std::shared_ptr<AxisHelper>;
  static Ptr make(float size) {return std::shared_ptr<AxisHelper>(new AxisHelper(size));}
};

}
}
#endif //THREE_QT_AXISHELPER_H
