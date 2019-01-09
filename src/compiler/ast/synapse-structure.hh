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

#ifndef _AST_SYNAPSE_STRUCTURE_HH_
# define _AST_SYNAPSE_STRUCTURE_HH_

# include <map>
# include <string>
# include "synapse-decl.hh"
# include "synapse-fields.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

/**
 * @brief Root element of the AST
 */
class structure : public decl {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf structure descriptor
   */
  explicit structure(const Descriptor *desc)
    : structure(desc->name(), new fields(desc)) {
    _desc = desc;
  }

  /**
   * @brief Constructor
   */
  structure(const std::string& name, fields *fields)
    : decl(name),
      _desc(NULL),
      _fields(fields) {}

  /**
   * @brief destructor
   */
  virtual ~structure() {
    delete _fields;
  }

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] visitor: visitor to browse
   */
  virtual std::string accept(visitor *visitor) const;

  /**
   * @brief Get all fields contained into the structure
   * @return a valid pointer
   */
  const fields *get_fields() const {
    return _fields;
  }

private:
  const Descriptor *_desc;
  fields *_fields;
};

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* _AST_SYNAPSE_STRUCTURE_HH_ */
