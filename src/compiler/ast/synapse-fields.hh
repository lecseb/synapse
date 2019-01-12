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

#ifndef _AST_SYNAPSE_FIELDS_HH_
# define _AST_SYNAPSE_FIELDS_HH_

# include <map>
# include <string>
# include "synapse-field.hh"
# include "synapse-interface.hh"

namespace synapse {
namespace compiler {
namespace ast {

/**
 * @brief Root element of the AST
 */
class fields : public interface {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf structure descriptor
   */
  explicit fields(const google::protobuf::Descriptor *desc);

  /**
   * @brief Constructor
   */
  explicit fields(const std::initializer_list<field *>& list);

  /**
   * @brief destructor
   */
  virtual ~fields();

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] visitor: visitor to browse
   */
  virtual std::string accept(visitor *visitor) const;

  /**
   * @brief Get the field list
   * @return a valid pointer
   */
  const std::map<uint32_t, field *>& get_fields() const {
    return _fields;
  }

private:
  std::map<uint32_t, field *> _fields;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_FIELDS_HH_ */
