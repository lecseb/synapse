/** This file is part of synapse.
 *
 * synapse is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * synapse is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with synapse.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "synapse-ctx_factory.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace header {

void CtxFactory::generate_callback_from_structure(ast::Ast *root,
  ast::Struct *node) {
  /* add contextual include */
  CtxFactory::_generate_allocator_callback(root, node);
}

void CtxFactory::_generate_allocator_callback(ast::Ast *root,
  ast::Struct *node) {
  std::string name = node->get_name();

  /* new allocation function */
  std::string new_comment = "/**\n" \
    " * @brief Allocate a new instance of " + name + "\n" \
    " * @return a valid pointer on success, NULL on error\n" \
    " */";
  std::string new_name = std::string(name + "_new");
  std::list<ast::Field *> new_params = std::list<ast::Field *>();
  std::map<uint32_t, ast::Field *>::const_iterator it;
  for (it = node->get_fields_begin(); it != node->get_fields_end(); it++)
    new_params.push_back(new ast::Field(it->second));
  ast::Field *new_out = new ast::Field(name, FieldDescriptor::TYPE_MESSAGE, true);
  root->add_function(new ast::Function(new_name, new_params, new_out, new_comment));

  /* free allocation function */
  std::string free_comment = "/**\n" \
    " * @brief Deallocate a specific instance of " + name + "\n" \
    " */";
  std::string free_name = std::string(name + "_free");
  std::list<ast::Field *> free_params = std::list<ast::Field *>();
  std::string param_name = std::string(node->get_name() + " *msg");
  free_params.push_back(new ast::Field(param_name, FieldDescriptor::TYPE_MESSAGE));
  root->add_function(new ast::Function(free_name, free_params, NULL, free_comment));
}

void CtxFactory::generate_callback_from_enum(ast::Ast *root, ast::Enum *node)
{
  /* tostring function */
  std::string comment = "/**\n" \
    " * @brief Convert an enum " + node->get_name() + " into a string\n" \
    " * representation\n" \
    " * @return a non empty string on success, an empty one otherwise\n" \
    " */";
  std::string name = std::string(node->get_name() + "_tostring");
  std::list<ast::Field *> params = std::list<ast::Field *>();
  std::string param_name = std::string(node->get_name() + " type");
  params.push_back(new ast::Field(param_name, FieldDescriptor::TYPE_ENUM));
  ast::Field *out = new ast::Field("", FieldDescriptor::TYPE_STRING, true);
  root->add_function(new ast::Function(name, params, out, comment));
}

};  // namespace header
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
