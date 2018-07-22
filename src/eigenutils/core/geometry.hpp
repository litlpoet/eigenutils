#ifndef SRC_EIGENUTILS_CORE_GEOMETRY_HPP_
#define SRC_EIGENUTILS_CORE_GEOMETRY_HPP_

#include <Eigen/Geometry>

#include <eigenutils/core/real.hpp>

namespace eigenutils
{

namespace core
{

using Trfm = Eigen::Transform<Real, 3, Eigen::Affine>;

}  // namespace core

}  // namespace eigenutils

#endif  // SRC_EIGENUTILS_CORE_GEOMETRY_HPP_
