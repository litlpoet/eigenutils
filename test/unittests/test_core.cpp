#include <catch2/catch.hpp>

#include <vector>

#include <eigenutils/core/geometry.hpp>
#include <eigenutils/core/matrix.hpp>

TEST_CASE("MemSizeTest", "[BasicTest]")
{
  std::vector<short> vec_short(15, 0);
  REQUIRE(sizeof(Eigen::Vector3d::Scalar) * 3 == sizeof(Eigen::Vector3d));
  REQUIRE(sizeof(double) * 4 * 4 == sizeof(eigenutils::core::Trfm));
  REQUIRE(sizeof(short) * vec_short.size() == sizeof(short) * 15);
}

TEST_CASE("DimTest", "[BasicTest]")
{
  eigenutils::core::Trfm trfm;
  eigenutils::core::MatX trfm_mat = trfm.matrix();
  REQUIRE(trfm_mat.rows() == 4);
  REQUIRE(trfm_mat.cols() == 4);
}
