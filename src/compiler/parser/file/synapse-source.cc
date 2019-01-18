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

#include "synapse-source.hh"
#include "ast/synapse-adaptor.hh"

namespace synapse {
namespace compiler {
namespace parser {
namespace file {

source::source(const params& params, stream *stream,
  definition::interface *definition, declaration::interface *declaration)
  : interface(params, *stream),
    _declaration(declaration),
    _definition(definition) {
  _stream << "/**\n"
    << " * synapse is free software: you can redistribute it and/or modify\n"
    << " * it under the terms of the GNU General Public License as "
    << "published\n"
    << " * by the Free Software Foundation, either version 3 of the License,"
    << "\n"
    << " * or (at your option) any later version.\n"
    << " *\n"
    << " * synapse is distributed in the hope that it will be useful,\n"
    << " * but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
    << " * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
    << " * GNU General Public License for more details.\n"
    << " *\n"
    << " * You should have received a copy of the GNU General Public License"
    << "\n"
    << " * along with synapse.  If not, see <https://www.gnu.org/licenses/>."
    << "\n"
    << " */\n\n";
  std::string name = _stream.get_name();
  std::string header = std::string(name.substr(0, name.size() - 1) + "h");
  _stream << "#include \"" << header << "\"" << stream::endl;
}

source::~source() {
  delete &_stream;
  delete _definition;
  delete _declaration;
}

bool source::parse(const ast::decls *node) {
  bool error = true;

  ast::decls::const_iterator it = node->begin();
  for (; it != node->end(); it++) {
    const ast::decl *decl = (*it);
    error &= decl->accept(this);
  }
  return error;
}

bool source::visite(const ast::enumeration *) {
  /* nothing to do here */
  return true;
}

bool source::visite(const ast::error *node) {
  error::get_instance() << node->get();
  return false;
}

bool source::visite(const ast::include *node) {
  _stream << "#include \"";
  bool error = interface::visite(node);
  _stream << "\"" << stream::endl;
  return error;
}

bool source::visite(const ast::structure *node) {
  _stream << stream::endl;
  bool error = node->accept(_definition);
  _stream << " {" << stream::endl;
  _stream.indent();
  ast::structure::const_iterator it = node->begin();
  for (; it != node->end(); it++) {
    _stream << ast::adaptor::field_tostring(it->second) << ";" << stream::endl;
  }
  _stream.outdent();
  _stream << "};" << stream::endl;
  return error;
}

bool source::visite(const ast::svcs::alloc::allocator *node) {
  bool error = true;

  ast::svcs::alloc::allocator::const_iterator it = node->begin();
  if (it != node->end()) {
    _stream << stream::endl;
    error &= (*it)->accept(_definition);
    _stream << " {" << stream::endl;
    _stream.indent();
    error &= (*it)->accept(_declaration);
    _stream.outdent();
    _stream << "}";
    _stream << stream::endl;
    for (it++; it != node->end(); it++) {
      _stream << stream::endl;
      error &= (*it)->accept(_definition);
      _stream << " {" << stream::endl;
      _stream.indent();
      error &= (*it)->accept(_declaration);
      _stream.outdent();
      _stream << "}";
      _stream << stream::endl;
    }
  }
  return error;
}
};  // namespace file
};  // namespace parser
};  // namespace compiler
};  // namespace synapse
