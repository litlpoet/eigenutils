#include <catch2/catch.hpp>

#include <iostream>
#include <vector>

#include <eigenutils/core/matrix.hpp>
#include <eigenutils/core/sparsematrix.hpp>
#include <eigenutils/io/sparsematrixio.hpp>

TEST_CASE("Initialization", "[CoreSparseMatrix]")
{
  eigenutils::core::MatX dense_mat(4, 5);
  // clang-format off
  dense_mat <<  1, 0,  3, 4, 0, // 1st row
                0, 0,  0, 2, 0, // 2nd row
                0, 0, -1, 3, 0, // 3rd row
               -2, 0,  0, 0, 7; // 4rd row
  // clang-format on
  std::cout << "Dense mat:\n" << dense_mat << std::endl;

  std::vector<eigenutils::core::SpTrp> triplets;
  triplets.emplace_back(eigenutils::core::SpTrp(0, 0, 1));
  triplets.emplace_back(eigenutils::core::SpTrp(0, 2, 3));
  triplets.emplace_back(eigenutils::core::SpTrp(0, 3, 4));
  triplets.emplace_back(eigenutils::core::SpTrp(1, 3, 2));
  triplets.emplace_back(eigenutils::core::SpTrp(2, 2, -1));
  triplets.emplace_back(eigenutils::core::SpTrp(2, 3, 3));
  triplets.emplace_back(eigenutils::core::SpTrp(3, 0, -2));
  triplets.emplace_back(eigenutils::core::SpTrp(3, 4, 7));

  eigenutils::core::SpMat sparse_mat(4, 5);
  sparse_mat.setFromTriplets(triplets.cbegin(), triplets.cend());
  std::cout << "Sparse mat :\n" << sparse_mat << std::endl;
  std::cout << "non zeros  : " << sparse_mat.nonZeros() << std::endl;
  std::cout << "outer size : " << sparse_mat.outerSize() << std::endl;
  std::cout << "inner size : " << sparse_mat.innerSize() << std::endl;

  REQUIRE(sparse_mat.isCompressed() == true);
  REQUIRE(eigenutils::core::MatX(sparse_mat) == dense_mat);
}

TEST_CASE("Sparse matrix IO", "[CoreSparseMatrix]")
{
  std::vector<eigenutils::core::SpTrp> triplets;
  triplets.emplace_back(eigenutils::core::SpTrp(0, 0, 1));
  triplets.emplace_back(eigenutils::core::SpTrp(0, 2, 3));
  triplets.emplace_back(eigenutils::core::SpTrp(0, 3, 4));
  triplets.emplace_back(eigenutils::core::SpTrp(1, 3, 2));
  triplets.emplace_back(eigenutils::core::SpTrp(2, 2, -1));
  triplets.emplace_back(eigenutils::core::SpTrp(2, 3, 3));
  triplets.emplace_back(eigenutils::core::SpTrp(3, 0, -2));
  triplets.emplace_back(eigenutils::core::SpTrp(3, 4, 7));

  eigenutils::core::SpMat sparse_mat(4, 5);
  sparse_mat.setFromTriplets(triplets.cbegin(), triplets.cend());

  eigenutils::io::WriteSparseMatrix(sparse_mat);

  eigenutils::core::SpMat sparse_mat_new;
  eigenutils::io::ReadSparseMatrix(sparse_mat_new);

  REQUIRE(eigenutils::core::MatX(sparse_mat) == eigenutils::core::MatX(sparse_mat_new));
}
