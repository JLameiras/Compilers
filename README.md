# MML compiler (Compilers @ IST)
## Final delivery graded 18/20

The language's standard can be found here [MML Language Reference Guide](https://web.tecnico.ulisboa.pt/~david.matos/w/pt/index.php/Compiladores/Projecto_de_Compiladores/Projecto_2022-2023/Manual_de_Refer%C3%AAncia_da_Linguagem_MML)

The MML compiler components are:
* scanner (`mml_scanner.l`)
* parser (`mml_parser.y`)
* symbol (`targets/symbol.h`)
* type checker (`targets/type_checker.cpp`)
* XML writer (for the middle delivery: `targets/xml_writer.cpp`)
* Postfix writer (for the final delivery: `targets/postfix_writer.cpp`)

Use example:
```
forward int<string> g;
auto f = (string s) -> int {
  g(s);
  return 10;
};
public g = (string n) -> int {
  n!!
  return 14;
};
begin
  f("ola")!!
  return 0;
end
```
