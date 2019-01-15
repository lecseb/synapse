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
  : _declaration(declaration),
    _definition(definition),
    _params(params),
    _stream(stream) {
  (*_stream) << "/**\n"
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
  std::string name = _stream->get_name();
  std::string header = std::string(name.substr(0, name.size() - 1) + "h");
  (*_stream) << "#include \"" << header << "\"" << stream::endl;
  (*_stream) << stream::endl;
}

source::~source() {
  delete _stream;
  delete _definition;
  delete _declaration;
}

bool source::parse(const ast::decls *node) {
  bool error = true;
  const std::list<ast::decl *>& decls = node->get_declarations();
  std::list<ast::decl *>::const_iterator it_decls = decls.begin();

  for (; it_decls != decls.end(); it_decls++) {
    const ast::decl *decl = (*it_decls);
    error &= decl->accept(_definition);
    if (typeid(*decl) != typeid(ast::include)) {
      (*_stream) << " {" << stream::endl;
      (*_stream) << "}";
    }
    (*_stream) << stream::endl << stream::endl;
  }
  return error;
}

};  // namespace parser
};  // namespace compiler
};  // namespace synapse
