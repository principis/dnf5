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

#ifndef LIBDNF5_TRANSACTION_ITEM_TYPE_HPP
#define LIBDNF5_TRANSACTION_ITEM_TYPE_HPP

#include "libdnf5/common/exception.hpp"

#include <string>


namespace libdnf5::transaction {

enum class TransactionItemType : int { PACKAGE, GROUP, ENVIRONMENT, MODULE };


class InvalidTransactionItemType : public libdnf5::Error {
public:
    InvalidTransactionItemType(const std::string & type);

    const char * get_domain_name() const noexcept override { return "libdnf5::transaction"; }
    const char * get_name() const noexcept override { return "InvalidTransactionItemType"; }
};


std::string transaction_item_type_to_string(TransactionItemType action);
TransactionItemType transaction_item_type_from_string(const std::string & action);


}  // namespace libdnf5::transaction

#endif  // LIBDNF5_TRANSACTION_ITEM_TYPE_HPP
