#include <gtest/gtest.h>

#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

#include <Eigen/Dense>
#include <Eigen/Geometry>

#include <b64/decode.h>
#include <b64/encode.h>

using Transf = Eigen::Transform<double, 3, Eigen::Affine>;

TEST(FileIOTest, SingleBinaryIOTest) {
  Eigen::Matrix4d mat_write = Eigen::Matrix4d::Random();
  Eigen::Matrix4d mat_read;

  std::ofstream os_mat("mat_write.bin", std::ios::out | std::ios::binary);
  if( os_mat.is_open()) {
    os_mat.write(reinterpret_cast<char*>(mat_write.data()), sizeof(mat_write));
    os_mat.close();
  } else {
    std::cout << "Unable to open file!" <<std::endl;
  }

  std::ifstream is_mat("mat_write.bin", std::ios::in | std::ios::binary);
  if (is_mat.is_open()) {
    is_mat.read(reinterpret_cast<char*>(mat_read.data()), sizeof(mat_read));
    is_mat.close();
  } else {
    std::cout << "Unable to open file!" << std::endl;
  }
  bool comp_res = mat_write.isApprox(mat_read);
  EXPECT_EQ(true, comp_res);
  EXPECT_EQ(0, std::remove("mat_write.bin"));
}

TEST(FileIOTest, SingleAsciiTest) {
  Eigen::Matrix4d mat_write = Eigen::Matrix4d::Random();
  Eigen::Matrix4d mat_read;

  std::ofstream os_mat("mat_write.txt", std::ios::out);
  if(os_mat.is_open()) {
    base64::encoder e;
    std::stringstream ss_out(std::iso_base::in | std::ios_base::out | std::stringstream::binary);
    ss_out.write(reinterpret_cast<char*>(mat_write.data()), sizeof(mat_write));
    ss_out.seekg(0);
    e.encode(ss_out, os_mat);
    os_mat.close();
  } else {
    std::cout << "Unable to open file!" << std::endl;
  }

  std::ifstream is_mat("mat_write.txt", std::ios::in);
  if(is_mat.is_open()) {
    base64::decoder d;
    std::stringstream ss_in(std::ios_base::in | std::ios_base::out | std::stringstream::binary);
    d.decode(is_mat, ss_in);
    ss_in.read(reinterpret_cast<char*>(mat_read.data()), sizeof(mat_read));
    is_mat.close();
  } else {
    std::cout << "Unable to open file!" << std::endl;
  }
  bool comp_res = mat_write.isApprox(mat_read);
  EXPECT_EQ(true, comp_res);
  EXPECT_EQ(0, std::remove("mat_write.txt"));
}

TEST(FileIOTest, VectorBinaryIOTest) {
  std::vector<Transf> mat_list_write;
  std::vector<Transf> mat_list_read;
  mat_list_write.resize(10);
  mat_list_read.resize(10);
  for (auto& mat : mat_list_write) mat = Eigen::Matrix4d::Random();

  EXPECT_EQ(sizeof(double) * 4*4*10, sizeof(Transf)*10);

  std::ostream os_mat("mat_list_write.bin", std::ios::out | std::ios::binary);
  if(os_mat.is_open()) {
    os_mat.write(reinterpret_cast<char*>(mat_list_write.data()), sizeof(Transf) *10);
    os_mat.close();
  } else {
    std::cout << "Unable to open file!" << std::endl;
  }

  std::ifstream is_mat("mat_list_write.bin", std::ios:in | std::ios::binary);
  if(is_mat.is_open()) {
    is_mat.read(reinterpret_cast<char*>(mat_list_read.data()), sizeof(Transf) *10);
    is_mat.close();
  } else {
    std::cout << "Unable to open file!" << std::endl;
  }

  for(size_t i=0 ; i<10; ++i)
    EXPECT_EQ(true, mat_list_write[i].isApprox(mat_list_read[i]));
  EXPECT_EQ(0, std::remove("mat_list_write.bin"));
}
