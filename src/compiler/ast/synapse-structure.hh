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

#ifndef _AST_SYNAPSE_STRUCTURE_HH_
# define _AST_SYNAPSE_STRUCTURE_HH_

# include <map>
# include <string>
# include "synapse-composite.hh"
# include "synapse-decl.hh"
# include "synapse-elements.hh"

namespace synapse {
namespace compiler {
namespace ast {

/**
 * @brief Root element of the AST
 */
class structure : public decl {
public:
  /**
   * @brief field element
   */
  class field : public interface {
  public:
    /**
     * @brief Constructor
     * @param [in] desc: protobuf field descriptor structure
     */
    explicit field(const google::protobuf::FieldDescriptor *desc);

    /**
     * @brief destructor
     */
    virtual ~field();

    /**
     * @brief Accept function of the visitor design pattern
     * @param [in] visitor: visitor to browse
     * @return true on success, false otherwise
     */
    virtual bool accept(visitor *visitor) const;

    /**
     * @brief Get the declared name
     * @return a string
     */
    const std::string& get_name() const {
      return _desc->name();
    }

    /**
     * @brief Get the declared type
     * @return a type
     */
    composite *get_composite() const {
      return _composite;
    }

  private:
    const google::protobuf::FieldDescriptor *_desc;
    composite *_composite;
  };

  /**
   * @brief field list
   */
  class fields : public elements<field>, public interface {
  public:
    /**
     * @brief Map typedef
     */
    typedef std::map<uint32_t, fields *> map;
    typedef std::map<uint32_t, fields *>::const_iterator const_iterator;

    /**
     * @brief Constructor
     * @param [in] desc: protobuf descriptor structure
     */
    explicit fields(const google::protobuf::Descriptor *desc);

    /**
     * @brief destructor
     */
    virtual ~fields() {}

    /**
     * @brief Accept function of the visitor design pattern
     * @param [in] visitor: visitor to browse
     * @return true on success, false otherwise
     */
    virtual bool accept(visitor *visitor) const;
  };

  /**
   * @brief Constructor
   * @param [in] desc: protobuf structure descriptor
   */
  explicit structure(const google::protobuf::Descriptor *desc);

  /**
   * @brief destructor
   */
  virtual ~structure();

  /**
   * @brief Accept function of the visitor design pattern
   * @param [in] visitor: visitor to browse
   * @return true on success, false otherwise
   */
  virtual bool accept(visitor *visitor) const;

  /**
   * @brief Get all fields contained into the structure
   * @return a valid pointer
   */
  const fields *get_fields() const {
    return _fields;
  }

private:
  const google::protobuf::Descriptor *_desc;
  fields *_fields;
};

};  // namespace ast
};  // namespace compiler
};  // namespace synapse

#endif /* _AST_SYNAPSE_STRUCTURE_HH_ */
