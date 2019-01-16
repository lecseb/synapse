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

namespace synapse {
namespace compiler {
namespace parser {

source::source(const params& params, stream *stream,
  definition::interface *definition, declaration::interface *declaration)
  : file(params, *stream),
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
  _stream << stream::endl;
}

source::~source() {
  delete &_stream;
  delete _definition;
  delete _declaration;
}

bool source::parse(const ast::decls *node) {
  bool error = true;

  const ast::decls::map& decls = node->get_elements();
  ast::decls::const_iterator it = decls.begin();
  for (; it != decls.end(); it++) {
    const ast::decl *decl = it->second;
    error &= decl->accept(this);
    _stream << stream::endl;
  }
  return error;
}

bool source::visite(const ast::include *node) {
  _stream << "#include <" << node->get_name() << ">";
  return true;
}

bool source::visite(const ast::function *node) {
  bool error = node->accept(_definition);
  _stream << stream::endl;
  _stream << "{" << stream::endl;
  _stream << "}" << stream::endl;
  return error;
}

bool source::visite(const ast::structure *node) {
  bool error = node->accept(_definition);
  _stream << stream::endl;
  _stream << "{" << stream::endl;
  _stream << "}" << stream::endl;
  return error;
}

};  // namespace parser
};  // namespace compiler
};  // namespace synapse
