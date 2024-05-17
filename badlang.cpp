#include <iostream>
#include <fstream>
int main() {
  std::cout << "Welcome to BADLANG!\n\nWhat to compile?\n> ";
  std::string filename;
  std::cin >> filename;
  std::ifstream file(filename);
  std::string code;
  std::string out="int main() {\n";
  std::string tmp_arg;
  int print=0;
  while (std::getline(file, code)) {
    if (code=="print") {
      std::getline(file, code);
      out=out+" std::cout << "+code+";\n";
      print=1;
    }
    else if (code=="input") {
      std::getline(file, code);
      out=out+" std::cin >> "+code+";\n";
      print=1;
    }
    else if (code=="int") {
      std::getline(file, code);
      out=out+" int "+code+";\n";
    }
    else if (code=="string") {
      std::getline(file, code);
      out=out+" std::string "+code+";\n";
      print=1;
    }
    else if (code=="var=") {
      std::getline(file, code);
      tmp_arg=code;
      std::getline(file, code);
      out=out+" "+tmp_arg+"="+code+";\n";
    }
    else if (code=="var+") {
      std::getline(file, code);
      tmp_arg=code;
      std::getline(file, code);
      out=out+" "+tmp_arg+"="+tmp_arg+"+"+code+";\n";
    }
    else if (code=="var-") {
      std::getline(file, code);
      tmp_arg=code;
      std::getline(file, code);
      out=out+" "+tmp_arg+"="+tmp_arg+"-"+code+";\n";
    }
  }
  out=out+"}";
  if (print==1) {
    out="#include <iostream>\n"+out;
  }
  file.close();
  std::cin >> filename;
  std::ofstream fileout(filename);
  fileout << out;
  fileout.close();
}
