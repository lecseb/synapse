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

#ifndef _PARSER_SYNAPSE_INTERFACE_HH_
# define _PARSER_SYNAPSE_INTERFACE_HH_

# include <string>
# include <google/protobuf/descriptor.h>
# include "ast/synapse-visitor.hh"

namespace synapse {
namespace compiler {
namespace parser {

/**
 * @brief generic parser implementation
 */
class interface : public ast::visitor {
public:
  /**
   * @brief protoc option representation
   */
  class option {
  public:
    option()
      : brief("unknown"),
	cmd("unknown"),
	name("unknown") {}

    option(const std::string& opt_name, const std::string& opt_cmd,
	const std::string& opt_brief)
      : brief(opt_brief),
	cmd(opt_cmd),
	name(opt_name) {}

    bool operator==(const option& opt) {
      return brief == opt.brief && cmd == opt.cmd && name == opt.name;
    }

    std::string brief;
    std::string cmd;
    std::string name;
  };

  /**
   * @brief Destructor
   */
  virtual ~interface() {}

  /**
   * @brief Order the parsing and start the ast construction
   * @param [in] desc: protobuf file structure
   * @return a string
   */
  virtual std::string parse(const google::protobuf::FileDescriptor *desc) {
    ast::decls *_decls = new ast::decls(desc);
    std::string error = _decls->accept(this);
    delete _decls;
    return error;
  }

  /**
   * @brief Visite an composite node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::composite *node) = 0;

  /**
   * @brief Visite an decls node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::decls *node) = 0;

  /**
   * @brief Visite an enumeration node
   * @param [in] node: node node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::enumeration *node) = 0;

  /**
   * @brief Visite an enumerator node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::enumerator *node) = 0;

  /**
   * @brief Visite an enumerators node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::enumerators *node) = 0;

  /**
   * @brief Visite an field node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::field *node) = 0;

  /**
   * @brief Visite an fields node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::fields *node) = 0;

  /**
   * @brief Visite an function node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::function *node) = 0;

  /**
   * @brief Visite an function output node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::function::out *node) = 0;

  /**
   * @brief Visite an include node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::include *node) = 0;

  /**
   * @brief Visite an param node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::param *node) = 0;

  /**
   * @brief Visite an params node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::params *node) = 0;

  /**
   * @brief Visite an structure node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::service *node) = 0;

  /**
   * @brief Visite an structure node
   * @param [in] node: node to visite
   * @return a string representation of an error
   */
  virtual std::string visite(const ast::structure *node) = 0;
};

};  // namespace parser
};  // namespace compiler
};  // namespace synapse

#endif /* !_PARSER_SYNAPSE_PARSER_HH_ */