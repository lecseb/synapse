/** This file is part of synapse.
 *
 * synapse is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * synapse is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with synapse.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "synapse-label.hh"
#include "synapse-visitor.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

Label::Label(const std::string& package, const std::string& enum_name,
    const EnumValueDescriptor *desc)
  : _name(std::string("e_" + package + "_" + enum_name + "_" + desc->name())),
    _value(std::to_string(desc->number())) {
}

const std::string& Label::get_name() const {
  return _name;
}

const std::string& Label::get_value() const {
  return _value;
}

std::string Label::accept(Visitor *visitor) {
  return visitor->visite(this);
}

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
