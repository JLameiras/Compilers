#ifndef __MML_AST_ITERATE_NODE_H__
#define __MML_AST_ITERATE_NODE_H__

#include <cdk/ast/expression_node.h>

namespace mml {

  /**
    * Class for describing iterate nodes.
   */
  class iterate_node: public cdk::basic_node {
    cdk::expression_node *_vector;
    cdk::expression_node *_count;
    cdk::expression_node *_function;
    cdk::expression_node *_condition;

  public:
    inline iterate_node(int lineno, cdk::expression_node *vector, cdk::expression_node *count, cdk::expression_node *function,
    cdk::expression_node *condition) :
      cdk::basic_node(lineno), _vector(vector), _count(count), _function(function), _condition(condition) {
    }

  public:
    inline cdk::expression_node *vector() {
      return _vector;
    }
    inline cdk::expression_node *count() {
      return _count;
    }
    inline cdk::expression_node *function() {
      return _function;
    }
    inline cdk::expression_node *condition() {
      return _condition;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_iterate_node(this, level);
    }

  };

} // mml

#endif