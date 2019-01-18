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

#ifndef _AST_SYNAPSE_ADAPTOR_HH_
# define _AST_SYNAPSE_ADAPTOR_HH_

# include <string>
# include <google/protobuf/descriptor.h>

namespace synapse {
namespace compiler {
namespace ast {

class adaptor {
public:
  static const std::string unknown;

  /**
   * @brief Convert a field descriptor into a complete field type
   * @param [in] desc: field descriptor to convert
   * @return a string
   */
  static std::string enumerator_tostring(
    const google::protobuf::EnumValueDescriptor *desc);

  /**
   * @brief Convert a field descriptor into a complete field type
   * @param [in] desc: field descriptor to convert
   * @return a string
   */
  static std::string field_tostring(
    const google::protobuf::FieldDescriptor *desc);

  /**
   * @brief Convert a descriptor into a complete parameter type
   * @param [in] desc: field descriptor to convert
   * @return a string
   */
  static std::string param_tostring(const google::protobuf::Descriptor *desc);

  /**
   * @brief Convert a descriptor into a complete parameter type
   * @param [in] desc: field descriptor to convert
   * @return a string
   */
  static std::string return_tostring(const google::protobuf::Descriptor *desc);

private:
  /**
   * @brief Convert a field descriptor type into a representation string
   * @param [in] type: type to convert
   * @return a string
   */
  static std::string _convert_type(
    const google::protobuf::FieldDescriptor::Type& type);
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* !_AST_SYNAPSE_ADAPTOR_HH_ */
