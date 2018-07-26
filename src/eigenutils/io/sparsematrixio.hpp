#ifndef SRC_EIGENUTILS_IO_SPARSEMATRIXIO_HPP_
#define SRC_EIGENUTILS_IO_SPARSEMATRIXIO_HPP_

namespace eigenutils
{

namespace io
{

template<typename spmat>
bool
WriteSparseMatrix(spmat const& sparse_mat)
{
  return true;
}

template<typename spmat>
bool
ReadSparseMatrix(spmat& sparse_mat)
{
  return true;
}

}  // namespace io

}  // namespace eigenutils

#endif  // SRC_EIGENUTILS_IO_SPARSEMATRIXIO_HPP_
