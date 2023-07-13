#ifndef __MML_AST_INDEX_POINTER_NODE_H__
#define __MML_AST_INDEX_POINTER_NODE_H__

#include <cdk/ast/lvalue_node.h>
#include <cdk/ast/expression_node.h>

namespace mml {

  /**
    * Class for describing index_pointer nodes.
   */
  class index_pointer_node: public cdk::lvalue_node {
    cdk::expression_node *_base, *_index;

  public:
    inline index_pointer_node(int lineno, cdk::expression_node *base, cdk::expression_node *index) :
      cdk::lvalue_node(lineno), _base(base), _index(index) {
    }

  public:
    inline cdk::expression_node *base() {
      return _base;
    }
    inline cdk::expression_node *index() {
      return _index;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_index_pointer_node(this, level);
    }

  };

} // mml

#endif