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
# include "synapse-composite.hh"
# include "synapse-decl.hh"
# include "synapse-elements.hh"
# include "synapse-structure.hh"

namespace synapse {
namespace compiler {
namespace ast {

/**
 * @brief Function element of the AST
 */
class function : public decl {
public:
  /**
   * @brief output element
   */
  class output : public interface {
  public:
    /**
     * @brief Constructor
     * @param [in] desc: protobuf descriptor structure
     */
    output(const google::protobuf::Descriptor *desc);

    /**
     * @brief Destructor
     */
    virtual ~output() {}

    /**
     * @brief Accept function of the visitor design pattern
     * @param [in] visitor: visitor to browse
     * @return true on success, false otherwise
     */
    virtual bool accept(visitor *visitor) const;

    /**
     * @brief Get the type
     * @return a string
     */
    const std::string& get_type() const {
      return _type;
    }

  private:
    std::string _type;
  };

  /**
   * @brief param element
   */
  class param : public output {
  public:
    /**
     * @brief Constructor
     * @param [in] name: name of the parameter
     * @param [in] desc: protobuf descriptor structure
     */
    param(const std::string& name, const google::protobuf::Descriptor *desc);

    /**
     * @brief destructor
     */
    virtual ~param() {}

    /**
     * @brief Accept function of the visitor design pattern
     * @param [in] visitor: visitor to browse
     * @return true on success, false otherwise
     */
    virtual bool accept(visitor *visitor) const;

    /**
     * @brief get the name
     * @return a string
     */
    const std::string& get_name() const {
      return _name;
    }

  private:
    std::string _name;
  };

  /**
   * @brief Constructor
   * @param [in] desc: protobuf service descriptor structure
   */
  explicit function(const google::protobuf::MethodDescriptor *desc);

  /**
   * @brief destructor
   */
  virtual ~function();

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] visitor: visitor to browse
   * @return true on success, false otherwise
   */
  virtual bool accept(visitor *visitor) const;

  /**
   * @brief Get the argument list
   * @return the param list
   */
  const param *get_param() const {
    return _param;
  }

  /**
   * @brief Get the argument list
   * @return the param list
   */
  const output *get_return_type() const {
    return _return;
  }

private:
  param *_param;
  output *_return;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_FUNCTION_HH_ */
