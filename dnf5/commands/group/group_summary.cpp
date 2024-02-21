/*
Copyright Contributors to the libdnf project.

This file is part of libdnf: https://github.com/rpm-software-management/libdnf/

Libdnf is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

Libdnf is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with libdnf.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "group_summary.hpp"

#include <libdnf5-cli/output/groupsummary.hpp>

namespace dnf5 {

using namespace libdnf5::cli;

void GroupSummaryCommand::print(const libdnf5::comps::GroupQuery & query) {
    libdnf5::cli::output::print_groupsummary_table(query.list());
}

}  // namespace dnf5