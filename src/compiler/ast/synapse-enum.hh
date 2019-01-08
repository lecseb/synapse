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

#ifndef _AST_SYNAPSE_ENUM_HH_
# define _AST_SYNAPSE_ENUM_HH_

# include <map>
# include <string>
# include <google/protobuf/descriptor.h>
# include "synapse-element.hh"
# include "synapse-label.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

class Visitor;

/**
 * @brief C enumeration representation
 */
class Enum : public Element {
public:
  /**
   * @brief Constructor
   * @param [in] package: package name of the enum
   * @param [in] desc: protobuf enumeration representation
   */
  Enum(const std::string& package, const EnumDescriptor *desc);

  /**
   * @brief Destructor
   */
  virtual ~Enum();

  /**
   * @brief part of the visitor design pattern
   */
  virtual std::string accept(Visitor *visitor);

  /**
   * @brief Get an iterator over the first element contained in the enum
   * @return a valid iterator
   */
  std::map<uint32_t, Label *>::const_iterator get_labels_begin() const {
    return _labels.begin();
  }

  /**
   * @brief Get an iterator over the last element contained in the enum
   * @return a valid iterator
   */
  std::map<uint32_t, Label *>::const_iterator get_labels_end() const {
    return _labels.end();
  }

  /**
   * @brief Get the enumeration name
   * @return the enum string name
   */
  virtual const std::string& get_name() const;

private:
  std::map<uint32_t, Label *> _labels;
  std::string _name;
};

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_AST_SYNAPSE_ENUM_HH_ */
