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
  using INDEX = typename Eigen::SparseMatrix<REAL, OPT, IDX>::Index;

  INDEX const rows = sparse_mat.rows();
  INDEX const cols = sparse_mat.cols();
  INDEX const nnzs = sparse_mat.nonZeros();
  INDEX const nout = sparse_mat.outerSize();

  out.write(reinterpret_cast<char const*>(&rows), sizeof(INDEX));
  out.write(reinterpret_cast<char const*>(&cols), sizeof(INDEX));
  out.write(reinterpret_cast<char const*>(&nnzs), sizeof(INDEX));
  out.write(reinterpret_cast<char const*>(&nout), sizeof(INDEX));
  out.write(reinterpret_cast<char const*>(sparse_mat.outerIndexPtr()), sizeof(IDX) * (nout + 1));
  out.write(reinterpret_cast<char const*>(sparse_mat.innerIndexPtr()), sizeof(IDX) * nnzs);
  out.write(reinterpret_cast<char const*>(sparse_mat.valuePtr()), sizeof(REAL) * nnzs);
  return true;
}

template<typename ISTREAM, typename REAL, int OPT, typename IDX>
bool
ReadSparseMatrix(ISTREAM& in, Eigen::SparseMatrix<REAL, OPT, IDX>& sparse_mat)
{
  using INDEX = typename Eigen::SparseMatrix<REAL, OPT, IDX>::Index;

  INDEX rows, cols, nnzs, nout;

  in.read(reinterpret_cast<char*>(&rows), sizeof(INDEX));
  in.read(reinterpret_cast<char*>(&cols), sizeof(INDEX));
  in.read(reinterpret_cast<char*>(&nnzs), sizeof(INDEX));
  in.read(reinterpret_cast<char*>(&nout), sizeof(INDEX));

  sparse_mat.resize(rows, cols);
  sparse_mat.makeCompressed();
  sparse_mat.reserve(nnzs);

  in.read(reinterpret_cast<char*>(sparse_mat.outerIndexPtr()), sizeof(IDX) * (nout + 1));
  in.read(reinterpret_cast<char*>(sparse_mat.innerIndexPtr()), sizeof(IDX) * nnzs);
  in.read(reinterpret_cast<char*>(sparse_mat.valuePtr()), sizeof(REAL) * nnzs);
  return true;
}

}  // namespace io

}  // namespace eigenutils

#endif  // SRC_EIGENUTILS_IO_SPARSEMATRIXIO_HPP_
