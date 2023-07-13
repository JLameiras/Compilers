#ifndef __MML_AST_RETURN_NODE_H__
#define __MML_AST_RETURN_NODE_H__

#include <cdk/ast/basic_node.h>
#include <cdk/ast/expression_node.h>

namespace mml {

  /**
   * Class for describing return nodes.
   */
  class return_node: public cdk::basic_node {
    cdk::expression_node * _value;

  public:
    return_node(int lineno, cdk::expression_node *value) :
            cdk::basic_node(lineno), _value(value) {
    }

  public:
    cdk::expression_node *value() {
      return _value;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_return_node(this, level);
    }

  };

} // mml

#endif
