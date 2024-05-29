#include <iostream>
#include <fstream>
#include <string>
int main() {
  std::cout << "Welcome to BADLANG!\n\nWhat to compile?\nIN BADLANG > ";
  std::string filename;
  std::cin >> filename;
  std::ifstream file(filename);
  std::string code;
  std::string out="int main() {\n";
  std::string tmp_arg;
  int print=0;
  int string_=0;
  int files=0;
  while (std::getline(file, code)) {
    if (code=="==") {
      out=out+"}\n";
    }
    else if (code=="print") {
      std::getline(file, code);
      out=out+"std::cout << "+code+";\n";
      print=1;
    }
    else if (code=="input") {
      std::getline(file, code);
      out=out+"std::cin >> "+code+"_;\n";
      print=1;
    }
    else if (code=="int") {
      std::getline(file, code);
      out=out+"int "+code+"_;\n";
    }
    else if (code=="string") {
      std::getline(file, code);
      out=out+"std::string "+code+"_;\n";
      print=1;
    }
    else if (code=="var=") {
      std::getline(file, code);
      tmp_arg=code;
      std::getline(file, code);
      out=out+tmp_arg+"="+code+"_;\n";
    }
    else if (code=="var+") {
      std::getline(file, code);
      tmp_arg=code;
      std::getline(file, code);
      out=out+tmp_arg+"="+tmp_arg+"+"+code+"_;\n";
    }
    else if (code=="var-") {
      std::getline(file, code);
      tmp_arg=code;
      std::getline(file, code);
      out=out+tmp_arg+"="+tmp_arg+"-"+code+"_;\n";
    }
    else if (code=="var/") {
      std::getline(file, code);
      tmp_arg=code;
      std::getline(file, code);
      out=out+tmp_arg+"="+tmp_arg+"/"+code+"_;\n";
    }
    else if (code=="var*") {
      std::getline(file, code);
      tmp_arg=code;
      std::getline(file, code);
      out=out+tmp_arg+"="+tmp_arg+"*"+code+";\n";
    }
    else if (code=="var^") {
      std::getline(file, code);
      tmp_arg=code;
      std::getline(file, code);
      out=out+tmp_arg+"="+tmp_arg+"^"+code+";\n";
    }
    else if (code=="openr") {
      std::getline(file, code);
      tmp_arg=code;
      std::getline(file, code);
      files=1;
      out=out+"std::ifstream "+code+"(\""+tmp_arg+"\");\n";
    }
    else if (code=="openw") {
      std::getline(file, code);
      tmp_arg=code;
      std::getline(file, code);
      files=1;
      out=out+"std::ofstream "+code+"(\""+tmp_arg+"\");\n";
    }
    else if (code=="fclose") {
      std::getline(file, code);
      files=1;
      out=out+code+".close();\n";
    }
    else if (code=="readline") {
      std::getline(file, code);
      tmp_arg=code;
      std::getline(file, code);
      files=1;
      string_=1;
      out=out+"std::getline("+tmp_arg+", "+code+");\n";
    }
    else if (code=="write") {
      std::getline(file, code);
      tmp_arg=code;
      std::getline(file, code);
      files=1;
      out=out+tmp_arg+" << "+code+";\n";
    }
    else if (code=="if") {
      std::getline(file, code);
      out=out+"if ("+code+") {\n";
    }
    else if (code=="while") {
      std::getline(file, code);
      out=out+"while ("+code+") {\n";
    }
    else if (code=="elif") {
      std::getline(file, code);
      out=out+"else if ("+code+") {\n";
    }
  }
  out=out+"}";
  if (print==1) {
    out="#include <iostream>\n"+out;
  }
  if (string_==1) {
    out="#include <string>\n"+out;
  }
  if (files==1) {
    out="#include <fstream>\n"+out;
  }
  file.close();
  std::cout << "OUT CPP > ";
  std::cin >> filename;
  std::ofstream fileout(filename);
  fileout << out;
  fileout.close();
}
