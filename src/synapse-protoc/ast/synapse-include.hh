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

#ifndef _AST_SYNAPSE_AST_INCLUDE_HH_
# define _AST_SYNAPSE_AST_INCLUDE_HH_

# include <list>
# include <string>
# include <google/protobuf/descriptor.h>
# include "synapse-element.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

class Visitor;

/**
 * @brief Root element of the AST
 */
class Include : public Element {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf root ast representation
   */
  explicit Include(const FileDescriptor *desc);

  /**
   * @brief Constructor
   * @param [in] name: name of the include
   */
  explicit Include(const std::string& name);

  /**
   * @brief Destructor
   */
  virtual ~Include() {}

  /**
   * @brief part of the visitor design pattern
   */
  virtual std::string accept(Visitor *visitor);

  /**
   * @brief Get the include name
   * @return a string
   */
  const std::string& get_name() const {
    return _name;
  }

  bool is_synapse_header() const {
    return _synapse_header;
  }

private:
  std::string _name;
  bool _synapse_header;
};

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_AST_SYNAPSE_INCLUDE_HH_ */
