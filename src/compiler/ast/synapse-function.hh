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

#ifndef _AST_SYNAPSE_FUNCTION_HH_
# define _AST_SYNAPSE_FUNCTION_HH_

# include <map>
# include <string>
# include "ast/synapse-decl.hh"
# include "ast/synapse-type.hh"

namespace synapse {
namespace compiler {
namespace ast {

class visitor;

/**
 * @brief function description
 */
class function {
public:
  /**
   * @brief typedef to simplify the naming
   */
  typedef std::map<uint32_t, type *> arguments;

  /**
   * @brief Constructor
   * @param [in] name: name of the structure
   * @param [in] args: argument of the function
   * @param [in] out: return of the function
   */
  function(const std::string& name, const arguments& args, type *out);

  /**
   * @brief destructor
   */
  virtual ~function();

  /**
   * @brief Get the argument list
   * @return the argument list
   */
  const arguments& get_arguments() const {
    return _args;
  }

  /**
   * @brief Get the name of the enumeration
   * @return a string
   */
  const std::string& get_name() const {
    return _name;
  }

  /**
   * @brief Create the prototype of the function
   * @return a string
   */
  std::string get_prototype(bool const_return, bool const_param) const;

  /**
   * @brief Get the output
   * @return the output (may be null)
   */
  const type *get_output() const {
    return _out;
  }

protected:
  arguments _args;
  std::string _name;
  type *_out;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_FUNCTION_HH_ */
