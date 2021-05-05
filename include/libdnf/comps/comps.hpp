/*
Copyright (C) 2021 Red Hat, Inc.

This file is part of libdnf: https://github.com/rpm-software-management/libdnf/

Libdnf is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

Libdnf is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with libdnf.  If not, see <https://www.gnu.org/licenses/>.
*/


#ifndef LIBDNF_COMPS_COMPS_HPP
#define LIBDNF_COMPS_COMPS_HPP

#include "libdnf/comps/group/sack.hpp"

#include <memory>


namespace libdnf {
class Base;
}


namespace libdnf::comps {


class Comps {
public:
    explicit Comps(libdnf::Base & base);
    ~Comps();

    void load_installed();
    // Load comps from given file into the pool
    void load_from_file(const std::string & path, const char * reponame);
    GroupSack & get_group_sack() { return group_sack; }

private:
    libdnf::Base & base;
    GroupSack group_sack{*this};

    class Impl;
    std::unique_ptr<Impl> p_impl;

    friend GroupSack;
    friend GroupQuery;
    friend Group;
};


}  // namespace libdnf::comps


#endif  // LIBDNF_COMPS_COMPS_HPP