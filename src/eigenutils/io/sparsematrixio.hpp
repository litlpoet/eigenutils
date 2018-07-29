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

  IDX const rows = sparse_mat.rows();
  IDX const cols = sparse_mat.cols();
  IDX const nnzs = sparse_mat.nonZeros();
  IDX const nout = sparse_mat.outerSize();

  out.write(reinterpret_cast<char const*>(&rows), sizeof(IDX));
  out.write(reinterpret_cast<char const*>(&cols), sizeof(IDX));
  out.write(reinterpret_cast<char const*>(&nnzs), sizeof(IDX));
  out.write(reinterpret_cast<char const*>(&nout), sizeof(IDX));

  out.write(reinterpret_cast<char const*>(sparse_mat.valuePtr()), sizeof(REAL) * nnzs);
  out.write(reinterpret_cast<char const*>(sparse_mat.outerIndexPtr()), sizeof(IDX) * (nout + 1));
  out.write(reinterpret_cast<char const*>(sparse_mat.innerIndexPtr()), sizeof(IDX) * nnzs);

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
  sparse_mat.reserve(nnzs);
  in.read(reinterpret_cast<char*>(sparse_mat.valuePtr()), sizeof(REAL) * nnzs);
  in.read(reinterpret_cast<char*>(sparse_mat.outerIndexPtr()), sizeof(IDX) * (nout + 1));
  in.read(reinterpret_cast<char*>(sparse_mat.innerIndexPtr()), sizeof(IDX) * nnzs);
  sparse_mat.makeCompressed();

  return true;
}

}  // namespace io

}  // namespace eigenutils

#endif  // SRC_EIGENUTILS_IO_SPARSEMATRIXIO_HPP_
