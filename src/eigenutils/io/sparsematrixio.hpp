#ifndef SRC_EIGENUTILS_IO_SPARSEMATRIXIO_HPP_
#define SRC_EIGENUTILS_IO_SPARSEMATRIXIO_HPP_

#include <Eigen/Core>
#include <Eigen/SparseCore>

#include <iostream>

namespace eigenutils
{

namespace io
{

template<typename OSTREAM, typename REAL, int OPT, typename IDX>
bool
WriteSparseMatrix(OSTREAM& out, Eigen::SparseMatrix<REAL, OPT, IDX> const& sparse_mat)
{
  if (!sparse_mat.isCompressed())
    return false;

  IDX const rows          = sparse_mat.rows();
  IDX const cols          = sparse_mat.cols();
  IDX const nnzs          = sparse_mat.nonZeros();
  IDX const nout          = sparse_mat.outerSize();
  IDX const size_per_it   = 3;
  IDX const nnzs_per_it   = nnzs / size_per_it;
  IDX const nnzs_residual = nnzs % size_per_it;
  std::cout << "nnzs per it : " << nnzs_per_it << std::endl;
  std::cout << "nnzs resiual: " << nnzs_residual << std::endl;

  out.write(reinterpret_cast<char const*>(&rows), sizeof(IDX));
  out.write(reinterpret_cast<char const*>(&cols), sizeof(IDX));
  out.write(reinterpret_cast<char const*>(&nnzs), sizeof(IDX));
  out.write(reinterpret_cast<char const*>(&nout), sizeof(IDX));

  out.write(reinterpret_cast<char const*>(sparse_mat.outerIndexPtr()), sizeof(IDX) * (nout + 1));
  for (size_t i = 0; i < size_per_it; ++i)
  {
    out.write(reinterpret_cast<char const*>(sparse_mat.innerIndexPtr() + (i * nnzs_per_it)),
              sizeof(IDX) * nnzs_per_it);
    out.write(reinterpret_cast<char const*>(sparse_mat.valuePtr() + (i * nnzs_per_it)),
              sizeof(REAL) * nnzs_per_it);
  }
  if (nnzs_residual != 0)
  {
    out.write(
        reinterpret_cast<char const*>(sparse_mat.innerIndexPtr() + (size_per_it * nnzs_per_it)),
        sizeof(IDX) * nnzs_residual);
    out.write(reinterpret_cast<char const*>(sparse_mat.valuePtr() + (size_per_it * nnzs_per_it)),
              sizeof(REAL) * nnzs_residual);
  }
  return true;
}

template<typename ISTREAM, typename REAL, int OPT, typename IDX>
bool
ReadSparseMatrix(ISTREAM& in, Eigen::SparseMatrix<REAL, OPT, IDX>& sparse_mat)
{
  IDX rows, cols, nnzs, nout;

  in.read(reinterpret_cast<char*>(&rows), sizeof(IDX));
  in.read(reinterpret_cast<char*>(&cols), sizeof(IDX));
  in.read(reinterpret_cast<char*>(&nnzs), sizeof(IDX));
  in.read(reinterpret_cast<char*>(&nout), sizeof(IDX));

  sparse_mat.resize(rows, cols);
  sparse_mat.makeCompressed();
  sparse_mat.resizeNonZeros(nnzs);

  IDX const size_per_it   = 3;
  IDX const nnzs_per_it   = nnzs / size_per_it;
  IDX const nnzs_residual = nnzs % size_per_it;
  std::cout << "nnzs per it : " << nnzs_per_it << std::endl;
  std::cout << "nnzs resiual: " << nnzs_residual << std::endl;

  in.read(reinterpret_cast<char*>(sparse_mat.outerIndexPtr()), sizeof(IDX) * (nout + 1));
  for (size_t i = 0; i < size_per_it; ++i)
  {
    in.read(reinterpret_cast<char*>(sparse_mat.innerIndexPtr() + (i * nnzs_per_it)),
            sizeof(IDX) * nnzs_per_it);
    in.read(reinterpret_cast<char*>(sparse_mat.valuePtr() + (i * nnzs_per_it)),
            sizeof(REAL) * nnzs_per_it);
  }
  if (nnzs_residual != 0)
  {
    in.read(reinterpret_cast<char*>(sparse_mat.innerIndexPtr() + (size_per_it * nnzs_per_it)),
            sizeof(IDX) * nnzs_residual);
    in.read(reinterpret_cast<char*>(sparse_mat.valuePtr() + (size_per_it * nnzs_per_it)),
            sizeof(REAL) * nnzs_residual);
  }
  return true;
}

}  // namespace io

}  // namespace eigenutils

#endif  // SRC_EIGENUTILS_IO_SPARSEMATRIXIO_HPP_
