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

#ifndef _ADAPTOR_SYNAPSE_AST_HH_
# define _ADAPTOR_SYNAPSE_AST_HH_

# include <list>
# include <string>
# include <google/protobuf/descriptor.h>
# include "synapse-element.hh"
# include "synapse-enum.hh"
# include "synapse-field.hh"
# include "synapse-label.hh"
# include "synapse-struct.hh"
# include "synapse-visitor.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace adaptor {

/**
 * @brief Root element of the AST
 */
class Ast : public Element {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf root ast representation
   */
  explicit Ast(const FileDescriptor *desc)
    : _enums(std::list<Enum *>()),
      _structs(std::list<Struct *>()) {
    for (int32_t i = 0; i < desc->enum_type_count(); i++)
      _enums.push_back(new Enum(desc->enum_type(i)));
    for (int32_t i = 0; i < desc->message_type_count(); i++)
      _structs.push_back(new Struct(desc->message_type(i)));
  }

  /**
   * @brief Destructor
   */
  virtual ~Ast() {
    std::list<Enum *>::iterator it_enum = _enums.begin();
    for (; it_enum != _enums.end(); it_enum++)
      delete *it_enum;
    std::list<Struct *>::iterator it_struct = _structs.begin();
    for (; it_struct != _structs.end(); it_struct++)
      delete *it_struct;
  }

  /**
   * @brief part of the visitor design pattern
   */
  virtual std::string accept(Visitor *visitor) const {
    return visitor->visite(this);
  }

  /**
   * @brief Get an iterator over the first element contained in the enum
   * @return a valid iterator
   */
  std::list<Enum *>::const_iterator get_enum_begin() const {
    return _enums.begin();
  }

  /**
   * @brief Get an iterator over the last element contained in the enum
   * @return a valid iterator
   */
  std::list<Enum *>::const_iterator get_enum_end() const {
    return _enums.end();
  }

  /**
   * @brief Get an iterator over the first element contained in the enum
   * @return a valid iterator
   */
  std::list<Struct *>::const_iterator get_struct_begin() const {
    return _structs.begin();
  }

  /**
   * @brief Get an iterator over the last element contained in the enum
   * @return a valid iterator
   */
  std::list<Struct *>::const_iterator get_struct_end() const {
    return _structs.end();
  }

private:
  std::list<Enum *> _enums;
  std::list<Struct *> _structs;
};

};  // namespace adaptor
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_ADAPTOR_SYNAPSE_AST_HH_ */
