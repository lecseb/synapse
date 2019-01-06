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

#include "synapse-enum.hh"
#include "adaptor/synapse-visitor.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace adaptor {

Enum::Enum(const EnumDescriptor *desc)
    : _labels(std::map<uint32_t, Label *>()),
      _name(desc->name()) {
  for (int32_t i = 0; i < desc->value_count(); i++) {
    const EnumValueDescriptor *label = desc->value(i);
    _labels[label->number()] = new Label(label);
  }
}

Enum::~Enum() {
  std::map<uint32_t, Label *>::iterator it = _labels.begin();
  for (; it != _labels.end(); it++)
    delete it->second;
}

std::string Enum::accept(Visitor *visitor) const {
  return visitor->visite(this);
}

const std::string& Enum::get_name() const {
  return _name;
}

std::map<uint32_t, Label *>::const_iterator Enum::get_label_begin() const {
  return _labels.begin();
}

std::map<uint32_t, Label *>::const_iterator Enum::get_label_end() const {
  return _labels.end();
}

};  // namespace adaptor
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
