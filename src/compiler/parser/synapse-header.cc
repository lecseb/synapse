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

#include "synapse-error.hh"
#include "synapse-header.hh"

namespace synapse {
namespace compiler {
namespace parser {

header::header(const params& params, stream *stream,
  definition::interface *definition)
  : _definition(definition),
    _params(params),
    _services(std::map<std::string, bool>({{ "io", false }})),
    _stream(stream) {
  std::string temp = std::string("_" + _stream->get_name() + "_");
  std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
  std::replace_if(temp.begin(), temp.end(), ispunct, '_');

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
  (*_stream) << "#ifndef " << temp << stream::endl;
  (*_stream) << "# define " << temp << stream::endl;
  (*_stream) << stream::endl;
}

header::~header() {
  std::string temp = std::string("_" + _stream->get_name() + "_");
  std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
  std::replace_if(temp.begin(), temp.end(), ispunct, '_');
  (*_stream) << "#endif /* !" << temp << " */" << stream::endl;
  delete _stream;
  delete _definition;
}

bool header::parse(const ast::decls *node) {
  bool error = true;
  const std::list<ast::decl *>& decls = node->get_declarations();
  std::list<ast::decl *>::const_iterator it_decls = decls.begin();

  for (; it_decls != decls.end(); it_decls++) {
    const ast::decl *decl = (*it_decls);
    if (typeid(*decl) == typeid(ast::service)) {
      _parse(dynamic_cast<const ast::service *>(decl));
    } else {
      error &= decl->accept(_definition);
      if (typeid(*decl) != typeid(ast::include))
	(*_stream) << ";" << stream::endl;
      else
	(*_stream) << stream::endl;
      (*_stream) << stream::endl;
    }
  }
  return error;
}

bool header::_parse(const ast::service *node) {
  bool error = true;
  const std::list<ast::function *>& functions = node->get_functions();

  if (_services.find(node->get_name()) == _services.end()) {
    error::get_instance() << node->get_name() << ": unknown service\n";
    return false;
  }

  std::list<ast::function *>::const_iterator it_functions = functions.begin();
  for (; it_functions != functions.end(); it_functions++) {
    const ast::function *function = (*it_functions);
    error &= _parse(function);
    (*_stream) << stream::endl;
  }
  return error;
}

bool header::_parse(const ast::function *node) {
  bool error = node->accept(_definition);
  (*_stream) << ";" << stream::endl;
  return error;
}

};  // namespace parser
};  // namespace compiler
};  // namespace synapse
