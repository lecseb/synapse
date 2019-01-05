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

#ifndef _ADAPTOR_SYNAPSE_STRUCT_HH_
# define _ADAPTOR_SYNAPSE_STRUCT_HH_

# include <map>
# include <string>
# include <google/protobuf/descriptor.h>
# include "synapse-element.hh"
# include "synapse-field.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace adaptor {

class Struct : public Element {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf structure representation
   */
  explicit Struct(const Descriptor *desc)
    : _fields(std::map<std::string, Field *>()),
      _name(desc->name()) {
    for (int32_t i = 0; i < desc->field_count(); i++) {
      const FieldDescriptor *field = desc->field(i);
      _fields[field->name()] = new Field(field);
    }
  }

  /**
   * @brief Destructor
   */
  virtual ~Struct() {
    std::map<std::string, Field *>::iterator it = _fields.begin();
    for (; it != _fields.end(); it++)
      delete it->second;
  }

  /**
   * @brief part of the visitor design pattern
   */
  virtual std::string accept(Visitor *visitor) const {
    return visitor->visite(this);
  }

  /**
   * @brief Get the structure name
   * @return return a string
   */
  std::string get_name() const {
    return _name;
  }

  /**
   * @brief Get an iterator over the first field contained in the enum
   * @return a valid iterator
   */
  std::map<std::string, Field *>::const_iterator get_field_begin() const {
    return _fields.begin();
  }

  /**
   * @brief Get an iterator over the last field contained in the enum
   * @return a valid iterator
   */
  std::map<std::string, Field *>::const_iterator get_field_end() const {
    return _fields.end();
  }

private:
  std::map<std::string, Field *> _fields;
  std::string _name;
};

};  // namespace adaptor
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_ADAPTOR_SYNAPSE_STRUCT_HH_ */
