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

#ifndef _AST_SYNAPSE_STRUCTURE_HH_
# define _AST_SYNAPSE_STRUCTURE_HH_

# include <map>
# include <string>
# include "ast/synapse-decl.hh"
# include "ast/synapse-function.hh"
# include "ast/synapse-type.hh"

namespace synapse {
namespace compiler {
namespace ast {

/**
 * @brief structure description
 */
class structure : public std::map<uint32_t, ast::type *>, public ast::decl {
public:
  /**
   * @brief structure factory description
   */
  class factory {
  public:
    /**
     * @brief Create the new allocator function
     * @param [in] structure: structure concerned by the function
     */
    static void create_new(ast::structure *structure);

    /**
     * @brief Create the free allocator function
     * @param [in] structure: structure concerned by the function
     */
    static void create_free(ast::structure *structure);

    /**
     * @brief Create the dup allocator function
     * @param [in] structure: structure concerned by the function
     */
    static void create_dup(ast::structure *structure);
  };

  /**
   * @brief Functions container description
   */
  class functions : public std::map<std::string, ast::function *> {
  public:
    /**
     * @brief Destructor
     */
    virtual ~functions() {
      iterator it = begin();
      for (; it != end(); it++)
	delete it->second;
    }
  };

  /**
   * @brief Fields container description
   */
  typedef std::map<uint32_t, ast::type *> fields;

  /**
   * @brief Constructor
   * @param [in] name: name of the structure
   * @param [in] fields: structure's field data
   */
  structure(const std::string& name, const fields& fields);

  /**
   * @brief destructor
   */
  virtual ~structure();

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] stream: file stream
   * @param [in] visitor: visitor to browse
   */
  virtual void accept(stream& stream, visitor *visitor) const;

  /**
   * @brief Add a function to the structure
   * @param [in] func: function to add
   */
  void add_function(ast::function *func);

  /**
   * @brief Add a function to the structure
   * @param [in] func: function to add
   */
  const functions& get_functions() const {
    return _funcs;
  }

  /**
   * @brief Get the name of the enumeration
   * @return a string
   */
  const std::string& get_name() const {
    return _name;
  }

private:
  functions _funcs;
  std::string _name;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_STRUCTURE_HH_ */
