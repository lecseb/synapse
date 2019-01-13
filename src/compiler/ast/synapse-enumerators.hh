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

#ifndef _AST_SYNAPSE_ENUMERATORS_HH_
# define _AST_SYNAPSE_ENUMERATORS_HH_

# include <map>
# include <string>
# include "synapse-enumerator.hh"
# include "synapse-interface.hh"

namespace synapse {
namespace compiler {
namespace ast {

/**
 * @brief Root element of the AST
 */
class enumerators : public interface {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf enumeration descriptor structure
   */
  explicit enumerators(const google::protobuf::EnumDescriptor *desc);

  /**
   * @brief Constructor
   */
  explicit enumerators(const std::initializer_list<enumerator *>& list);

  /**
   * @brief destructor
   */
  virtual ~enumerators();

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] visitor: visitor to browse
   * @return true on success, false otherwise
   */
  virtual bool accept(visitor *visitor) const;

  /**
   * @brief Get the enumerator list
   * @return a list
   */
  const std::map<uint32_t, enumerator *>& get_enumerators() const {
    return _enumerators;
  }

private:
  std::map<uint32_t, enumerator *> _enumerators;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_ENUMERATORS_HH_ */
