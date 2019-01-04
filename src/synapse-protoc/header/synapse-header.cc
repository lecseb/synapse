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

#include "synapse-header.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace header {

Synapse::Synapse(const FileDescriptor *desc, OutputDirectory *out)
  : Header(desc, out, ".synapse.h") {
}

Synapse::~Synapse() {
}

bool Synapse::generate(const std::string&, std::string *error) {
  std::string preproc = std::string("_GENERATE_" + _full_name + "_");
  std::transform(preproc.begin(), preproc.end(), preproc.begin(), ::toupper);
  std::replace_if(preproc.begin(), preproc.end(), ispunct, '_');
  /* write preproc protection */
  _io_printer->Print(std::string("#ifndef " + preproc + "\n").c_str());
  _io_printer->Print(std::string("# define " + preproc + "\n").c_str());
  _io_printer->Print("\n");

  /* write list of enum */
  for (int32_t i = 0; i < _desc->enum_type_count(); i++) {
    const EnumDescriptor *desc = _desc->enum_type(i);
    generate_enum(desc, error);
    _io_printer->Print("\n");
  }
  /* write list of message */
  for (int32_t i = 0; i < _desc->message_type_count(); i++) {
    const Descriptor *desc = _desc->message_type(i);
    std::string name = desc->name();
    std::string type = std::string("struct " + name);
    _io_printer->Print(std::string(type + ";\n").c_str());
    _io_printer->Print("\n");
  }
  /* write the list of services */
  for (int32_t i = 0; i < _desc->service_count(); i++) {
    const ServiceDescriptor *desc = _desc->service(i);
    generate_service(desc, error);
    _io_printer->Print("\n");
  }
  _io_printer->Print(std::string("#endif /* !" + preproc + "*/\n").c_str());
  return true;
}

void Synapse::generate_enum(const EnumDescriptor *desc, std::string *) {
  _io_printer->Print(std::string("enum " + desc->name() + " {\n").c_str());
  _io_printer->Indent();
  for (int32_t i = 0; i < desc->value_count(); i++) {
    const EnumValueDescriptor *value = desc->value(i);
    _io_printer->Print(std::string(value->name() + " = " +
      std::to_string(value->number()) + ";\n").c_str());
  }
  _io_printer->Outdent();
  _io_printer->Print("};\n");
}

void Synapse::generate_service(const ServiceDescriptor *desc,
  std::string *) {
  for (int32_t i = 0; i < desc->method_count(); i++) {
    const MethodDescriptor *mth = desc->method(i);
    std::string in = std::string("struct " + mth->input_type()->name());
    std::string params = std::string("(" + in + " *msg)");
    std::string out = std::string("struct " +  mth->output_type()->name());
    std::string svc = std::string(out + " *" + mth->name() + params);
    _io_printer->Print(std::string(svc + ";\n").c_str());
  }
}

};  // namespace header
};  // namespace compiler
};  // namespace protobuf
};  // namespace google
