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

#ifndef _PROTOC_HEADER_SYNAPSE_HEADER_H_
# define _PROTOC_HEADER_SYNAPSE_HEADER_H_

# include <google/protobuf/stubs/common.h>
# include "protoc-header.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace header {

class Synapse : public Header {
public:
  /**
   * @brief Generate a generic file
   * @param [in] desc: proto description class
   * @param [in] out: proto output description class
   */
  explicit Synapse(const FileDescriptor *desc, OutputDirectory *out)
    : Header(desc, out, ".synapse.h") {}

  /**
   * @brief Destructor
   */
  virtual ~Synapse() {};

  /**
   * @brief Generates code for the given proto file, generating one or more
   * files in the given output directory. A parameter to be passed to the
   * generator can be specified on the command line. This is intended to be used
   * to pass generator specific parameters. It is empty if no parameter was
   * given. ParseGeneratorParameter (below), can be used to accept multiple
   * parameters within the single parameter command line flag.
   * @return true if successful. Otherwise, sets *error to a description of the
   * problem (e.g. "invalid parameter") and returns false.
   */
  virtual bool generate(const std::string& param, std::string *error) {
    std::string preproc = std::string("_GENERATE_" + _full_name + "_");
    std::transform(preproc.begin(), preproc.end(), preproc.begin(), ::toupper);
    std::replace_if(preproc.begin(), preproc.end(), ispunct, '_');
    /* write preproc protection */
    _io_printer->Print(std::string("#ifndef " + preproc + "\n").c_str());
    _io_printer->Print(std::string("# define " + preproc + "\n").c_str());
    _io_printer->Print("\n");

    /* write list of enum */
    for (uint32_t i = 0; i < _desc->enum_type_count(); i++) {
      const EnumDescriptor *desc = _desc->enum_type(i);
      generate_enum(desc, error);
      _io_printer->Print("\n");
    }
    /* write list of message */
    for (uint32_t i = 0; i < _desc->message_type_count(); i++) {
      const Descriptor *desc = _desc->message_type(i);
      std::string name = desc->name();
      std::string type = std::string("struct " + name);
      _io_printer->Print(std::string(type + ";\n").c_str());
      //generate_create_delete_handler(desc);
      _io_printer->Print("\n");
    }
    /* write the list of services */
    for (uint32_t i = 0; i < _desc->service_count(); i++) {
      const ServiceDescriptor *desc = _desc->service(i);
      generate_service(desc, error);
      _io_printer->Print("\n");
    }
    _io_printer->Print(std::string("#endif /* !" + preproc + "*/\n").c_str());
    return true;
  }

  virtual void generate_enum(const EnumDescriptor *desc, std::string *error) {
    _io_printer->Print(std::string("enum " + desc->name() + " {\n").c_str());
    _io_printer->Indent();
    for (uint32_t i = 0; i < desc->value_count(); i++) {
      const EnumValueDescriptor *value = desc->value(i);
      _io_printer->Print(std::string(value->name() + " = " +
        std::to_string(value->number()) + ";\n").c_str());
    }
    _io_printer->Outdent();
    _io_printer->Print("};\n");
  }

  virtual void generate_service(const ServiceDescriptor *desc,
      std::string *error) {
    std::string out, in, params;

    for (uint32_t i = 0; i < desc->method_count(); i++) {
      const MethodDescriptor *mth = desc->method(i);
      std::string in = std::string("struct " + mth->input_type()->name());
      std::string params = std::string("(" + in + " *msg)");
      std::string out = std::string("struct " +  mth->output_type()->name());
      std::string svc = std::string(out + " *" + mth->name() + params);
      _io_printer->Print(std::string(svc + ";\n").c_str());
    }
  }
};

};  // namespace header
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_PROTOC_HEADER_SYNAPSE_HEADER_H_ */
