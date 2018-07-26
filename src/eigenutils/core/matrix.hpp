#ifndef SRC_EIGENUTILS_CORE_MATRIX_HPP_
#define SRC_EIGENUTILS_CORE_MATRIX_HPP_

#include <Eigen/Core>

#include <eigenutils/core/real.hpp>

namespace eigenutils
{

namespace core
{

using Vec2  = Eigen::Matrix<Real, 2, 1>;
using Vec3  = Eigen::Matrix<Real, 3, 1>;
using Vec4  = Eigen::Matrix<Real, 4, 1>;
using Vec2i = Eigen::Matrix<Idx, 2, 1>;
using Vec3i = Eigen::Matrix<Idx, 3, 1>;
using Vec4i = Eigen::Matrix<Idx, 4, 1>;

using RVec2  = Eigen::Matrix<Real, 1, 2, Eigen::RowMajor>;
using RVec3  = Eigen::Matrix<Real, 1, 3, Eigen::RowMajor>;
using RVec4  = Eigen::Matrix<Real, 1, 4, Eigen::RowMajor>;
using RVec2i = Eigen::Matrix<Idx, 1, 2, Eigen::RowMajor>;
using RVec3i = Eigen::Matrix<Idx, 1, 3, Eigen::RowMajor>;
using RVec4i = Eigen::Matrix<Idx, 1, 4, Eigen::RowMajor>;

}  // namespace core

}  // namespace eigenutils

#endif  // SRC_EIGENUTILS_CORE_MATRIX_HPP_
