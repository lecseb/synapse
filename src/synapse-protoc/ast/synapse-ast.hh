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

#ifndef _AST_SYNAPSE_AST_HH_
# define _AST_SYNAPSE_AST_HH_

# include <list>
# include <string>
# include <google/protobuf/descriptor.h>
# include "synapse-element.hh"
# include "synapse-enum.hh"
# include "synapse-function.hh"
# include "synapse-include.hh"
# include "synapse-struct.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

class Visitor;

/**
 * @brief Root element of the AST
 */
class Ast : public Element {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf root ast representation
   */
  explicit Ast(const FileDescriptor *desc);

  /**
   * @brief Destructor
   */
  virtual ~Ast();

  /**
   * @brief part of the visitor design pattern
   */
  virtual std::string accept(Visitor *visitor);

  /**
   * @brief Get an iterator over the first element contained in the enum
   * @return a valid iterator
   */
  std::list<Enum *>::const_iterator get_enums_begin() const {
    return _enums.begin();
  }

  /**
   * @brief Get an iterator over the last element contained in the enum
   * @return a valid iterator
   */
  std::list<Enum *>::const_iterator get_enums_end() const {
    return _enums.end();
  }

  /**
   * @brief Get an iterator over the first element contained in the enum
   * @return a valid iterator
   */
  std::list<Struct *>::const_iterator get_structs_begin() const {
    return _structs.begin();
  }

  /**
   * @brief Get an iterator over the last element contained in the enum
   * @return a valid iterator
   */
  std::list<Struct *>::const_iterator get_structs_end() const {
    return _structs.end();
  }

  /**
   * @brief Add an include in the AST
   * @param [in] include: include instance to add in the generated
   * file
   */
  bool add_include(Include *include);

  /**
   * @brief Get an iterator over the first element contained in the enum
   * @return a valid iterator
   */
  std::list<Include *>::const_iterator get_includes_begin() const {
    return _includes.begin();
  }

  /**
   * @brief Get an iterator over the last element contained in the enum
   * @return a valid iterator
   */
  std::list<Include *>::const_iterator get_includes_end() const {
    return _includes.end();
  }

  /**
   * @brief Add an include in the AST
   * @param [in] name: name of the include to add in the generated
   * file
   */
  bool add_function(Function *function);

  /**
   * @brief Get an iterator over the first element contained in the enum
   * @return a valid iterator
   */
  std::list<Function *>::const_iterator get_functions_begin() const {
    return _functions.begin();
  }

  /**
   * @brief Get an iterator over the last element contained in the enum
   * @return a valid iterator
   */
  std::list<Function *>::const_iterator get_functions_end() const {
    return _functions.end();
  }

private:
  std::list<Enum *> _enums;
  std::list<Function *> _functions;
  std::list<Include *> _includes;
  std::list<Struct *> _structs;
};

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_AST_SYNAPSE_AST_HH_ */
