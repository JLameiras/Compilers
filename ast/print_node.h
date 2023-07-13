#ifndef __MML_AST_PRINT_NODE_H__
#define __MML_AST_PRINT_NODE_H__

#include <cdk/ast/sequence_node.h>

namespace mml {

  /**
   * Class for describing print nodes.
   */
  class print_node: public cdk::basic_node {
    cdk::sequence_node *_arguments;
    bool _newline = false;

  public:
    inline print_node(int lineno, cdk::sequence_node *argument, bool newline = false) :
            cdk::basic_node(lineno), _arguments(argument), _newline(newline) {
    }

  public:
    inline cdk::sequence_node *arguments() {
      return _arguments;
    }
    cdk::expression_node *argument(size_t ax) {
      return dynamic_cast<cdk::expression_node*>(_arguments->node(ax));
    }
    inline bool newline() {
      return _newline;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_print_node(this, level);
    }

  };

} // mml

#endif