#include <catch2/catch.hpp>

#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>
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
  std::cout << "Sparse mat (input):\n" << sparse_mat << std::endl;

  constexpr auto const file_name = "sparse_mat.bin";
  std::ofstream        out_file(file_name, std::ios::out | std::ios::binary);
  REQUIRE(out_file.is_open());
  if (out_file.is_open())
  {
    eigenutils::io::WriteSparseMatrix(out_file, sparse_mat);
    out_file.close();
  }

  eigenutils::core::SpMat sparse_mat_new;
  std::ifstream           in_file(file_name, std::ios::in | std::ios::binary);
  REQUIRE(in_file.is_open());
  if (in_file.is_open())
  {
    eigenutils::io::ReadSparseMatrix(in_file, sparse_mat_new);
    std::cout << "Sparse mat (output):\n" << sparse_mat_new << std::endl;
  }

  auto MatA = eigenutils::core::MatX(sparse_mat);
  auto MatB = eigenutils::core::MatX(sparse_mat_new);
  std::cout << "Dense mat (input) :\n" << MatA << std::endl;
  std::cout << "Dense mat (output):\n" << MatB << std::endl;
  REQUIRE(MatA.cwiseEqual(MatB).count() == (4 * 5));
}

TEST_CASE("SparseMat Map", "[CoreSparseMatrix]")
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

  eigenutils::core::SpMatRM sparse_mat(4, 5);
  sparse_mat.setFromTriplets(triplets.cbegin(), triplets.cend());

  std::vector<double>                data(4 * 5);
  Eigen::Map<eigenutils::core::MatX> data_mat(data.data(), 4, 5);

  std::vector<double>                  data2(4 * 5);
  Eigen::Map<eigenutils::core::MatXRM> data2_mat(data2.data(), 4, 5);

  data_mat  = sparse_mat;
  data2_mat = sparse_mat;

  std::cout << "sparse_mat: " << std::endl << sparse_mat << std::endl;
  std::cout << "data_mat : " << std::endl << data_mat << std::endl;
  std::cout << "data_mat2: " << std::endl << data2_mat << std::endl;
  std::cout << "vector list: ";
  for (auto const& d : data)
    std::cout << d << ", ";
  std::cout << std::endl;
  std::cout << "vector list2: ";
  for (auto const& d : data2)
    std::cout << d << ", ";
  std::cout << std::endl;
}
