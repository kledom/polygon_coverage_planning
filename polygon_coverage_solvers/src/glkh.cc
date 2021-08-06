/*
 * polygon_coverage_planning implements algorithms for coverage planning in
 * general polygons with holes. Copyright (C) 2019, Rik Bähnemann, Autonomous
 * Systems Lab, ETH Zürich
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "polygon_coverage_solvers/glkh.h"

#include <ros/assert.h>
#include <ros/console.h>
#include <ros/package.h>

#include <fstream>

namespace polygon_coverage_planning {
namespace glkh {

const std::string kFile = "runGLKH";
const std::string kPackageName = "polygon_coverage_solvers";
const std::string kPackagePath = ros::package::getPath(kPackageName);
const std::string kCatkinPath = kPackagePath.substr(0, kPackagePath.find("/src/"));
const std::string kLibraryPath = kCatkinPath + "/devel/lib";
const std::string kExecutablePath = kLibraryPath + "/" + kFile;

bool Task::mIsSquare() const {
  for (size_t i = 0; i < m.size(); ++i) {
    if (m[i].size() != m.size()) {
      return false;
    }
  }
  return true;
}

bool Task::mIsSymmetric() const {
  if (!mIsSquare()) {
    return false;
  }
  for (size_t i = 0; i < m.size(); ++i) {
    for (size_t j = 0; j < m[i].size(); ++j) {
      if (m[i][j] != m[j][i]) {
        return false;
      }
    }
  }
  return true;
}

Glkh::Glkh() {}

void Glkh::setSolver(const std::string& file, bool binary) {
  // Create problem file
  //create_problem_file();

}

void Glkh::setSolver(const Task& task) {
  // Create problem file

  std::string name = "sweep_plan";
  std::string type = task.mIsSymmetric() ? "GTSP" : "AGTSP";
  std::string comment = "Create by polygon_coverage_solvers.";
  size_t dimension = task.m.size();
  size_t num_sets = task.clusters.size();
  std::string edge_weight_type = "EXPLICIT";
  std::string edge_weight_format = "FULL_MATRIX";

  // Problem file
  std::ofstream f("/home/kledom/problem.gtsp");
  f << "Name: " << name << std::endl;
  f << "Type: " << type << std::endl;
  f << "COMMENT: " << comment << std::endl;
  f << "DIMENSION: " << dimension << std::endl;
  f << "GTSP_SETS: " << num_sets << std::endl;
  f << "EDGE_WEIGHT_TYPE: " << edge_weight_type << std::endl;
  f << "EDGE_WEIGHT_FORMAT: " << edge_weight_format << std::endl;

  f << "EDGE_WEIGHT_SECTION:" << std::endl;
  for (size_t i = 0; i < task.m.size(); i++)
  {
    for (auto m_ij : task.m[i])
    {
      f << m_ij << " ";
    }
    f << std::endl;
  }

  f << "GTSP_SET_SECTION:" << std::endl;
  for (size_t i = 0; i < task.clusters.size(); i++)
  {
    f << i + 1 << " ";
    for (auto vertex_idx : task.clusters[i])
    {
      f << vertex_idx + 1 << " ";
    }
    f << -1 << std::endl;
  }

  f << "EOF" << std::endl;
  f.close();
}

bool Glkh::solve() {
  // Solve
  // solve_with_file();

  // Validate solution
  //int num_nodes = solution_length...
  int num_nodes = 5;
  solution_.resize(num_nodes);
  for (int i = 0; i < num_nodes; ++i) {
    //solution_[i] = solution_at_index(i)
  }

  return true;
}

}  // namespace glkh
}  // namespace polygon_coverage_planning
