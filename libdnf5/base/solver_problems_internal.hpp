/*
Copyright Contributors to the libdnf project.

This file is part of libdnf: https://github.com/rpm-software-management/libdnf/

Libdnf is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 2.1 of the License, or
(at your option) any later version.

Libdnf is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with libdnf.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef LIBDNF5_BASE_SOLVER_PROBLEMS_INTERNAL_HPP
#define LIBDNF5_BASE_SOLVER_PROBLEMS_INTERNAL_HPP

#include "libdnf5/base/base.hpp"
#include "libdnf5/base/solver_problems.hpp"
#include "rpm/solv/goal_private.hpp"


namespace libdnf5::base {


std::vector<std::vector<std::pair<libdnf5::ProblemRules, std::vector<std::string>>>> process_solver_problems(
    const libdnf5::BaseWeakPtr & base, rpm::solv::GoalPrivate & solved_goal);


}  // namespace libdnf5::base

#endif  // LIBDNF5_BASE_SOLVER_PROBLEMS_INTERNAL_HPP
