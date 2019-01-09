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

# include <list>
# include <string>
# include "synapse-composite.hh"
# include "synapse-decl.hh"
# include "synapse-params.hh"
# include "synapse-structure.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace ast {

/**
 * @brief Function element of the AST
 */
class function : public decl {
public:
  /**
   * @brief Ouptu element of a function
   */
  class out : public param {
  public:
    /**
     * @brief Constructor
     * @param [in] desc: protobuf output function type
     */
    out(const Descriptor *desc)
      : param(desc) {}

    /**
     * @brief Destructor
     */
    virtual ~out() {};

    /**
     * @brief Accept function of the visitor design pattern
     * @param [in] visitor: visitor to browse
     */
    virtual std::string accept(visitor *visitor) const;
  };

  /**
   * @brief Constructor
   * @param [in] desc: protobuf service descriptor structure
   */
  explicit function(const MethodDescriptor *desc);

  /**
   * @brief Constructor
   * @param [in] name: name of the function
   * @param [in] output: return type
   * @param [in] input: input type
   */
  function(const std::string& name, param *return_type,
    params *args);

  /**
   * @brief destructor
   */
  virtual ~function();

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] visitor: visitor to browse
   */
  virtual std::string accept(visitor *visitor) const;

  /**
   * @brief Get the argument list
   * @return the param list
   */
  const params *get_params() const {
    return _params;
  }

  /**
   * @brief Get the argument list
   * @return the param list
   */
  const param *get_return_type() const {
    return _return;
  }

private:
  params *_params;
  param *_return;
};

};  // namespace ast
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* _AST_SYNAPSE_FUNCTION_HH_ */
