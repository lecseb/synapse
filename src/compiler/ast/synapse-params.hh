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

#ifndef _AST_SYNAPSE_PARAMS_HH_
# define _AST_SYNAPSE_PARAMS_HH_

# include <list>
# include <string>
# include "synapse-interface.hh"
# include "synapse-param.hh"

namespace synapse {
namespace compiler {
namespace ast {

/**
 * @brief Root element of the AST
 */
class params : public interface {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf structure
   */
  explicit params(const google::protobuf::Descriptor *desc);

  /**
   * @brief Constructor
   */
  explicit params(const std::initializer_list<param *>& list);

  /**
   * @brief destructor
   */
  virtual ~params();

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] visitor: visitor to browse
   * @return true on success, false otherwise
   */
  virtual bool accept(visitor *visitor) const;

  /**
   * @brief Add manually parameter into the list
   * @param [in] param: parameter to add
   */
  virtual void add_param(param *param) {
    _params.push_back(param);
  }

  /**
   * @brief Get the parameter list
   * @return the param list
   */
  const std::list<param *>& get_params() const {
    return _params;
  }

private:
  std::list<param *> _params;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_PARAMS_HH_ */
