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

#ifndef _ADAPTOR_SYNAPSE_FUNCTION_HH_
# define _ADAPTOR_SYNAPSE_FUNCTION_HH_

# include <map>
# include <string>
# include <google/protobuf/descriptor.h>
# include "synapse-element.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace adaptor {

class Visitor;

/**
 * @brief C enumeration representation
 */
class Function : public Element {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf enumeration representation
   */
  explicit Function(const ServiceDescriptor *desc);

  /**
   * @brief Destructor
   */
  virtual ~Function() {}

  /**
   * @brief part of the visitor design pattern
   */
  virtual std::string accept(Visitor *visitor) const;
};

};  // namespace adaptor
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_ADAPTOR_SYNAPSE_FUNCTION_HH_ */
