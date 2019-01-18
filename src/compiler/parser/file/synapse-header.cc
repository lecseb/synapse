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
namespace file {

header::header(const params& params, stream *stream,
  definition::interface *definition)
  : interface(params, *stream),
    _definition(definition),
    _services(std::map<std::string, bool>()) {
  std::string temp = std::string("_" + _stream.get_name() + "_");
  std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
  std::replace_if(temp.begin(), temp.end(), ispunct, '_');

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
  _stream << "#ifndef " << temp << stream::endl;
  _stream << "# define " << temp << stream::endl;
  _stream << stream::endl;
}

header::~header() {
  _stream << stream::endl;
  std::string temp = std::string("_" + _stream.get_name() + "_");
  std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
  std::replace_if(temp.begin(), temp.end(), ispunct, '_');
  _stream << "#endif /* !" << temp << " */" << stream::endl;
  delete &_stream;
  delete _definition;
}

bool header::parse(const ast::decls *node) {
  bool error = true;

  ast::decls::const_iterator it = node->begin();
  for (; it != node->end(); it++) {
    const ast::decl *decl = (*it);
    error &= decl->accept(this);
  }
  return error;
}

bool header::visite(const ast::enumeration *node) {
  _stream << stream::endl;
  bool error = node->accept(_definition);
  _stream << ";" << stream::endl;
  return error;
}

bool header::visite(const ast::error *node) {
  error::get_instance() << node->get();
  return false;
}

bool header::visite(const ast::include *node) {
  _stream << "# include <";
  bool error = interface::visite(node);
  _stream << ">";
  _stream << stream::endl;
  return error;
}

bool header::visite(const ast::structure *node) {
  _stream << stream::endl;
  bool error = node->accept(_definition);
  _stream << ";" << stream::endl;
  return error;
}

bool header::visite(const ast::svcs::alloc::allocator *node) {
  bool error = true;

  ast::svcs::alloc::allocator::const_iterator it = node->begin();
  if (it != node->end()) {
    _stream << stream::endl;
    error &= (*it)->accept(_definition);
    _stream << ";" << stream::endl;

    for (it++; it != node->end(); it++) {
      _stream << stream::endl;
      error &= (*it)->accept(_definition);
      _stream << ";" << stream::endl;
    }
  }
  return error;
}

};  // namespace file
};  // namespace parser
};  // namespace compiler
};  // namespace synapse
