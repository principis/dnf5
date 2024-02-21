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


#ifndef LIBDNF5_CLI_OUTPUT_GROUPSUMMARY_HPP
#define LIBDNF5_CLI_OUTPUT_GROUPSUMMARY_HPP

#include "libdnf5-cli/output/key_value_table.hpp"

namespace libdnf5::cli::output {


static void add_line_into_groupsummary_table(KeyValueTable * table, const char * key, const uint value) {
    if (value == 0) {
        return;
    }

    table->add_line(key, value);
}

template <class Query>
void print_groupsummary_table(Query & group_list) {
    KeyValueTable table;

    uint installed_groups = 0;
    uint installed_lang_groups = 0;
    uint available_groups = 0;
    uint available_lang_groups = 0;

    for (const auto & group : group_list) {
        auto is_langonly = !group.get_langonly().empty();

        if (group.get_installed()) {
            is_langonly ? installed_lang_groups++ : installed_groups++;
        } else {
            is_langonly ? available_lang_groups++ : available_groups++;
        }
    }

    add_line_into_groupsummary_table(&table, "Installed Groups", installed_groups);
    add_line_into_groupsummary_table(&table, "Installed Language Groups", installed_lang_groups);
    add_line_into_groupsummary_table(&table, "Available Groups", available_groups);
    add_line_into_groupsummary_table(&table, "Available Language Groups", available_lang_groups);

    table.print();
}


}  // namespace libdnf5::cli::output

#endif  // LIBDNF5_CLI_OUTPUT_GROUPSUMMARY_HPP
