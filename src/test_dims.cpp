#include <gtest/gtest.h>

#include <vector>

#include <Eigen/Dense>
#include <Eigen/Geometry>

using Transf = Eigen::Transform<double, 3, Eigen::Affine>;

TEST(BasicTest, MemSizeTest) {
  std::vector<short> vec_short(15, 0);
  EXPECT_EQ(sizeof(Eigen::Vector3d::Scalar) *3, sizeof(Eigen::Vector3d));
  EXPECT_EQ(sizeof(double) * 4 * 4, sizeof(Transf));
  EXPECT_EQ(sizeof(short) * vec_short.size(), sizeof(short) *15);
}

TEST(BasicTest, DimTest) {
  Transf trfm;
  Eigen::MatrixXd trfm_mat = trfm.matrix();
  EXPECT_EQ(trfm_mat.rows(), 4);
  EXPECT_EQ(trfm_mat.cols(), 4);
}
