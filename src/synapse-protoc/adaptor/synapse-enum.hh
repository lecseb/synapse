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

#ifndef _ADAPTOR_SYNAPSE_ENUM_HH_
# define _ADAPTOR_SYNAPSE_ENUM_HH_

# include <map>
# include <string>
# include <google/protobuf/descriptor.h>
# include "synapse-element.hh"
# include "synapse-label.hh"

namespace google {
namespace protobuf {
namespace compiler {
namespace adaptor {

/**
 * @brief C enumeration representation
 */
class Enum : public Element {
public:
  /**
   * @brief Constructor
   * @param [in] desc: protobuf enumeration representation
   */
  explicit Enum(const EnumDescriptor *desc)
    : _labels(std::map<uint32_t, Label *>()),
      _name(desc->name()) {
    for (int32_t i = 0; i < desc->value_count(); i++) {
      const EnumValueDescriptor *label = desc->value(i);
      _labels[label->number()] = new Label(label);
    }
  }

  /**
   * @brief Destructor
   */
  virtual ~Enum() {
    std::map<uint32_t, Label *>::iterator it = _labels.begin();
    for (; it != _labels.end(); it++)
      delete it->second;
  }

  /**
   * @brief part of the visitor design pattern
   */
  virtual std::string accept(Visitor *visitor) const {
    return visitor->visite(this);
  }

  /**
   * @brief Get the enumeration name
   * @return the enum string name
   */
  virtual std::string get_name() const {
    return _name;
  }

  /**
   * @brief Get an iterator over the first element contained in the enum
   * @return a valid iterator
   */
  std::map<uint32_t, Label *>::const_iterator get_label_begin() const {
    return _labels.begin();
  }

  /**
   * @brief Get an iterator over the last element contained in the enum
   * @return a valid iterator
   */
  std::map<uint32_t, Label *>::const_iterator get_label_end() const {
    return _labels.end();
  }

private:
  std::map<uint32_t, Label *> _labels;
  std::string _name;
};

};  // namespace adaptor
};  // namespace compiler
};  // namespace protobuf
};  // namespace google

#endif /* !_ADAPTOR_SYNAPSE_ENUM_HH_ */
