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

  std::ofstream f("file.txt");
  //create_problem_file();
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
