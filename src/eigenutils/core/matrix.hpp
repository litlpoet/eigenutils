#ifndef SRC_EIGENUTILS_CORE_MATRIX_HPP_
#define SRC_EIGENUTILS_CORE_MATRIX_HPP_

#include <Eigen/Core>

#include <eigenutils/core/real.hpp>

namespace eigenutils
{

namespace core
{

using Vec2  = Eigen::Matrix<Real, 2, 1, Eigen::ColMajor>;
using Vec3  = Eigen::Matrix<Real, 3, 1, Eigen::ColMajor>;
using Vec4  = Eigen::Matrix<Real, 4, 1, Eigen::ColMajor>;
using Vec2i = Eigen::Matrix<Idx, 2, 1, Eigen::ColMajor>;
using Vec3i = Eigen::Matrix<Idx, 3, 1, Eigen::ColMajor>;
using Vec4i = Eigen::Matrix<Idx, 4, 1, Eigen::ColMajor>;
using VecX  = Eigen::Matrix<Idx, Eigen::Dynamic, 1, Eigen::ColMajor>;

using RVec2  = Eigen::Matrix<Real, 1, 2, Eigen::RowMajor>;
using RVec3  = Eigen::Matrix<Real, 1, 3, Eigen::RowMajor>;
using RVec4  = Eigen::Matrix<Real, 1, 4, Eigen::RowMajor>;
using RVec2i = Eigen::Matrix<Idx, 1, 2, Eigen::RowMajor>;
using RVec3i = Eigen::Matrix<Idx, 1, 3, Eigen::RowMajor>;
using RVec4i = Eigen::Matrix<Idx, 1, 4, Eigen::RowMajor>;
using RVecX  = Eigen::Matrix<Idx, 1, Eigen::Dynamic, Eigen::RowMajor>;

using Mat2x2 = Eigen::Matrix<Real, 2, 2, Eigen::ColMajor>;
using Mat2x3 = Eigen::Matrix<Real, 2, 3, Eigen::ColMajor>;
using Mat2x4 = Eigen::Matrix<Real, 2, 4, Eigen::ColMajor>;
using Mat3x2 = Eigen::Matrix<Real, 3, 2, Eigen::ColMajor>;
using Mat3x3 = Eigen::Matrix<Real, 3, 3, Eigen::ColMajor>;
using Mat3x4 = Eigen::Matrix<Real, 3, 4, Eigen::ColMajor>;
using Mat4x2 = Eigen::Matrix<Real, 4, 2, Eigen::ColMajor>;
using Mat4x3 = Eigen::Matrix<Real, 4, 3, Eigen::ColMajor>;
using Mat4x4 = Eigen::Matrix<Real, 4, 4, Eigen::ColMajor>;
using MatX   = Eigen::Matrix<Real, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor>;

using Mat2x2RM = Eigen::Matrix<Real, 2, 2, Eigen::RowMajor>;
using Mat2x3RM = Eigen::Matrix<Real, 2, 3, Eigen::RowMajor>;
using Mat2x4RM = Eigen::Matrix<Real, 2, 4, Eigen::RowMajor>;
using Mat3x2RM = Eigen::Matrix<Real, 3, 2, Eigen::RowMajor>;
using Mat3x3RM = Eigen::Matrix<Real, 3, 3, Eigen::RowMajor>;
using Mat3x4RM = Eigen::Matrix<Real, 3, 4, Eigen::RowMajor>;
using Mat4x2RM = Eigen::Matrix<Real, 4, 2, Eigen::RowMajor>;
using Mat4x3RM = Eigen::Matrix<Real, 4, 3, Eigen::RowMajor>;
using Mat4x4RM = Eigen::Matrix<Real, 4, 4, Eigen::RowMajor>;
using MatXRM   = Eigen::Matrix<Real, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>;

}  // namespace core

}  // namespace eigenutils

#endif  // SRC_EIGENUTILS_CORE_MATRIX_HPP_
