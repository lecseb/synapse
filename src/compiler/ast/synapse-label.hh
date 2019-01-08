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

#ifndef _AST_SYNAPSE_LABEL_HH_
# define _AST_SYNAPSE_LABEL_HH_

# include <string>
# include <google/protobuf/descriptor.h>
# include "synapse-element.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

class Visitor;

/**
 * @brief Enumeration label representation
 */
class Label : public Element {
public:
  /**
   * @brief Constructor
   * @param [in] package: package name of the label
   * @param [in] enum_name: enumeration name
   * @param [in] desc: protobuf label representation
   */
  Label(const std::string& package, const std::string& enum_name,
    const EnumValueDescriptor *desc);

  /**
   * @brief Destructor
   */
  virtual ~Label() {}

  /**
   * @brief Get the label name
   * @return the label name
   */
  const std::string& get_name() const;

  /**
   * @brief Get the label value
   * @return the label value
   */
  const std::string& get_value() const;

  /**
   * @brief part of the visitor design pattern
   */
  virtual std::string accept(Visitor *visitor);

private:
  std::string _name;
  std::string _value;
};

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_AST_SYNAPSE_LABEL_HH_ */
