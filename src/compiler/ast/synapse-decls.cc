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

#include "ast/synapse-decls.hh"
#include "ast/synapse-enumeration.hh"
#include "ast/synapse-error.hh"
#include "ast/synapse-include.hh"
#include "ast/synapse-structure.hh"
#include "ast/synapse-type.hh"
#include "ast/types/synapse-enumeration.hh"
#include "ast/types/synapse-enumerator.hh"
#include "ast/types/synapse-simple.hh"
#include "ast/types/synapse-structure.hh"

namespace synapse {
namespace compiler {
namespace ast {

static std::vector<ast::structure *> _generate_dependencies() {
  structure::fields args;
  std::vector<ast::structure *> deps = std::vector<ast::structure *>({
      new ast::structure("s_synapse_bytes", args),
      new ast::structure("s_synapse_list", args),
  });
  return deps;
}

decls::decls(const google::protobuf::FileDescriptor *desc)
  : _deps(_generate_dependencies()) {
  /* create all include needed */
  for (int32_t i = 0; i < desc->dependency_count(); i++)
    parse(desc->dependency(i));

  /* create all enumeration */
  for (int32_t i = 0; i < desc->enum_type_count(); i++)
    parse(desc->enum_type(i));

  /* create all structure and function needed */
  for (int32_t i = 0; i < desc->message_type_count(); i++)
    parse(desc->message_type(i));
}

decls::~decls() {
  for (decls::iterator it = begin(); it != end(); it++)
    delete it->second;

  std::vector<ast::structure *>::iterator dep = _deps.begin();
  for (; dep != _deps.end(); dep++)
    delete *dep;
}

const ast::enumeration *decls::get_enumeration(
    const std::string& name) const {
  decls::const_iterator it = find(name);

  if (it != end()) {
    const ast::decl *decl = it->second;
    const ast::enumeration *res = dynamic_cast<const ast::enumeration *>(decl);
    if (typeid(*it->second) == typeid(ast::enumeration) &&
          res && res->get_name() == name) {
      return res;
    }
  }
  return nullptr;
}

const ast::structure *decls::get_structure(
    const std::string& name) const {
  decls::const_iterator it = find(name);

  if (it != end()) {
    const ast::decl *decl = it->second;
    const ast::structure *res = dynamic_cast<const ast::structure *>(decl);
    if (typeid(*it->second) == typeid(ast::structure) &&
          res && res->get_name() == name) {
      return res;
    }
  }
  return nullptr;
}

void decls::parse(const google::protobuf::Descriptor *desc) {
  ast::structure *decl = nullptr;
  ast::structure::fields fields;

  std::vector<ast::structure *>::iterator dep = _deps.begin();
  for (; dep != _deps.end(); dep++)
    (*this)[(*dep)->get_name()] = (*dep);

  for (int32_t i = 0; i < desc->field_count(); i++) {
    fields[i] = ast::type::create(desc->field(i), *this);
    if (!fields[i])
      goto error;
  }

  for (dep = _deps.begin(); dep != _deps.end(); dep++)
    erase(find((*dep)->get_name()));

  decl = new ast::structure(desc->name(), fields);
  if (!decl)
    goto error;

  (*this)[desc->name()] = decl;
  ast::structure::factory::create_new(decl);
  ast::structure::factory::create_free(decl);
  ast::structure::factory::create_dup(decl);
  return;

error:
  (*this)[desc->name()] = new error(desc, "failed to create " + desc->name());

  structure::fields::iterator field = fields.end();
  for (field = fields.begin(); field != fields.end(); field++)
    delete field->second;
}

void decls::parse(const google::protobuf::EnumDescriptor *desc) {
  enumeration::enumerators enums;

  for (int32_t i = 0; i < desc->value_count(); i++) {
    const google::protobuf::EnumValueDescriptor *value = desc->value(i);
    enums[i] = new ast::types::enumerator(value->name(),
      std::to_string(value->number()));
  }

  ast::decl *decl = new ast::enumeration(desc->name(), enums);
  if (decl) {
    (*this)[desc->name()] = decl;
  } else {
    decl = new error(desc, "failed to create " + desc->name());
    (*this)[desc->name()] = decl;
  }
}

void decls::parse(const google::protobuf::FileDescriptor *desc) {
  ast::decl *decl = new ast::include(desc->name());
  if (decl) {
    (*this)[desc->name()] = decl;
  } else {
    decl = new error("failed to create " + desc->name());
    (*this)[desc->name()] = decl;
  }
}

};  // namespace ast
};  // namespace compiler
};  // namespace synapse
