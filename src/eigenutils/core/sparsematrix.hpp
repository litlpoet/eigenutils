#ifndef SRC_EIGENUTILS_CORE_SPARSEMATRIX_HPP_
#define SRC_EIGENUTILS_CORE_SPARSEMATRIX_HPP_

#include <Eigen/SparseCore>

#include <eigenutils/core/real.hpp>

namespace eigenutils
{

namespace core
{

using SpTrp = Eigen::Triplet<Real>;

using SpVec  = Eigen::SparseVector<Real, Eigen::ColMajor>;
using SpVeci = Eigen::SparseVector<Idx, Eigen::ColMajor>;

using SpVecRM  = Eigen::SparseVector<Real, Eigen::RowMajor>;
using SpVecRMi = Eigen::SparseVector<Idx, Eigen::RowMajor>;

using SpMat  = Eigen::SparseMatrix<Real, Eigen::ColMajor>;
using SpMati = Eigen::SparseMatrix<Idx, Eigen::ColMajor>;

using SpMatRM  = Eigen::SparseMatrix<Real, Eigen::RowMajor>;
using SpMatRMi = Eigen::SparseMatrix<Idx, Eigen::RowMajor>;

}  // namespace core

}  // namespace eigenutils

#endif  // SRC_EIGENUTILS_CORE_SPARSEMATRIX_HPP_
