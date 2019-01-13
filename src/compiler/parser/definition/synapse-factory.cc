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

#include "synapse-factory.hh"

namespace synapse {
namespace compiler {
namespace parser {
namespace definition {

bool factory::visite(const ast::decls *node) {
  bool error = true;
  const std::list<ast::decl *>& decls = node->get_declarations();

  std::list<ast::decl *>::const_iterator decl = decls.begin();
  for (; decl != decls.end(); decl++) {
    error &= (*decl)->accept(this);
  }
  return error;
}

bool factory::visite(const ast::enumeration *node) {
  /* tostring function */
  ast::decl *func = new ast::function(
    std::string(node->get_name() + "_tostring"),
    new ast::function::out(
      new ast::composite(
	google::protobuf::FieldDescriptor::TYPE_STRING,
	std::string(),
	true)),
      new ast::params({
	new ast::param(
	  std::string("type"),
          new ast::composite(
	    google::protobuf::FieldDescriptor::TYPE_ENUM,
	    node->get_name()))
      }));
  _decls->add_decl(func);
  return true;
}

bool factory::visite(const ast::structure *node) {
  /* new function */
  ast::params *new_params = new ast::params({});
  const ast::fields *new_fields = node->get_fields();
  if (new_fields) {
    const std::map<uint32_t, ast::field *>& fields = new_fields->get_fields();
    std::map<uint32_t, ast::field *>::const_iterator it = fields.begin();
    for (; it != fields.end(); it++) {
      ast::field *field = it->second;
      ast::composite *type = new ast::composite(field->get_type());
      new_params->add_param(new ast::param(field->get_name(), type));
    }
  }
  ast::decl *new_func = new ast::function(
    std::string(node->get_name() + "_new"),
    new ast::function::out(
      new ast::composite(
	google::protobuf::FieldDescriptor::TYPE_MESSAGE,
	node->get_name(),
	true)),
      new_params);
  _decls->add_decl(new_func);

  /* free function */
  ast::decl *free_func = new ast::function(
    std::string(node->get_name() + "_free"),
    NULL,
    new ast::params({
      new ast::param(
	std::string("msg"),
        new ast::composite(
	  google::protobuf::FieldDescriptor::TYPE_MESSAGE,
	  node->get_name(),
	  true))
	}));
  _decls->add_decl(free_func);
  return true;
}

};  // namespace definition
};  // namespace parser
};  // namespace compiler
};  // namespace synapse
