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

#ifndef _AST_TYPES_SYNAPSE_ENUMERATOR_HH_
# define _AST_TYPES_SYNAPSE_ENUMERATOR_HH_

# include <string>
# include "ast/synapse-type.hh"

namespace synapse {
namespace compiler {
namespace ast {
namespace types {

/**
 * @brief structure description
 */
class enumerator : public ast::type {
public:
  /**
   * @brief Constructor
   * @param [in] name: name of the type
   * @param [in] value: value of the type
   */
  enumerator(const std::string& name, const std::string& value)
    : type(name, value, false),
      _value(std::stoul(value, nullptr, 10)) {
  }

  /**
   * @brief destructor
   */
  virtual ~enumerator() {}

  /**
   * @brief Get the field form of the descriptor
   * @retun a string
   */
  virtual std::string get_field_form(bool) const {
    return _name + std::string(" = ") + get_default_value();
  }

  /**
   * @brief Get the return form of the descriptor
   * @retun a string
   */
  virtual std::string get_return_form(bool) const {
    return std::string();
  }

  /**
   * @brief Get the return form of the descriptor
   * @retun a string
   */
  virtual std::string get_type_form() const {
    return std::string();
  }

  virtual uint32_t get_value() const {
    return _value;
  }

private:
  uint32_t _value;
};

};  // namespace types
};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_TYPES_SYNAPSE_ENUMERATOR_HH_ */
